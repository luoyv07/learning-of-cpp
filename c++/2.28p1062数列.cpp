#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int k, n, counter = 1, mark;
	cin >> k >> n;
	long long ans[1001];
	ans[1] = 1;
	for (int i = 1; i <= n; i++) {
		counter++;
		ans[counter] = pow(k, i);
		if (counter == n) {
			cout << ans[counter];
			return 0;
		}
		for (int j = 1, temp = counter - 1; j <= temp; j++) {
			counter++;
			ans[counter] = ans[temp + 1] + ans[j];
			if (counter == n) {
				cout << ans[counter];
				return 0;
			}
		}
	}
}