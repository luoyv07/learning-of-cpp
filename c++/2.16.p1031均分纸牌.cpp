#include <iostream>
using namespace std;
int main() {
	int n, a[101];
	cin >> n;
	int all = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		all += a[i];
	}
	int ave = all / n, ans = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] == ave)continue;
		ans++;
		a[i + 1] = a[i] + a[i + 1] - ave;
	}
	cout << ans;
}