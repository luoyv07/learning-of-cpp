#include <iostream>
#include <cmath>
using namespace std;
char input[62525];
void f(int n) {
	int a = 0, b = 0;
	for (int i = 1; input[i] != 'E'; i++) {
		if (input[i] == 'W')a++;
		if (input[i] == 'L')b++;
		if ((a >= n || b >= n)&&abs(a-b)>=2) {
			cout << a << ":" << b << endl;
			a = b = 0;
		}
	}
	cout << a << ":" << b << endl;
}
int main() {
	char temp = 'none';
	for (int i = 1; temp != 'E'; i++) {
		cin >> temp;
		input[i] = temp;
	}
	f(11);
	cout << endl;
	f(21);
}