#include <iostream>;
using namespace std;
class floor1 {
public:
	int a, b, c, d;
};
int main() {
	int n=0;
	cin >> n;
	floor1 floors[10000];
	for (int q = 1; q <= n; q++) {
		cin >> floors[q].a >> floors[q].b >> floors[q].c >> floors[q].d;
	}
	int x, y;
	cin >> x >> y;
	for (int i = n; i > 0; i--) {
		if (x >= floors[i].a && x <= floors[i].a + floors[i].c && y >= floors[i].b && y <= floors[i].b + floors[i].d) {
			cout << i;
			return 0;
		}
	}
	cout << -1;
	return 0;
}