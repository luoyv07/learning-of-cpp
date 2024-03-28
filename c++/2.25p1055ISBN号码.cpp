#include <iostream>
using namespace std;
int main() {
	int isbn[13];
	string str;
	cin >> str;
	for (int i = 0; i <= 11; i++) {
		isbn[i + 1] = str[i] - 48;
	}
	int iden = str[12] - 48;
	int temp = isbn[1] + 2 * isbn[3] + 3 * isbn[4] +4*isbn[5]+ 5 * isbn[7] + 6 * isbn[8] + 7 * isbn[9] + 8 * isbn[10] + 9 * isbn[11];
	int ans = temp % 11;
	if (ans == iden || (ans == 10 && iden == 40)) {
		cout << "Right";
	}
	else {
	    cout << isbn[1] << "-" << isbn[3] << isbn[4] << isbn[5] << "-";
	    for (int i = 7; i <= 11; i++) {
			cout << isbn[i];
		}
		cout << "-";
		if (ans < 10) {
			cout << ans;
		}
		else {
			cout << "X";
		}
	}
}