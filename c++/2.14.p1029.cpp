#include <iostream>
using namespace std;
int main() {
	int x, y;
	cin >> x >> y;
	if (y % x != 0) {
		cout << 0;
		return 0;
	}
	int q = y / x;
	int count = 0;
	int factors = 2;
	for (; q > 1; factors++) {
		if (q % factors == 0) {
			count++;
			while (q % factors == 0) {
				q /= factors;
			}
		}
	}
	cout << (1 << count);
}