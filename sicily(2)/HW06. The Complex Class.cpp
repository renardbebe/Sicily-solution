class Complex //复数类
{
public:
	Complex(double real = 0, double imag = 0);
	Complex operator+(Complex& com);
	Complex operator-(Complex& com);
	Complex operator*(Complex& com);
	Complex operator/(Complex& com);
	double& operator[](int i);
	double operator[](int i) const;
	friend ostream& operator<<(ostream& os, Complex& com);//友元函数重载提取运算符"<<"
	friend istream& operator>>(istream& is, Complex& com);//友元函数重载插入运算符">>"
private:
	double real;//实数
	double imag;//虚数
};

#include <iostream>

using namespace std;

Complex::Complex(double real, double imag) {
	this->real = real;
	this->imag = imag;
}

Complex Complex::operator+(Complex& com) {
	Complex ans;
	ans.real = real + com.real;
	ans.imag = imag + com.imag;
	return ans;
}

Complex Complex::operator-(Complex& com) {
	Complex ans;
	ans.real = real - com.real;
	ans.imag = imag - com.imag;
	return ans;
}

Complex Complex::operator*(Complex& com) {
	Complex ans;
	ans.real = real*com.real - imag*com.imag;
	ans.imag = real*com.imag + imag*com.real;
	return ans;
}

Complex Complex::operator/(Complex& com) {
	Complex ans;
	ans.real = (real*com.real + imag*com.imag) / (com.real*com.real + com.imag*com.imag);
	ans.imag = (imag*com.real - real*com.imag) / (com.real*com.real + com.imag*com.imag);
	return ans;
}

double& Complex::operator[](int i) {
	if(i == 0) return real;
	else if(i == 1) return imag;
}

double Complex::operator[](int i) const {
	if(i == 0) return real;
	else if(i == 1) return imag;
}

ostream& operator<<(ostream& os, Complex& com) {
	if(com.imag == 0) os << com.real;
	else
	{
		if(com.real == 0)
		{
			if(com.imag == 1)
			{
				os << "i";
			}
			else if(com.imag == -1)
			{
				os << "-" << "i";
			}
			else os << com.imag << "i";
		}
		else
		{
			if(com.imag == 1)
			{
				os << com.real << "+" << "i";
			}
			else if(com.imag == -1)
			{
				os << com.real << "-" << "i";
			}
			else
			{
				if(com.imag < 0) os << com.real << com.imag << "i";
				else os << com.real << "+" << com.imag << "i";	
			}	
		}
	}
	return os;
}

istream& operator>>(istream& is, Complex& com) {
	is >> com.real >> com.imag;
	return is;
}

int main ()
{
	int T;
	cin >> T;
	while (T--) {
		Complex com1, com2;
		cin >> com1;
		cout << com1 << endl;
		cout << com1[0] << " " << com1[1] << endl;
		
		cin >> com2;
		cout << com2 << endl;
		cout << com2[0] << " " << com2[1] << endl;
		
		Complex c1 = com1 + com2;
		cout << "(" << com1 << ")+(" << com2 << ")=" << c1 << endl;
		
		Complex c2 = com1 - com2;
		cout << "(" << com1 << ")-(" << com2 << ")=" << c2 << endl;
		
		Complex c3 = com1 * com2;
		cout << "(" << com1 << ")*(" << com2 << ")=" << c3 << endl;
		
		Complex c4 = com1 / com2;
		cout << "(" << com1 << ")/(" << com2 << ")=" << c4 << endl;
	}
    return 0;
}
