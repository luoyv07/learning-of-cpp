#include <iostream>;
using namespace std;
int main() {
	int n, m, k[5001], s[5001];
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> k[i] >> s[i];
	}
	int temp1, temp2;
	for (int i = 1; i < n; i++) {
		for (int j = i; j <= n; j++) {
			if (s[i] < s[j]) {
				temp1 = k[i];
				temp2 = s[i];
				k[i] = k[j];
				s[i] = s[j];
				k[j] = temp1;
				s[j] = temp2;
			}
			else if (s[i] == s[j] && k[i] > k[j]) {
				temp1 = k[i];
				temp2 = s[i];
				k[i] = k[j];
				s[i] = s[j];
				k[j] = temp1;
				s[j] = temp2;
			}
		}
	}
	int ans = 1.5 * m;
	if (ans >= n) {
		cout << s[n] << " " << n << endl;
		for (int i = 1; i <= n; i++) {
			cout << k[i] << " " << s[i] << endl;
		}
		return 0;
	}
	int temp = s[ans];
	ans--;
	for (int i = ans + 1; s[i] == temp; i++) {
		ans++;
	}
	cout << s[ans] << " " << ans << endl;
	for (int i = 1; i <= ans; i++) {
		cout << k[i] << " " << s[i] << endl;
	}
}