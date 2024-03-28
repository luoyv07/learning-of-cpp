#include <iostream>
using namespace std;
int main() {
	string code, ori, request;
	cin >> code >> ori >> request;
	char box[26] = { '0' };
	for (int i = 0; i <= 25; i++) {
		box[i] = '0';
	}
	int l = code.length();
	for (int i = 0; i < l; i++) {
		if (box[code[i] - 'A'] == '0') {
			box[code[i] - 'A'] = ori[i];
		}
		else if (box[code[i] - 'A'] != ori[i]) {
			cout << "Failed";
			return 0;
		}
	}
	for (int i = 0; i <= 25; i++) {
		if (box[i] == '0') {
			cout << "Failed";
			return 0;
		}
		for (int j = i + 1; j <= 25; j++) {
			if (box[i] == box[j]) {
				cout << "Failed";
				return 0;
			}
		}
	}
	for (int i = 0; i <= request.length(); i++) {
		cout << box[request[i] - 'A'];
	}
}