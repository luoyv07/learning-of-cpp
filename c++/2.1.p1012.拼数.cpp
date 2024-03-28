#include <iostream>
#include <algorithm>
using namespace std;
bool com(string a,string b) {
	return (a + b > b + a);
}
int main() {
	int n;
	cin >> n;
	string a[20];
	for (int i = 0; i <= n - 1; i++) {
		cin >> a[i];
	}
	sort(a, a + n, com);
	for (int i = 0; i <= n - 1; i++) {
		cout << a[i];
	}
	return 0;
}