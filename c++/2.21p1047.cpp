#include <iostream>
using namespace std;
int tree[10001] = { 0 };
void set(int sta, int end) {
	for (int i = sta; i <= end; i++) {
		tree[i] = 0;
	}
}
int main() {
	int l, m;
	cin >> l >> m;
	for (int i = 0; i <= l; i++) {
		tree[i] = 1;
	}
	int sta, end;
	for (int i = 1; i <= m; i++) {
		cin >> sta >> end;
		set(sta, end);
	}
	int ans = 0;
	for (int i = 0; i <= l; i++) {
		ans += tree[i];
	}
	cout << ans;
}