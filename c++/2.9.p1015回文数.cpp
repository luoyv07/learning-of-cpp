#include <iostream>
using namespace std;
int n, ori[300], tur[300], l, ans = 0;
string m;
void trans() {
	for (int i = 0; i <= m.length()-1; i++) {
		if (m[i] >= '0' && m[i] <= '9') {
			ori[i] = m[i] - '0';
		}
		else {
			ori[i] = m[i] - 'A' + 10;
		}
	}
}
void turn() {
	for (int i = 0; i <= l - 1; i++) {
		tur[l - 1 - i] = ori[i];
	}
}
bool check(int a[]) {
	for (int i = 0; i <= l / 2; i++) {
		if (a[i] != a[l - 1 - i]) {
			return 0;
		}
	}
	return 1;
}
void add1() {
	for (int i = 0; i <= l - 1; i++) {
		ori[i] += tur[i];
		ori[i + 1] += ori[i] / n;
		ori[i] %= n;
	}
	if (ori[l] > 0) {
		l++;
	}
}
int main() {
	cin >> n >> m;
	l = m.length();
	trans();
	turn();
	while (!check(ori)) {
		ans++;
		add1();
		turn();
		if (ans >= 30) {
			cout << "Impossible!";
			return 0;
		}
	}
	cout<<"STEP="<<ans;
}