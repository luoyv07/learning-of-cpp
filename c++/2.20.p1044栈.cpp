#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int f[20][20];
	for (int i = 0; i <= n; i++) {
		f[i][0] = 1;
	}
	for (int j = 1; j <= n; j++) {
		for (int i = 0; i <= n; i++) {
			if (i == 0) {
				f[i][j] = f[i + 1][j - 1];
			}
			if (i != 0) {
				f[i][j] = f[i - 1][j] + f[i + 1][j - 1];
			}
		}
	}
	cout << f[0][n];
}