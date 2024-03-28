#include <iostream>
#include<array>
#include<vector>
using namespace std;
void inputVector(vector<int>& a) {
	int n, m, p = 0;
	for (n = 0; n < 15; n++) {
		m = rand() % 100;
		for (auto item : a) {
			if (item == m) {
				p = 1;
			}
		}
		if (p == 1) {
			n--;
			continue;
		}
		a.push_back(m);
	}
}
void displayVector(const vector <int>& a) {
	for (auto item : a) {
		cout << item << endl;
	}
}
int main() {
	srand((unsigned)time(NULL));
	vector<int>a;
	inputVector(a);
	displayVector(a);
}