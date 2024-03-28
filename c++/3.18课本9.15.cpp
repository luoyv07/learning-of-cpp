#include <iostream>
using namespace std;
class TicTacToe {
private:
	int board[3][3];
public:
	TicTacToe() {
		for (int i = 0; i <= 2; i++) {
			for (int j = 0; j <= 2; j++) {
				board[i][j] = 0;
			}
		}
	}
	bool check() {
		for (int i = 0; i <= 2; i++) {
			if (board[i][0] == board[i][1] && board[i][2] == board[i][0] && board[i][0] != 0) {
				return 1;
			}
			else if (board[0][i] == board[1][i] && board[2][i] == board[0][i] && board[0][i] != 0) {
				return 1;
			}
		}
		if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != 0) {
			return 1;
		}
		if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[2][0] != 0) {
			return 1;
		}
		return 0;
	}
	bool move( int n) {
		int a, b;
		flag:
		cin >> a >> b;
		if (a < 0 || a>2 || b < 0 || b>2) {
			cout << "非法输入，请新输入" << endl;
			goto flag;
		}
		if (board[a][b] != 0) {
			cout << "非法输入，请新输入" << endl;
			goto flag;
		}
		board[a][b] = n;
		if (check()) {
			cout << n << "号选手胜！！！！";
			return 0;
		}
		return 1;
	}
};
int main() {
	TicTacToe T;
	int a, b;
	int counter = 0;
	bool temp;
	do {
		cout << "请" << counter % 2 + 1 << "号选手落子" << endl;
		temp = T.move(counter % 2 + 1);
		counter++;
	} while (temp);
}