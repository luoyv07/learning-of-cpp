#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int position[5000], n, l;
	cin >> l >> n;
	if (n == 0) {
		cout << "0 0";
		return 0;
	}
	for (int i = 0; i < n; i++) {
		cin >> position[i];
	}
	int medium = l / 2 + 1;
	int close_medium = l;
	int mostr = medium;
	int mostl = l / 2;
	for (int i = 0; i < n; i++) {
		if (abs(position[i] - medium) < abs(close_medium - medium)) {
			close_medium = position[i];
		}
		if (position[i] < mostl) {
			mostl = position[i];
		}
		if (position[i] > mostr) {
			mostr = position[i];
		}
	}
	int least_time, most_time;
	if (close_medium < medium) {
		least_time = close_medium;
	}
	else {
		least_time = l + 1 - close_medium;
	}
	if (mostr > l + 1 - mostl) {
		most_time = mostr;
	}
	else {
		most_time = l + 1 - mostl;
	}
	cout << least_time << " " << most_time;
}