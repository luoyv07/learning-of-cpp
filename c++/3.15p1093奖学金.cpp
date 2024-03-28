#include <iostream>
using namespace std;
class stu {
public:
	int id;
	int tal;
	int ch;
};
int main() {
	int a, b, c;
	stu temp;
	int num;
	stu student[301];
	cin >> num;
	for (int i = 1; i <= num; i++) {
		cin >> a >> b >> c;
		student[i].id = i;
		student[i].tal = a + b + c;
		student[i].ch = a;
	}
	for (int i = 1; i <= num - 1; i++) {
		for (int j = i + 1; j <= num; j++) {
			if (student[i].tal < student[j].tal) {
				temp = student[i];
				student[i] = student[j];
				student[j] = temp;
			}
			else if (student[i].tal == student[j].tal) {
				if (student[i].ch < student[j].ch) {
					temp = student[i];
					student[i] = student[j];
					student[j] = temp;
				}
				else if (student[i].ch == student[j].ch) {
					if (student[i].id >= student[j].id) {
						temp = student[i];
						student[i] = student[j];
						student[j] = temp;
					}
				}
				
			}
		}
	}
	for (int i = 1; i <= 5; i++) {
		cout << student[i].id << " " << student[i].tal << endl;
	}
}