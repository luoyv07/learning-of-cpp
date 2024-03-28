#include <iostream>
using namespace std;
class peanut {
public:
	int m = 0, n = 0, p = 0, t = 0;
};
int main() {
	int n, m, k;
	cin >> m >> n >> k;
	peanut p[500];
	int counter = 0, temp;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> temp;
			if (temp != 0) {
				counter++;
				p[counter].m = i;
				p[counter].n = j;
				p[counter].p = temp;
			}
		}
	}
	if (counter == 0) {
		cout << 0;
		return 0;
	}
	for (int i = 1; i <= counter - 1; i++) {
		for (int j = i + 1; j <= counter; j++) {
			if (p[j].p > p[i].p) {
				swap(p[j], p[i]);
			}
		}
	}
	int nowm = 0, nown = p[1].n, ans = 0, u = 0;
	for (int i = 1; i <= k; i++) {
		u = p[i].m;
		if (i == 1) p[i].t = p[i].m + 1; 
		else   p[i].t = p[i - 1].t + abs(p[i].m - p[i - 1].m) + abs(p[i].n - p[i - 1].n) + 1;
		if (p[i].t + u <= k) {
			ans += p[i].p;
		}
		else {
			cout << ans;
			return 0;
		}
	}
	cout << p;
}