#include <iostream>
#include <string>
#include <iomanip>
 
using namespace std;
 
class Date {
    public:
        Date();
        Date(const Date&);
        Date(const string&);
        Date(int, int = 2, int = 29);
        void setDate(const string&);
        void printDate() const;
        int getYear() const;
        int getMonth() const;
        int getDay() const;
    private:
        bool checkFormat(const string&) const;
        bool validate();
        int year, month, day;
        bool pass;
};
 
/******** this part should be submitted ********/
#include <cstdio>

Date::Date() {     //默认构造函数
	year = 2006;
	month = 1;
	day = 1;
	pass = true;
}
 
Date::Date(const Date& anotherDate) {     //拷贝构造函数
	year = anotherDate.getYear();
	month = anotherDate.getMonth();
	day = anotherDate.getDay();
	pass = validate();
}
 
Date::Date(const string& input) {     //类型转换构造函数
	setDate(input);
	pass = validate();
}
 
Date::Date(int year, int month, int day) {     //带默认参数的构造函数
	Date::year = year;
	Date::month = month;
	Date::day = day;
	pass = validate();
}
 
void Date::printDate() const {     //输出 
	if(pass)
	{
		printf("%04d",year);
		cout << "-";
		printf("%02d",month);
		cout << "-";
		printf("%02d",day);
		cout << endl; 
	}
	else cout << "Invalid Date\n";
}

int Date::getYear() const {
	return year;
}
 
int Date::getMonth() const {
	return month;
}
 
int Date::getDay() const {
	return day;
}
 
void Date::setDate(const string& input) {     //设置新的日期
	if(checkFormat(input) == true)
	{
		int y = 0, m = 0, d = 0;
		for(int i = 0; i < 4; i++)
		{
			y = y*10 + input[i] -'0';
		}
		for(int i = 5; i <= 6; i++)
		{
			m = m*10 + input[i] -'0';
		}
		for(int i = 8; i <= 9; i++)
		{
			d = d*10 + input[i] -'0';
		}
		year = y;
		month = m;
		day = d;
	}
	else
	{
		year = 233;
		month = 233;
		day = 233;
	}
	pass = validate();
}
 
bool Date::checkFormat(const string& input) const {     //判断格式 
	if(input.length() != 10) return false;
	if(input[4] != ':' || input[7] != ':') return false;
	for (int i = 0; i < 10; i++)
	{
		if(!isdigit(input[i]) && i != 4 && i != 7) return false;
	}
	return true;
}
 
bool Date::validate() {     //判断日期是否合法 
	if(month < 1 || month > 12) return false;
	else if(day <= 0 || day > 31) return false;
	else if(month == 2)
	{
		if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
		{
			if(day > 29) return false;
		}
		else
		{
			if(day > 28) return false;
		}
	}
	else if(month == 4 || month == 6 || month == 9 || month == 11)
	{
		if(day > 30) return false;
	}
	return true;
}
/******** this part should be submitted ********/
 
int main() {
	int T;
	int flag;
	Date* myDate;
	
	string dateString;
	int year, month, day;
	
	cin >> T;
	while (T--) {
		cin >> flag;
		if (flag == 1) {
			cin >> dateString;
			myDate = new Date(dateString);			
		}
		else if (flag == 2) {
			cin >> year;
			myDate = new Date(year);
		}
		else if (flag == 3) {
			cin >> year >> month;
			myDate = new Date(year, month);
		}
		else if (flag == 4) {
			cin >> year >> month >> day;
			myDate = new Date(year, month, day);
        }
        else if (flag == 5){
                myDate = new Date(2016,3,7);
                myDate -> printDate();
                cin >> dateString;
                myDate->setDate(dateString);
                cout << setw(1);
                cout << myDate->getYear() << ' ';
                cout << myDate->getMonth() <<' ';
                cout << myDate->getDay() << endl;
        }
        else if (flag == 6){
                myDate = new Date();
                myDate ->printDate();
                delete myDate;
                cin >> year >> month >> day;
                myDate = new Date( Date(year,month,day) );

                cout << setw(1);
                cout << myDate->getYear() << ' ';

                cout << myDate->getMonth() <<' ';
                cout << myDate->getDay() << endl;
		}
 
		myDate->printDate();
                delete myDate;
	}
	
	return 0;
}
