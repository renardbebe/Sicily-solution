#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

class MyInteger
{
  private:
    int value;
  public:
    MyInteger(int);
    int getValue()const;
    bool isEven()const;
    bool isOdd()const;
    bool isPrime()const;
    static bool isEven(int);
    static bool isOdd(int);
    static bool isPrime(int);
    static bool isEven(const MyInteger&);
    static bool isOdd(const MyInteger&);
    static bool isPrime(const MyInteger&);
    bool equals(int)const;
    bool equals(const MyInteger&)const;
    static int parseInt(const string&);
};

MyInteger::MyInteger(int x) {                            // ��ʼ�� 
    value = x;
}

int MyInteger::getValue()const {
    return value;
}

bool MyInteger::isEven()const {                          //  �ж�ż�� 
    if( (int)abs(value)%2 == 0) return true;             // ȡģֻ���int,absת���������Ϊdouble 
    else return false;
}

bool MyInteger::isOdd()const {                           //  �ж����� 
    if( (int)abs(value)%2 == 1) return true;
    else return false;
}

bool MyInteger::isPrime()const {                          //  �ж�����
	int flag = 1;  
	if(value < 2) flag = 0;
	else
	{
		for (int i = 2; i <= sqrt(value); i++) {
			if (value % i == 0) {
				flag = 0;
				break;
			}
		}	
	}
	if (flag) return true;
	else return false;	
}

bool MyInteger::isEven(int x) {
    if( (int)abs(x)%2 == 0) return true;
    else return false;
}

bool MyInteger::isOdd(int x) {
    if( (int)abs(x)%2 == 1) return true;
    else return false;
}

bool MyInteger::isPrime(int x) {
	int flag = 1;  
	if(x < 2) flag = 0;
	else
	{
		for (int i = 2; i <= sqrt(x); i++) {
			if (x % i == 0) {
				flag = 0;
				break;
			}
		}	
	}
	if (flag) return true;
	else return false;	
}

bool MyInteger::isEven(const MyInteger& my_number) {
    int x = my_number.value;
    if( (int)abs(x)%2 == 0) return true;
    else return false;
}

bool MyInteger::isOdd(const MyInteger& my_number) {
    int x = my_number.value;
    if( (int)abs(x)%2 == 1) return true;
    else return false;
}

bool MyInteger::isPrime(const MyInteger& my_number) {
	int x = my_number.value;
	int flag = 1;  
	if(x < 2) flag = 0;
	else
	{
		for (int i = 2; i <= sqrt(x); i++) {
			if (x % i == 0) {
				flag = 0;
				break;
			}
		}	
	}
	if (flag) return true;
	else return false;	
}

bool MyInteger::equals(int x)const {
    if(x == value) return true;
    else return false;
}

bool MyInteger::equals(const MyInteger& my_number)const {
    int x = my_number.value;
    if(x == value) return true;
    else return false;
}

int MyInteger::parseInt(const string& str) {
	int h = 0;
	
	/* ����һ */
    if(str[0] == '-')
    {
        for(int i = 1; i < str.length(); i++)
	    {
	        h = h*10 + str[i] - '0';
	    }
	    h = 0 - h;
    }
    else
    {
	    for(int i = 0; i < str.length(); i++)
	    {
	        h = h*10 + str[i] - '0';
	    }	
    }
    
    /* ������ */
    /* h = atoi(str.c_str()); */
    
    return h;
}

/*   ���Դ��� 
int main ()
{
	MyInteger x(2);
	
	if(x.isEven()) cout << x.getValue() << " is even.\n";
	else cout << x.getValue() << " is not even.\n";
	if(x.isOdd()) cout << x.getValue() << " is odd.\n";
	else cout << x.getValue() << " is not odd.\n";
	if(x.isPrime()) cout << x.getValue() << " is prime.\n";
	else cout << x.getValue() << " is not prime.\n";
	if(x.equals(0)) cout << 0 << " is equal to " << x.getValue() << endl;
	else cout << 0 << " is not equal to " << x.getValue() << endl;
	string str = "-1234";
	cout << x.parseInt(str) << endl;
	
	return 0;
} 
*/
