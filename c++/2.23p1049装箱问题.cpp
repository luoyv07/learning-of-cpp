#include <iostream>
using namespace std;
int main() {
	int V, n;
	cin >> V >> n;
	int v[31];
	int left[20001] = { 0 };
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = V; j >=v[i]; j--) {
			left[j] = max(left[j - v[i]] + v[i], left[j]);
		}
	}
	cout << V - left[V];
}