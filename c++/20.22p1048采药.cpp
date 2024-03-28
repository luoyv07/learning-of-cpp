#include <iostream>
#include <algorithm>
using namespace std;
int T, M, t[101], m[101];
int value[101][1001];
int main() {
	cin >> T >> M;
	for (int i = 1; i <= M; i++) {
		cin >> t[i] >> m[i];
	}
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= T; j++) {
			if (j >= t[i]) {
				value[i][j] = max(value[i - 1][j - t[i]] + m[i], value[i - 1][j]);
			}
			else {
				value[i][j] = value[i - 1][j];
			}
		}
	}
	cout << value[M][T];
}