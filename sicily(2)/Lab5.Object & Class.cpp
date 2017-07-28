// -- Class 类 
class Rectangle
{
  private:
    double width, height;
  public:
    Rectangle() 
	{
		width=0.0;
		height=0.0;
	}
    Rectangle(double Width, double Height)
    {
    	width=Width;
    	height=Height;
    }
    double getWidth()
    {
    	return width;
    }
    double getHeight()
    {
    	return height;
    }
    void setWidth(double Width)
	{
		width=Width;
	}
    void setHeight(double Height)
    {
    	height=Height;
    }
    double getArea()
	{
		return width*height;
    }
    double getPerimeter()
    {
    	return 2*(width+height);
    }
};                                 

// 客户端调用 

#include <cstdio>
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    Rectangle r1;
    cout << fixed << setprecision(2);
    cout << "width: " << r1.getWidth() << "; Height: " << r1.getHeight() 
      << "; Area: " << r1.getArea() << "; perimeter: " << r1.getPerimeter() << endl;  // width: 0.00; Height: 0.00; Area: 0.00; perimeter: 0.00

    r1.setWidth(2.0);
    r1.setHeight(1.5);
    
    cout << "width: " << r1.getWidth() << "; Height: " << r1.getHeight() 
      << "; Area: " << r1.getArea() << "; perimeter: " << r1.getPerimeter() << endl;  //width: 2.00; Height: 1.50; Area: 3.00; perimeter: 7.00
    
    Rectangle r2(1.5, 2.0);
    cout << "width: " << r2.getWidth() << "; Height: " << r2.getHeight() 
      << "; Area: " << r2.getArea() << "; perimeter: " << r2.getPerimeter() << endl;  //width: 1.50; Height: 2.00; Area: 3.00; perimeter: 7.00
      
    return 0;
}



