#include <iostream>
using namespace std;
void f_array(int *f_arr, int a1, int a2,int n) {
	f_arr[1] = a1;
	f_arr[2] = a2;
	for (int i = 3; i <= n; i++) {
		f_arr[i] = f_arr[i - 1] + f_arr[i - 2];
	}
}
inline int lefton(int orin, int leavebus, int enterbus) {
	return orin - leavebus + enterbus;
}
int main() {
	int a, n, m, x;
	cin >> a >> n >> m >> x;
	if (n <= 3) {
		cout << a;
		return 0;
	}
	int enterbus[21], leavebus[21], leftonbus[21];
	leftonbus[2] = leftonbus[1] = a;
	int p=-1;
	for (int u = 0; u <= 20; u++) {//傻逼吧，先上车，在本站就立刻下车是什么操作
		f_array(enterbus, a, u, n - 1);
		for (int i = 3; i <= n - 1; i++) {
			leavebus[i] = enterbus[i - 1];
			leftonbus[i] = lefton(leftonbus[i - 1], leavebus[i], enterbus[i]);
		}
		if (leftonbus[n - 1] == m) {
			p = u;
			break;
		}
	}
	cout << p << endl;
	f_array(enterbus, a, p, n - 1);
	for (int i = 3; i <= n - 1; i++) {
		leavebus[i] = enterbus[i - 1];
		leftonbus[i] = lefton(leftonbus[i - 1], leavebus[i], enterbus[i]);
	}
	if (x == n) {
		cout << 0;
		return 0;
	}
	cout << leftonbus[x];
}