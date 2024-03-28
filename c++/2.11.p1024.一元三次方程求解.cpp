#include <iostream>
#include <iomanip>
using namespace std;
double a, b, c, d;
inline double cal(double x) {
	return a * x * x * x + b * x * x + c * x + d;
}
double find(double x1, double x2) {
	double x, y, z;
	while(x2-x1>=0.01){
		x = cal(x1);
		y = cal((x1 + x2) / 2);
		z = cal(x2);
		if (y == 0) {
			return (x1 + x2) / 2;
		}
		else if (x * y < 0) {
			x2 = (x1 + x2) / 2;
		}
		else if (y * z < 0) {
			x1 = (x1 + x2) / 2;
		}
	}
	return (x1 + x2) / 2;
}
int main() {
	cin >> a >> b >> c >> d;
	double sol[201], x[6], ans[3];
	int temp = 1;
	sol[0] = -100;
	for (int i = 1; i <= 200; i++) {
		sol[i] = sol[i - 1] + 1;
	}
	for (int i = 0; i < 200; i++) {
		if (cal(sol[i]) == 0) {
			x[2 * (temp - 1)] = sol[i];
			x[2 * (temp-1)+1] = sol[i];
			temp++;
		}
		else if (cal(sol[i]) * cal(sol[i + 1]) < 0) {
			x[2 * (temp - 1)] = sol[i];
			x[2 * (temp-1)+1] = sol[i+1];
			temp++;
		}
		if (temp > 3) {
			break;
		}
	}
	ans[0] = find(x[0], x[1]);
	ans[1] = find(x[2], x[3]);
	ans[2] = find(x[4], x[5]);
	cout << fixed << setprecision(2) << ans[0] << " " << ans[1] << " " << ans[2];
}