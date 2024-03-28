#include <iostream>
using namespace std;
int main() {
	int n, ans = 0, h[11];
	for (int i = 1; i <= 10; i++) {
		cin >> h[i];
	}
	cin >> n;
	for (int i = 1; i <= 10; i++) {
		if (n + 30 >= h[i]) {
			ans++;
		}
	}
	cout << ans;

}