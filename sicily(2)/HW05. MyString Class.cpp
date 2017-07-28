#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class MyString
{
public:
    MyString(const char*);
    MyString(int = 0, char = '\0');          //initialize size_t number of char, terminated with '\0'
    MyString(const MyString&);               //copy constructor
    ~MyString();                             //destructor
    const char* c_str();                     //return private char*
    static int getNumberOfObjects();
private:
    char *str;
    static int numberOfObjects;              //count the number of MyString objects
};

int MyString::numberOfObjects = 0;           //在全局声明 

MyString::MyString(const char* s)
{
	int size = strlen(s);
	str = new char [size];
	for(int i = 0; i < size; i++)
	{
		str[i] = s[i];
	}
	++numberOfObjects;
}

MyString::MyString(int size_t, char c) {
	str = new char [size_t];                  //要先给str分配空间 !
	for(int i = 0; i < size_t; i++)
	{
		str[i] = c;
	}
	++numberOfObjects;
}

MyString::MyString(const MyString& c) {
	int size = strlen(c.str);
	str = new char [size];
	for(int i = 0; i < size; i++)
	{
		str[i] = c.str[i];
	}
	++numberOfObjects;
}
	
MyString::~MyString() {
	--numberOfObjects;
}

const char* MyString::c_str() {
	return str;
}

int MyString::getNumberOfObjects() {
	return numberOfObjects;
}

/**********************测试代码**************************/ 
int main()
{
	MyString ms1(3, '*');
    cout << ms1.c_str() << endl;
	MyString *ptr_ms2 = new MyString("陪你把独自孤单 变成了勇敢");
    MyString *ptr_ms3 = new MyString("陪你把想念的酸 拥抱成温暖");
    MyString *ptr_ms4 = new MyString("一次次失去 又重来 我没离开");
    MyString *ptr_ms5 = new MyString("陪伴是最长情的告白");
    {
        MyString ms3(ms1);
    }
    cout << ptr_ms2->c_str() << endl;
    cout << ptr_ms3->c_str() << endl;
    cout << ptr_ms4->c_str() << endl;
    cout << ptr_ms5->c_str() << endl;
    //delete ptr_ms2;
    cout << MyString::getNumberOfObjects() << endl;
    return 0;
}
