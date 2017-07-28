#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class Land
{
public:
	Land() : price_(0) {}
	explicit Land(int price);
	virtual double CalMoney() = 0;
protected:
	int price_;
};
 
class Square : public Land
{
public:
	Square(double len, int price);
	double CalMoney();
private:
	//length of side of a square
	double len_;
};
 
class Circle : public Land
{
public:
	Circle(double radius, int price);
	double CalMoney();
private:
	//length of radius of a circle
	double radius_;
};
 
class Accountant
{
public:
	Accountant() : money_(0) {}
	// develop a land, earn the value of the land
	void DevelopEstate(Land* land);
	// return the value of money_
	double CheckMoney();
private:
	double money_;
};
 
//your code will be here
const double pi = acos(-1);

Land::Land(int price)
{
	price_ = price;
}

double Land::CalMoney()
{
	return (double)price_;
}

Square::Square(double len, int price)
{
	price_ = price;
	len_ = len;
}

double Square::CalMoney()
{
	return len_*len_*price_;
}

Circle::Circle(double radius, int price)
{
	price_ = price;
	radius_ = radius;
}

double Circle::CalMoney()
{
	return pi*radius_*radius_*price_;
}

void Accountant::DevelopEstate(Land* land)
{
	money_ += land->CalMoney();
}

double Accountant::CheckMoney()
{
	return money_;
}
 
int main(int argc, const char *argv[])
{
	Accountant py;
	Circle *a = new Circle(100, 10000);
	Square *b = new Square(100, 50000);
	py.DevelopEstate(a);
	cout << setprecision(10) << py.CheckMoney() << endl;
	py.DevelopEstate(b);
	cout << setprecision(10) << py.CheckMoney() << endl;
 
	return 0;
}
