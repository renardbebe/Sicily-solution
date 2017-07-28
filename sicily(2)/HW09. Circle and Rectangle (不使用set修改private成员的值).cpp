#include <iostream>
#include <cmath>

using namespace std;

class Point{
private:
	double x,y;
public:
	Point();
	Point(double xv,double yv);
	Point(Point& pt);
	double getx();
	double gety();
};

Point::Point()
{
	x = 0;
	y = 0;
}

Point::Point(double xv,double yv)
{
	x = xv;
	y = yv;
}

Point::Point(Point& pt)
{
	x = pt.getx();
	y = pt.gety();
}

double Point::getx()
{
	return x;
}

double Point::gety()
{
	return y;
}

class Rectangle : public Point
{
private:
	double length;
	double width;
public:
	Rectangle();
	Rectangle(double , double , double , double );
	Rectangle(Rectangle& );
	int position(Point &pt);
};

Rectangle::Rectangle() : Point(0,0)    // 默认构造函数
{
	length = 0;
	width = 0;
}

Rectangle::Rectangle(double x, double y, double l, double w) : Point(x,y)   // 带参数的构造函数 
{
	length = l;
	width = w;
}

Rectangle::Rectangle(Rectangle& re) : Point(re.getx(),re.gety())   //  拷贝构造函数 
{
	length = re.length;
	width = re.width;
}

int Rectangle::position(Point &pt)
{
	if((pt.getx() >  Point::getx() && (pt.getx() <  Point::getx() + length) ) && pt.gety() > Point::gety() && (pt.gety() < Point::gety() + width))  // inside
		return -1;
	else if(pt.getx() < Point::getx() || pt.getx() > Point::getx() + length || pt.gety() < Point::gety() || pt.gety() > Point::gety() + width)  // outside
		return 1;
	else return 0;
}

class Circle : public Point
{
private:
	double radius;
public:
	Circle();
	Circle(double , double , double );
	Circle(Circle & );
	int position(Point &pt);
};

Circle::Circle() : Point(0,0)
{
	radius = 0;
}

Circle::Circle(double x, double y, double r): Point(x,y)
{	
	radius = r;
}

Circle::Circle(Circle & c) : Point(c.getx(),c.gety())
{
	radius = c.radius;
}

int Circle::position(Point &pt)
{
	double d = (pt.getx() - Point::getx())*(pt.getx() - Point::getx()) + (pt.gety() - Point::gety())*(pt.gety() - Point::gety());
	if(d < radius*radius)  // inside
		return -1;
	else if(abs(d - radius*radius) < 0.0005)  // on
		return 0;
	else return 1;
}

//////////////////////////////////////////////////

int main()
{
	Circle cc1(0,0,5);
	Rectangle rt1(1,1,2,2);
	Point p1(3,2);
	Circle cc2(cc1);
	
	cout << "The Rectangle: Left corner vertex (" << rt1.getx() << "," << rt1.gety() << ")\n";
	cout << "The Circle: Middle vertex (" << cc1.getx() << "," << cc1.gety() << ")\n";
	cout << "The Point: (" << p1.getx() << "," << p1.gety() << ")\n";
	
	cout<<"Point p1:\n";
	switch(rt1.position(p1))
	{
	 case 0:cout<<"on-rectangle."<<endl;break;
	 case -1:cout<<"inside-rectangle."<<endl;break;
	 case 1:cout<<"outside-rectangle."<<endl;break;
	}
	switch(cc1.position(p1))
	{
	 case 0:cout<<"on-circle."<<endl;break;
	 case -1:cout<<"inside-circle."<<endl;break;
	 case 1:cout<<"outside-circle."<<endl;break;
	}
	return 0;
}
