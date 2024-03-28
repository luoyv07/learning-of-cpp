#include <iostream>
using namespace std;
class student {
public:
	string name;
	int score;
};
class teacher {
public:
	string name;
	student stu[5];
};
void mark(teacher(&tea)[3]) {
	for (int n = 0; n < 3; n++) {
		for (int m = 0; m < 5; m++) {
			tea[n].stu[m].score = rand() % 101;
		}
	}
}
int main() {
	teacher tea[3];
	mark(tea);
	for (int n = 0; n < 3; n++) {
		cout << n+1 << "号老师的学生:" << endl;
		for (int m = 0; m < 5; m++) {
			cout << "学生" << m+1 << ":" << endl;
			cout<<tea[n].stu[m].score <<endl;
		}
	}
}