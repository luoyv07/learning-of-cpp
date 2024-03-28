#include <iostream>
#include <iomanip>
using namespace std;
class DateAndTime {
private:
	unsigned int hour;
	unsigned int minute;
	unsigned int second;
	unsigned int day;
	unsigned int month;
	unsigned int year;
public:
	explicit DateAndTime(int hour , int minute , int second , int day , int month , int year ) {
		setHour(hour);
		setMinute(minute);
		setSecond(second);
		setMonth(month); 
		setYear(year);   
		setDay(day);
	}
	void setHour(int h) {
		if (h >= 0 && h < 24) {
			hour = h;
		}
		else {
			throw invalid_argument("hour must be 0-23");
		}
	}
	void setMinute(int m) {
		if (m >= 0 && m < 60) {
			minute = m;
		}
		else {
			throw invalid_argument("minute must be 0-59");
		}
	}
	void setSecond(int s) {
		if (s >= 0 && s < 60) {
			second = s;
		}
		else {
			throw invalid_argument("second must be 0-59");
		}
	}
	void setDay(int d) {
		int maxDays;

		switch (month) {
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			maxDays = 31;
			break;
		case 4: case 6: case 9: case 11:
			maxDays = 30;
			break;
		case 2:
			if (year % 4 != 0) {
				maxDays = 28;
			}
			else {
				maxDays = 29;
			}
			break;
		default:
			throw invalid_argument("Invalid month");
		}

		if (d >= 1 && d <= maxDays) {
			day = d;
		}
		else {
			throw invalid_argument("Invalid day for the given month");
		}
	}
	void setMonth(int m) {
		if (m >= 1 && m < 12) {
			month = m;
		}
		else {
			throw invalid_argument("month must be 1-12");
		}
	}
	void setYear(int y) {
		year = y;
	}
	unsigned int getHour() const {
		return hour;
	}
	unsigned int getMinute() const {
		return minute;
	}
	unsigned int getSecond() const {
		return second;
	}
	unsigned int getDay() const {
		return day;
	}
	unsigned int getMonth() const {
		return month;
	}
	unsigned int getYear() const {
		return year;
	}
	void nextMonth() {
		if (month > 12) {
			month -= 12;
			year++;
		}
	}
	void nextDay() {
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 11) {
			if (day > 31) {
				day -= 31;
				month++;
			}
		}
		else if (month == 4 || month == 6 || month == 9 || month == 12) {
			if (day > 30) {
				day -= 30;
				month++;
			}
		}
		else {
			if (year % 4 == 0) {
				if (day > 29) {
					day -= 29;
					month++;
				}
			}
			else {
				if (day > 28) {
					day -= 28;
					month++;
				}
			}
		}
	}
	void nextHour() {
		if (hour >= 24) {
			hour -= 24;
			day++;
		}
	}
	void nextMinute(){
		if (minute >= 60) {
			minute -= 60;
			hour++;
		}
	}
	void nextSecond() {
		if (second >= 60) {
			second -= 60;
			minute++;
		}
	}
	void next() {
		nextSecond();
		nextMinute();
		nextHour();
		nextDay();
		nextMonth();
	}
	void tick() {
		second++;
		next();
	}
	void printUniversal() const{
		cout << setfill('0') << setw(2) << getDay() << "/" << setfill('0') << setw(2) << getMonth() << "/" << setfill('0') << setw(4) << getYear() << " " << setfill('0') << setw(2) << getHour() << ":" << setfill('0') << setw(2) << getMinute() << ":" << setfill('0') << setw(2) << getSecond() << endl;
	}
	void printStandard()const {
		cout << setfill('0') << setw(2) << getDay() << "/" << setfill('0') << setw(2) << getMonth() << "/" << setfill('0') << setw(4) << getYear() << " " << setfill('0') << setw(2) << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12) << ":" << setfill('0') << setw(2) << getMinute() << ":" << setfill('0') << setw(2) << getSecond() << (hour < 12 ? "AM" : "PM") << endl;
	}
};
int main() {
	DateAndTime d(23, 59, 50, 17, 3, 2024);
	for (int i = 0; i <= 20; i++) {
		d.tick();
		d.printUniversal();
	}
}
