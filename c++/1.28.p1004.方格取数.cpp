#include <iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int board[9][9] = { 0 };
int f[9][9][9][9];
int n;
int move(int x1, int y1, int x2, int y2) {
	if (x1 == n - 1 && y1 == n - 1 && x2 == n - 1 && y2 == n - 1) {
		return 0;
	}
	if (f[x1][y1][x2][y2] != -1) {
		return f[x1][y1][x2][y2];
	}
	int M = 0;
	if (x1 + 1 <= n - 1 && x2 + 1 <= n - 1) {
		M = max(M, move(x1 + 1, y1, x2 + 1, y2) + board[x1 + 1][y1] + board[x2 + 1][y2] - (x1 + 1 == x2 + 1 && y1 == y2) * board[x1 + 1][y1]);
	}
	if (x1 + 1 <= n - 1 && y2 + 1 <= n - 1) {
		M = max(M, move(x1 + 1, y1, x2, y2 + 1) + board[x1 + 1][y1] + board[x2][y2 + 1] - (x1 + 1 == x2 && y1 == y2 + 1) * board[x1 + 1][y1]);
	}
	if (y1 + 1 <= n - 1 && y2 + 1 <= n - 1) {
		M = max(M, move(x1, y1 + 1, x2, y2 + 1) + board[x1][y1 + 1] + board[x2][y2 + 1] - (x1 == x2 && y1 + 1 == y2 + 1) * board[x1][y1 + 1]);
	}
	if (y1 + 1 <= n - 1 && x2 + 1 <= n - 1) {
		M = max(M, move(x1, y1 + 1, x2 + 1, y2) + board[x1][y1 + 1] + board[x2 + 1][y2] - (x1 == x2 + 1 && y1 + 1 == y2) * board[x1][y1 + 1]);
	}
	f[x1][y1][x2][y2] = M;
	return M;
}
int main() {
	cin >> n;
	int a, b, c;
	memset(f, -1, sizeof(f));
	do {
		cin >> a >> b >> c;
		board[a - 1][b - 1] = c;
	} while (!(a == 0 && b == 0 && c == 0));
	cout << move(0, 0, 0, 0);// +board[0][0];
	return 0;
}