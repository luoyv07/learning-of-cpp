#include <iostream>
using namespace std;
int n, k, x[21], ans = 0;
bool isprime(int a) {
	for (int i = 2; i * i <= a; i++) {
		if (a % i == 0) {
			return 0;
		}
	}
	return 1;
}
void enumerate(int now, int sum, int pos) {
	if (now == k) {
		if (isprime(sum)) {
			ans++;
		}
		return;
	}
	for (int i = pos; i <= n; i++) {
		enumerate(now + 1, sum + x[i], i + 1);
	}
	return;
}
int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
	}
	enumerate(0, 0, 1);
	cout << ans;
}