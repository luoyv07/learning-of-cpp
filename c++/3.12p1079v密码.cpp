#include <iostream>
using namespace std;
int main() {
	string k, c;
	cin >> k >> c;
	int lk = k.length(), lc = c.length();
	int ik[100];
	for (int i = 0; i <= lk - 1; i++) {
		if (k[i] >= 'A' && k[i] <= 'Z') {
			ik[i] = k[i] - 'A';
		}
		else {
			ik[i] = k[i] - 'a';
		}
	}
	char temp;
	for (int i = 0; i <= lc - 1; i++) {
		if (c[i] >= 'A' && c[i] <= 'Z') {
			if (c[i] - 'A' - ik[i % lk] >= 0) {
				temp = c[i] - ik[i % lk];
				cout << temp;
			}
			else {
				temp = c[i] - ik[i % lk] + 26;
				cout << temp;
			}
		}
		else {
			if (c[i] - 'a' - ik[i % lk] >= 0) {
				temp = c[i] - ik[i % lk];
				cout << temp;
			}
			else {
				temp = c[i] - ik[i % lk] + 26;
				cout << temp;
			}
		}
	}
}