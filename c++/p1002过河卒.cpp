#include<iostream>
using namespace std;
int counter=0;
int hx, hy, dx, dy;
int hmx[9] = { 1,1,-1,-1,2,2,-2,-2,0 };
int hmy[9] = { 2,-2,2,-2,1,-1,1,-1,0 };
bool check(int x1, int y1) {
	for (int a = 0; a < 9; a++) {
		if (x1 + hmx[a] == hx && y1 + hmy[a] == hy) {
			return 1;
		}
	}
	return 0;
}//检测是否为马可走位置
void move(int x1, int y1) {
	if (x1 == dx && y1 == dy) {
		counter++;
		return;
	}
	if (x1 > dx || y1 > dy) {
		return;
	}
	bool isControlled = check(x1, y1);
	if (isControlled == 1) {
		return;
	}
	move(x1 + 1, y1);
	move(x1, y1 + 1);
	return;
}//递归的移动
int main(){
	cin >> dx >> dy >> hx >> hy;
	move(0, 0);
	cout << counter;
}