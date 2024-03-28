#include <iostream>
using namespace std;
class RationalNumber {
public:
	int denominator;
	int numerator;

	RationalNumber(int a, int b) :numerator(a), denominator(b) {
		checkZero();
		check();
	}

	void checkZero() {
		int a, b;
		if (denominator == 0) {
			cout << "0 can not be a denominator, please try again." << endl;
			cin >> a >> b;
			numerator = a;
			denominator = b;
			checkZero();
		}
	}

	int gcd(int a, int b) {
		return b == 0 ? a : gcd(b, a % b);
	}

	void check() {
		int g = gcd(numerator, denominator);
		numerator /= g;
		denominator /= g;
		if (denominator < 0) {
			numerator = -numerator;
			denominator = -denominator;
		}
	}

	RationalNumber operator+(const RationalNumber& other) {
		int newNumerator = numerator * other.denominator + other.numerator * denominator;
		int newDenominator = denominator * other.denominator;
		return RationalNumber(newNumerator, newDenominator);
	}

	RationalNumber operator-(const RationalNumber& other) {
		int newNumerator = numerator * other.denominator - other.numerator * denominator;
		int newDenominator = denominator * other.denominator;
		return RationalNumber(newNumerator, newDenominator);
	}

	RationalNumber operator*(const RationalNumber& other) {
		int newNumerator = numerator * other.numerator;
		int newDenominator = denominator * other.denominator;
		return RationalNumber(newNumerator, newDenominator);
	}

	RationalNumber operator/(const RationalNumber& other) {
		int newNumerator = numerator * other.denominator;
		int newDenominator = denominator * other.numerator;
		return RationalNumber(newNumerator, newDenominator);
	}

	bool operator>(const RationalNumber& other) {
		return numerator * other.denominator > other.numerator * denominator;
	}

	bool operator<(const RationalNumber& other) {
		return numerator * other.denominator < other.numerator * denominator;
	}

	bool operator>=(const RationalNumber& other) {
		return numerator * other.denominator >= other.numerator * denominator;
	}

	bool operator<=(const RationalNumber& other) {
		return numerator * other.denominator <= other.numerator * denominator;
	}

	bool operator==(const RationalNumber& other) {
		return numerator * other.denominator == other.numerator * denominator;
	}

	bool operator!=(const RationalNumber& other) {
		return numerator * other.denominator != other.numerator * denominator;
	}


};

int main() {
	RationalNumber r1(1, 2);
	RationalNumber r2(3, 4);

	cout << "Testing arithmetic operators:" << endl;
	RationalNumber sum = r1 + r2;
	cout << "1/2 + 3/4 = " << sum.numerator << "/" << sum.denominator << endl;

	RationalNumber difference = r1 - r2;
	cout << "1/2 - 3/4 = " << difference.numerator << "/" << difference.denominator << endl;

	RationalNumber product = r1 * r2;
	cout << "1/2 * 3/4 = " << product.numerator << "/" << product.denominator << endl;

	RationalNumber quotient = r1 / r2;
	cout << "1/2 / 3/4 = " << quotient.numerator << "/" << quotient.denominator << endl;

	cout << "\nTesting comparison operators:" << endl;
	cout << "1/2 > 3/4: " << (r1 > r2 ? "true" : "false") << endl;
	cout << "1/2 < 3/4: " << (r1 < r2 ? "true" : "false") << endl;
	cout << "1/2 >= 3/4: " << (r1 >= r2 ? "true" : "false") << endl;
	cout << "1/2 <= 3/4: " << (r1 <= r2 ? "true" : "false") << endl;
	cout << "1/2 == 3/4: " << (r1 == r2 ? "true" : "false") << endl;
	cout << "1/2 != 3/4: " << (r1 != r2 ? "true" : "false") << endl;

	return 0;
}