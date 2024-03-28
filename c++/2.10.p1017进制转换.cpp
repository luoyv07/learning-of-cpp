#include <iostream>
using namespace std;
int n, r;
char tur[100000];
int main() {
	cin >> n >> r;
	int m = n;
	int temp;
	int i;
	for (i = 0; n != 0; i++) {
		temp = n % r;
		n /= r;
		if (temp < 0) {
			temp -= r;
			n++;
		}
		if (temp < 10) {
			tur[i] = temp + 48;
		}
		else {
			tur[i] = temp - 10 + 'A';
		}
	}
	cout << m << "=";
	for (int m=i; m >= 0; m--) {
		cout << tur[m];
	}
	cout << "(base" << r << ")";
}