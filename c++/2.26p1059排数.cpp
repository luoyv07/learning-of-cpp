#include <iostream>
using namespace std;
int main() {
	int n, ori[101], ans[101], counter = 0, check = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> ori[i];
	}
	for (int i = 1; i < n; i++) {
		check = 0;
		for (int j = i + 1; j <= n; j++) {
			if (ori[i] == ori[j]) {
				check = 1;
			}
		}
		if (check == 1) {
			continue;
		}
		counter++;
		ans[counter] = ori[i];
	}
	counter++;
	ans[counter] = ori[n];
	int temp;
	for (int i = 1; i < counter; i++) {
		for (int j = i + 1; j <= counter; j++) {
			if (ans[i] > ans[j]) {
				temp = ans[i];
				ans[i] = ans[j];
				ans[j] = temp;
			}
		}
	}
	cout << counter << endl;
	for (int i = 1; i <= counter; i++) {
		cout << ans[i] << " ";
	}
}