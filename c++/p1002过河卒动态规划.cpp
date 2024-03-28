#include<iostream>
using namespace std;
int board[21][21];
int horseMovesX[9] = { 1, 1, -1, -1, 2, 2, -2, -2, 0 };
int horseMovesY[9] = { 2, -2, 2, -2, 1, -1, 1, -1, 0 };
int hx, hy, dx, dy;
bool isControlled(int x, int y) {
	for (int i = 0; i < 9; ++i) {
		if (x + horseMovesX[i] == hx && y + horseMovesY[i] == hy) {
			return true;
		}
	}
	return false;
}
int main() {
	cin >> dx >> dy >> hx >> hy;
	memset(board, 0, sizeof(board));
	board[0][0] = 1;
	for (int a = 0; a < 21; a++) {
		for (int b = 0; b < 21; b++) {
			if (isControlled(a, b) || (a == hx && b == hy)) continue;
			if (a > 0) board[a][b] += board[a - 1][b];
			if (b > 0) board[a][b] += board[a][b - 1];

		}
	}
	cout << board[dx][dy];
}