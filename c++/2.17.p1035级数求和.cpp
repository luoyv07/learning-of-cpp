#include <iostream>
using namespace std;
int main() {
	int k;
	cin >> k;
	double s = 0;
	for (double i = 1; i > 0; i++) {
		s = s + 1 / i;
		if (s > k) {
			cout << i;
			break;
		}
	}
}