#include <iostream>
#include <algorithm>
using namespace std;

class term {
public:
    int coefficient;
    int exponent;
};

class Polynomial {
private:
    term* terms;
    int capacity;
    int numTerms;

    void ensureCapacity(int minCapacity) {
        if (capacity < minCapacity) {
            int newCapacity = max(minCapacity, 2 * capacity);
            term* newTerms = new term[newCapacity];
            for (int i = 0; i < numTerms; ++i) {
                newTerms[i] = terms[i];
            }
            delete[] terms;
            terms = newTerms;
            capacity = newCapacity;
        }
    }

public:
    Polynomial(int cap) : capacity(cap), numTerms(0) {
        terms = new term[capacity];
    }

    Polynomial(const Polynomial& other) : capacity(other.capacity), numTerms(other.numTerms) {
        terms = new term[capacity];
        for (int i = 0; i < numTerms; ++i) {
            terms[i] = other.terms[i];
        }
    }

    ~Polynomial() {
        delete[] terms;
    }

    Polynomial& operator=(const Polynomial& other) {
        if (this != &other) {
            delete[] terms;
            capacity = other.capacity;
            numTerms = other.numTerms;
            terms = new term[capacity];
            for (int i = 0; i < numTerms; ++i) {
                terms[i] = other.terms[i];
            }
        }
        return *this;
    }

    void setTerm(int index, int coefficient, int exponent) {
        if (index >= 0 && index < capacity) {
            terms[index].coefficient = coefficient;
            terms[index].exponent = exponent;
            if (index >= numTerms) {
                numTerms = index + 1;
            }
        }
    }

    term getTerm(int index) const {
        if (index >= 0 && index < numTerms) {
            return terms[index];
        }
        else {
            return { 0, 0 };
        }
    }

    void print() const {
        for (int i = 0; i < numTerms; ++i) {
            cout << terms[i].coefficient << "x^" << terms[i].exponent;
            if (i < numTerms - 1) {
                cout << " + ";
            }
        }
        cout << endl;
    }

    void combineLikeTerms() {
        sort(terms, terms + numTerms, [](const term& a, const term& b) {
            return a.exponent > b.exponent;
            });

        int i = 0;
        for (int j = 1; j < numTerms; ++j) {
            if (terms[i].exponent == terms[j].exponent) {
                terms[i].coefficient += terms[j].coefficient;
            }
            else {
                ++i;
                if (i != j) {
                    terms[i] = terms[j];
                }
            }
        }
        numTerms = i + 1;
    }

    Polynomial& operator+=(const Polynomial& other) {
        for (int i = 0; i < other.numTerms; ++i) {
            bool found = false;
            for (int j = 0; j < numTerms; ++j) {
                if (terms[j].exponent == other.terms[i].exponent) {
                    terms[j].coefficient += other.terms[i].coefficient;
                    found = true;
                    break;
                }
            }
            if (!found) {
                ensureCapacity(numTerms + 1);
                terms[numTerms++] = other.terms[i];
            }
        }
        combineLikeTerms();
        return *this;
    }

    Polynomial operator+(const Polynomial& other) const {
        Polynomial result(*this);
        result += other;
        return result;
    }

    Polynomial& operator-=(const Polynomial& other) {
        for (int i = 0; i < other.numTerms; ++i) {
            bool found = false;
            for (int j = 0; j < numTerms; ++j) {
                if (terms[j].exponent == other.terms[i].exponent) {
                    terms[j].coefficient -= other.terms[i].coefficient;
                    found = true;
                    break;
                }
            }
            if (!found) {
                ensureCapacity(numTerms + 1);
                terms[numTerms].coefficient = -other.terms[i].coefficient;
                terms[numTerms++].exponent = other.terms[i].exponent;
            }
        }
        combineLikeTerms();
        return *this;
    }

    Polynomial operator-(const Polynomial& other) const {
        Polynomial result(*this);
        result -= other;
        return result;
    }

    Polynomial& operator*=(const Polynomial& other) {
        Polynomial result(capacity + other.capacity);
        for (int i = 0; i < numTerms; ++i) {
            for (int j = 0; j < other.numTerms; ++j) {
                int newCoeff = terms[i].coefficient * other.terms[j].coefficient;
                int newExp = terms[i].exponent + other.terms[j].exponent;
                bool found = false;
                for (int k = 0; k < result.numTerms; ++k) {
                    if (result.terms[k].exponent == newExp) {
                        result.terms[k].coefficient += newCoeff;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    result.ensureCapacity(result.numTerms + 1);
                    result.terms[result.numTerms].coefficient = newCoeff;
                    result.terms[result.numTerms++].exponent = newExp;
                }
            }
        }
        result.combineLikeTerms();
        *this = result;
        return *this;
    }

    Polynomial operator*(const Polynomial& other) const {
        Polynomial result(*this);
        result *= other;
        return result;
    }
};

int main() {
    Polynomial p1(5);
    p1.setTerm(0, 1, 2); // x^2
    p1.setTerm(1, 3, 1); // 3x
    p1.setTerm(2, 2, 0); // 2

    Polynomial p2(3);
    p2.setTerm(0, 2, 1); // 2x
    p2.setTerm(1, 1, 0); // 1

    Polynomial p3 = p1 + p2;
    cout << "p1 + p2 = ";
    p3.print();

    Polynomial p4 = p1 - p2;
    cout << "p1 - p2 = ";
    p4.print();

    Polynomial p5 = p1 * p2;
    cout << "p1 * p2 = ";
    p5.print();

    return 0;
}
