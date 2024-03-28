#include <iostream>
using namespace std;
int main() {
	int n, x[102] = { 0 };
	cin >> n;
	for (int i = 1; i <= n + 1; i++) {
		cin >> x[i];
	}
	for (int i = 1; i <= n + 1; i++) {
		if (x[i]) {
			if (i != 1 && x[i] > 0)cout << "+";
			if (x[i] < -1 || x[i]>1 || n - i + 1 == 0)cout << x[i];
			if (x[i] == -1 && n - i + 1)cout << "-";
			if (n - i + 1 > 1)cout << "x^" << n - i + 1;
			if (n - i + 1 == 1)cout << "x";
		}
	}
}