#include <iostream>
using namespace std;
int main(){
	int n, m;
	cin >> n >> m;
	int v[26], w[26];
	for (int i = 1; i <= m; i++) {
		cin >> v[i] >> w[i];
	}
	int ans[30000] = { 0 };
	for (int i = 1; i <= m; i++) {
		for (int j = n; j >= v[i]; j--) {
			ans[j] = max(ans[j - v[i]] + v[i] * w[i], ans[j]);
		}
	}
	cout << ans[n];
}