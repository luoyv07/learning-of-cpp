#include <iostream>
using namespace std;
void f(string mid,string aft) {
	if (mid.size() == 0)return;
	int n = aft.size() - 1;
	char end = aft[n];
	cout << end;
	int k = mid.find(end);
	f(mid.substr(0, k), aft.substr(0, k));
	f(mid.substr(k+1), aft.substr(k, n-k));
}
int main() {
	string mid, aft;
	cin >> mid >> aft;
	f(mid, aft);
}