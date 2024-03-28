#include <iostream>
#include <algorithm>
using namespace std;
void Reduce(int &numerator, int &denominator) {
	for (int i = 2; i <= min(numerator, denominator); i++) {
		if (numerator % i == 0 && denominator % i == 0) {
			numerator /= i;
			denominator /= i;
			Reduce(numerator,denominator);
		}
	}
}
class Rational {
private:
	int numerator = 1;
	int denominator = 1;
public:
	
	Rational(int a, int b) :numerator(a), denominator(b) {
		Reduce(numerator,denominator);
	}
	Rational() {

	}
	friend Rational operator+(const Rational& lhs,const Rational& rhs) {
		int num = lhs.numerator * rhs.denominator + rhs.numerator * lhs.denominator;
		int denom = lhs.denominator * rhs.denominator;
		Reduce(num, denom);
		return Rational(num, denom);
	}
	friend Rational operator-(const Rational& lhs, const Rational& rhs) {
		int num = lhs.numerator * rhs.denominator - rhs.numerator * lhs.denominator;
		int denom = lhs.denominator * rhs.denominator;
		Reduce(num, denom);
		return Rational(num, denom);
	}
	friend Rational operator*(const Rational& lhs, const Rational& rhs) {
		int num = lhs.numerator * rhs.numerator;
		int denom = lhs.denominator * rhs.denominator;
		Reduce(num, denom);
		return Rational(num, denom);
	}
	friend Rational operator/(const Rational& lhs, const Rational& rhs) {
		int num = lhs.numerator * rhs.denominator;
		int denom = lhs.denominator * rhs.numerator;
		Reduce(num, denom);
		return Rational(num, denom);
	}
	void printfra() {
		cout << numerator << "/" << denominator << endl;
	}
	void printfla() {
		double a = numerator, b = denominator;
		double ans = a / b;
		cout << ans;
	}
};
int main() {
	Rational r1 = { 2,4 };
	Rational r2 = { 9,81 };
	Rational r3;
	Rational r4 = r1 + r2;
	Rational r5 = r1 - r2;
	Rational r6 = r1 * r2;
	Rational r7 = r1 / r2;
	r1.printfra();
	r2.printfra();
	r3.printfra();
	r4.printfra();
	r5.printfra();
	r6.printfra();
	r7.printfra();
	r1.printfla();
	r2.printfla();
	r3.printfla();
	r4.printfla();
	r5.printfla();
	r6.printfla();
	r7.printfla();
}