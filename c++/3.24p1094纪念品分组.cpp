#include <iostream>
using namespace std;
int main() {
	int w, n, p[30000];
	cin >> w >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}
	int temp;
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (p[i] > p[j]) {
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}
	int counter = 0;
	for (int i = 1,j = n; i <= j;) {
		if (p[i] + p[j] <= w) {
			i++;
			j--;
			counter++;
		}
		else {
			j--;
			counter++;
		}
	}
	cout << counter;
}