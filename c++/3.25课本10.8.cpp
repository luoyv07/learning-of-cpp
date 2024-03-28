#include <iostream>
using namespace std;
class Complex {
public:
	explicit Complex(double realpart = 0.0, double imaginarypart = 0.0) :real(realpart), imaginary(imaginarypart) {

	}
	Complex operator+(const Complex& operand2)const {
		return Complex(real + operand2.real, imaginary + operand2.imaginary);
	}
	Complex operator-(const Complex& operand2)const {
		return Complex(real - operand2.real, imaginary - operand2.imaginary);
	}
	Complex operator*(const Complex& operand2)const {
		return Complex(real * operand2.real - imaginary * operand2.imaginary, real * operand2.imaginary + imaginary * operand2.real);
	}
	bool operator==(const Complex& operand2) const{
		if (real == operand2.real && imaginary == operand2.imaginary) {
			return 1;
		}
		return 0;
	}
	bool operator!=(const Complex& operand2) const {
		if (real != operand2.real || imaginary != operand2.imaginary) {
			return 1;
		}
		return 0;
	}
	friend ostream& operator<<(ostream& os, const Complex& c) {
		os << c.real;
		if (c.imaginary >= 0) {
			os << "+";
		}
		os << c.imaginary << "i";
		return os;
	}
	friend istream& operator>>(istream& is, Complex& c) {
		is >> c.real >> c.imaginary;
		return is;
	}

private:
	double real;
	double imaginary;
};
void testComplex() {
	Complex c1(3, 4);
	Complex c2(1, -2);

	Complex sum = c1 + c2;
	cout << c1 << " + " << c2 << " = " << sum << endl;

	Complex difference = c1 - c2;
	cout << c1 << " - " << c2 << " = " << difference << endl;

	Complex product = c1 * c2;
	cout << c1 << " * " << c2 << " = " << product << endl;

	cout << c1 << " == " << c2 << " ? " << (c1 == c2 ? "True" : "False") << endl;

	cout << c1 << " != " << c2 << " ? " << (c1 != c2 ? "True" : "False") << endl;

	Complex c3;
	cout << "Enter a complex number in the format 'a b' (e.g., '5 6'): ";
	cin >> c3;
	cout << "You entered: " << c3 << endl;
}

int main() {
	testComplex();
	return 0;
}