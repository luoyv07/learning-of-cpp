#include <iostream>
using namespace std;
class stu {
public:
	string name;
	int term_score;
	int class_score;
	char iscadre;
	char iswest;
	int paper;
	int f() {
		int reward = 0;
		if (term_score > 80 && paper >= 1) {
			reward += 8000;
		}
		if (term_score > 85 && class_score > 80) {
			reward += 4000;
		}
		if (term_score > 90) {
			reward += 2000;
		}
		if (term_score > 85 && iswest == 'Y') {
			reward += 1000;
		}
		if (class_score > 80 && iscadre == 'Y') {
			reward += 850;
		}
		return reward;
	}
};
int main() {
	int n;
	stu student[101];
	int maxreward = 0;
	int maxstu;
	int temp, all = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> student[i].name >> student[i].term_score >> student[i].class_score >> student[i].iscadre >> student[i].iswest >> student[i].paper;
		temp = student[i].f();
		if (temp > maxreward) {
			maxreward = temp;
			maxstu = i;
		}
		all += temp;
	}
	cout << student[maxstu].name << endl;
	cout << student[maxstu].f() << endl;
	cout << all;
}