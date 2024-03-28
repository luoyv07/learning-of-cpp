#include <iostream>
#include<iomanip>
#include<string>
using namespace std;
class Hero {
public:
	string name;
	int age;
	string gender;
};
void rank1(Hero(& hero)[5],int len) {
	Hero temp;
	for (int a = 0; a < len-1; a++) {
		for (int b = 0; b < len-a-1; b++) {
			if (hero[b].age < hero[b + 1].age) {
				temp = hero[b];
				hero[b] = hero[b + 1];
				hero[b + 1] = temp;
			}
		}
	}
}
int main() {
	Hero hero[5] = { {"张飞",21,"男"},{"刘备",25,"男"},{"貂蝉",21,"女"},{"司马徽",85,"男"},{"孙鲁育",16,"女"} };
	int len = sizeof(hero)/sizeof(hero[0]);
	rank1 (hero,len);
	for (int a = 0; a < 5; a++) {
		cout <<left<< setw(10) << hero[a].name << setw(5) << hero[a].age << setw(5) << hero[a].gender << endl;
	}
}