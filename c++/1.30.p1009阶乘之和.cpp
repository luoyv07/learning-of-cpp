#include <iostream>
#include<array>
#include<vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector <int> factorial;
	vector <int> sum;
	factorial.push_back(1);
	sum.push_back(factorial[0]);
	for (int a = 2; a <= n; a++) {
		int carry = 0;
		for (int i = 0; i <= factorial.size()-1; i++) {
			int product = factorial[i] * a + carry;
			factorial[i] = product % 10;
			carry = product / 10;
		}
		while (carry) {
			factorial.push_back(carry % 10);
			sum.push_back(0);
			carry /= 10;
		}
		for (int i = 0; i <= sum.size() - 1; i++) {
			int temp = sum[i] + factorial[i] + carry;
			sum[i] = temp % 10;
			carry = temp / 10;
		}
		while (carry) {
			sum.push_back(carry % 10);
			carry /= 10;
		}
	}
	for (int i = sum.size() - 1; i >= 0; i--) {
		cout << sum[i];
	}
	
}
