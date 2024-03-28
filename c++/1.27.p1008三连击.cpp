#include <iostream>
using namespace std;
int main() {
	for (int a = 123,b,c; a <= 333; a++) {
		b = 2 * a;
		c = 3 * a;
		if ((a / 100 + a / 10 % 10 + a % 10 + b / 100 + b / 10 % 10 + b % 10 + c / 100 + c / 10 % 10 + c % 10 == 45) && ((a / 100) * (a / 10 % 10) * (a % 10) * (b / 100) * (b % 100 / 10) * (b % 10) * (c / 100) * (c % 100 / 10) * (c % 10) == 362880)) {
			cout << a << " " << b << " " << c << endl;	
	    }
	}
}