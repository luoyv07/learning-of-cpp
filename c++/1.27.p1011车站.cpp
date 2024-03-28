#include <iostream>
using namespace std;
bool check(int q,int a,int n,int m) {
	int enterBus[21], leftBus[21];
	enterBus[1] = a;
	leftBus[1] = 0;
	enterBus[2] = leftBus[2] = q;
	int num[21];
	num[1] = a;
	num[a] = a;
	for(int temp = 3; temp <= n-1; temp++ ) {
		enterBus[temp] = enterBus[temp - 1]+enterBus[temp - 2];
		leftBus[temp] = enterBus[temp - 1];
		num[temp] = enterBus[temp] + leftBus[temp];
	}
	if (num[n - 1] == m) {
		return 1;
	}
	else {
		return 0;
	}
}
int main() {
	int a, n, m, x;
	int enterBus[21], leftBus[21];
	cin >> a >> n >> m >> x;
	enterBus[1] = a;
	if (n < 4) {
		cout << a;
		return 0;
	}
	for (int q = 0; q <= a; q++) {
		if (check(q, a, n, m)) {
			enterBus[2] = leftBus[2] = q;
		}
	}
	int num[21];
	num[1] = a;
	num[a] = a;
	for (int temp = 3; temp <= n - 1; temp++) {
		enterBus[temp] = enterBus[temp - 1] + enterBus[temp - 2];
		leftBus[temp] = enterBus[temp - 1];
		num[temp] = enterBus[temp] + leftBus[temp];
	}
	cout << num[x];
}