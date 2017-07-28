#include <iostream>
using namespace std;
class A
{
public:
    A(int a0):a(a0) {}
    void showA() { cout<<a<<endl; }
protected:
    int a;
}; 
 
class C
{
public:
    C(int c0):c(c0) {}
    void showC() { cout<<c<<endl; }
protected:
    int c;
};

class B : public A, public C
{
public:
	B(int x = 11,int y = 22) : A(x),C(y) {}
private:
	int x;
	int y;	
};
