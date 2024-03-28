#include <iostream>
#include<string.h>
using namespace std;
int floor1[300][300];
void change(int a, int b, int c, int d,int n) {
	for (int i = 1; i <= c; i++) {
		for (int j = 1; j <= d; j++) {
			floor1[a + i - 1][b + j - 1] = n;
		}
	}
}
int main() {
	memset(floor1, -1, sizeof(floor1));
	int n, a, b, c, d, counter=0;
	cin >> n;
	for (int q = 0; q < n; q++) {
		cin >> a >> b >> c >> d;
		counter++;
		change(a, b, c, d, counter);
	}
	cin >> a >> b;
	cout << floor1[a][b];
}