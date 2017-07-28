#include <iostream>
#include <cmath>

using namespace std;

class MyVector 
{
public: 
    MyVector(int = 0, int = 0, int = 0);
    MyVector(const MyVector &);
    void display();
    friend MyVector add(MyVector &v1, MyVector &v2);
    friend MyVector sub(MyVector &v1, MyVector &v2);
    friend int dot(MyVector &v1, MyVector &v2);
    friend MyVector cross(MyVector &v1, MyVector &v2);
private:
    int x, y, z;
};

MyVector::MyVector(int x, int y, int z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

MyVector::MyVector(const MyVector & c) {
	x = c.x;
	y = c.y;
	z = c.z;
}

void MyVector::display() {
	cout << "(" << x << "," << y << "," << z << ")\n"; 
}

/***************** FRIEND ********************/
MyVector add(MyVector &v1, MyVector &v2) {                      // 函数有返回值，返回类型是一个类对象 
	MyVector ans;
	ans.x = v1.x + v2.x;
	ans.y = v1.y + v2.y;
	ans.z = v1.z + v2.z;
	return ans;
}

MyVector sub(MyVector &v1, MyVector &v2) {
	MyVector ans;
	ans.x = v1.x - v2.x;
	ans.y = v1.y - v2.y;
	ans.z = v1.z - v2.z;
	return ans;
}

int dot(MyVector &v1, MyVector &v2) {
	return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
}

MyVector cross(MyVector &v1, MyVector &v2) {            // 叉乘公式: a×b=（y1z2-y2z1,z1x2-z2x1,x1y2-x2y1）
	MyVector ans;
	ans.x = v1.y*v2.z - v2.y*v1.z;
	ans.y = v1.z*v2.x - v2.z*v1.x;
	ans.z = v1.x*v2.y - v2.x*v1.y;
	return ans;
}

/********************s**测试代码**************************/ 
int main()
{
    MyVector a;
    MyVector b(-1);
    MyVector c(3,4,5);
    MyVector d(17,12);
    MyVector e(c);
	MyVector x = add(a, b);
    x.display();
    MyVector y = sub(b, c);
    y.display();
    MyVector z = cross(c, d);
    z.display();
    int w = dot(d, e);
    cout << w << endl;
    return 0;
}
