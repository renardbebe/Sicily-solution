#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

class Rational
{
public:
  Rational();
  Rational(long numerator, long denominator);
  long getNumerator();
  long getDenominator();
  Rational add(Rational &secondRational);
  Rational subtract(Rational &secondRational);
  Rational multiply(Rational &secondRational);
  Rational divide(Rational &secondRational);
  int compareTo(Rational &secondRational); // ”<”: -1, “=”: 0, “>”: 1
  bool equals(Rational &secondRational);
  int intValue();
  double doubleValue();
  string toString();

  bool operator<(Rational &secondRational);
  bool operator<=(Rational &secondRational);
  bool operator>(Rational &secondRational);
  bool operator>=(Rational &secondRational);
  bool operator!=(Rational &secondRational);
  bool operator==(Rational &secondRational);

  Rational operator+(Rational &secondRational);
  Rational operator-(Rational &secondRational); 
  Rational operator*(Rational &secondRational);
  Rational operator/(Rational &secondRational);

  Rational& operator+=(Rational &secondRational);
  Rational& operator-=(Rational &secondRational);
  Rational& operator*=(Rational &secondRational);
  Rational& operator/=(Rational &secondRational);

  long& operator[](const int &index);

  Rational& operator++();
  Rational& operator--();

  Rational operator++(int dummy);
  Rational operator--(int dummy);

  Rational operator+();
  Rational operator-();

  friend ostream &operator<<(ostream &stream, Rational rational);
  friend istream &operator>>(istream &stream, Rational &rational);

  operator double();
  
private:
  long numerator;
  long denominator;
  static long gcd(long n, long d);
};

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

Rational::Rational() {
    numerator = 0;
    denominator = 0;
}

Rational::Rational(long numerator, long denominator) {
    if(denominator > 0)
    {
	    this->numerator = numerator;
	    this->denominator = denominator;	
    }
	else
	{
		this->numerator = 0 - numerator;
	    this->denominator = 0 - denominator;
	}
}

long Rational::getNumerator() {
    return numerator;
}

long Rational::getDenominator() {
    return denominator;
}

Rational Rational::add(Rational &secondRational) {
    Rational ans;
    long up = 0, down = 0;
    up = numerator * secondRational.denominator + denominator * secondRational.numerator;
    down = denominator * secondRational.denominator;
    long tmp = gcd(up,down);
    up /= tmp;
    down /= tmp;
    ans.numerator = up;
    ans.denominator = down;
    return ans;
}

Rational Rational::subtract(Rational &secondRational) {
    Rational ans;
    long up = 0, down = 0;
    up = numerator * secondRational.denominator - denominator * secondRational.numerator;
    down = denominator * secondRational.denominator;
    long tmp = gcd(up,down);
    up /= tmp;
    down /= tmp;
    ans.numerator = up;
    ans.denominator = down;
    return ans;
}

Rational Rational::multiply(Rational &secondRational) {
    Rational ans;
    long up = 0, down = 0;
    up = numerator * secondRational.numerator;
    down = denominator * secondRational.denominator;
    long tmp = gcd(up,down);
    up /= tmp;
    down /= tmp;
    ans.numerator = up;
    ans.denominator = down;
    return ans;
}

Rational Rational::divide(Rational &secondRational) {
    Rational ans;
    long up = 0, down = 0;
    up = numerator * secondRational.denominator;
    down = denominator * secondRational.numerator;
    long tmp = gcd(up,down);
    up /= tmp;
    down /= tmp;
    ans.numerator = up;
    ans.denominator = down;
    return ans;
}

int Rational::compareTo(Rational &secondRational) {       // ”<”: -1, “=”: 0, “>”: 1
    long a = numerator * secondRational.denominator - denominator * secondRational.numerator;
	if(a < 0) return -1;
	else if (a == 0) return 0;
	else return 1;
}

bool Rational::equals(Rational &secondRational) {
    if(compareTo (secondRational) == 0) return true;
    else return false;
}

int Rational::intValue() {
    int a;
    a = numerator / denominator;
    return a;
}

double Rational::doubleValue() {
    double a;
    a = (double)numerator / denominator - (int)numerator / denominator;
    return a;
}

string to_String(int n)
{
	int m = n;
	int i = 0, j = 0;
	char s[1000];
	char ss[1000];
	if(n == 0) 
	{
		ss[0] = '0';
		ss[1] = '\0';
	}
	else if(n < 0)
	{
		m = 0 - m;
		while (m > 0)
		{
			s[i++] = m % 10 + '0';
	    	m /= 10;
		}
		s[i] = '\0';
	
		i--;
		ss[0] = '-';
		j = 1;
		while(i >= 0)
		{
			ss[j++] = s[i--];
		}
		ss[j] = '\0';
	}
	else
	{
		while (m > 0)
		{
			s[i++] = m % 10 + '0';
	    	m /= 10;
		}
		s[i] = '\0';
	
		i--;
		while(i >= 0)
		{
			ss[j++] = s[i--];
		}
		ss[j] = '\0';	
	}
	return ss;
}

string Rational::toString() {
    string s;
    long tmp = gcd(numerator,denominator);
    numerator /= tmp;
    denominator /= tmp;
    s += to_String(numerator);
    if(denominator != 1 && numerator)
    {
	    s += "/";
	    s += to_String(denominator); 	
    }
    return s;
}

// Define function operators for relational operators
bool Rational::operator<(Rational &secondRational) {
    if(compareTo (secondRational) == -1) return true;
    else return false;
}

bool Rational::operator<=(Rational &secondRational) {
    if(compareTo (secondRational) != 1) return true;
    else return false;
}

bool Rational::operator>(Rational &secondRational) {
    if(compareTo (secondRational) == 1) return true;
    else return false;
}

bool Rational::operator>=(Rational &secondRational) {
    if(compareTo (secondRational) != -1) return true;
    else return false;
}

bool Rational::operator!=(Rational &secondRational) {
    if(compareTo (secondRational) ) return true;
    else return false;
}

bool Rational::operator==(Rational &secondRational) {
    if(compareTo (secondRational) == 0) return true;
    else return false;
}

// Define function operators for arithmetic operators
Rational Rational::operator+(Rational &secondRational) {
    return add(secondRational);
}

Rational Rational::operator-(Rational &secondRational) {
    return subtract(secondRational);
}

Rational Rational::operator*(Rational &secondRational) {
    return multiply(secondRational);
}

Rational Rational::operator/(Rational &secondRational) {
    return divide(secondRational);
}

// Define function operators for shorthand operators
Rational& Rational::operator+=(Rational &secondRational) {
    long up = 0, down = 0;
    up = numerator * secondRational.denominator + denominator * secondRational.numerator;
    down = denominator * secondRational.denominator;
    long tmp = gcd(up,down);
    up /= tmp;
    down /= tmp;
    this->numerator = up;
    this->denominator = down;
    return *this;
}

Rational& Rational::operator-=(Rational &secondRational) {
    long up = 0, down = 0;
    up = numerator * secondRational.denominator - denominator * secondRational.numerator;
    down = denominator * secondRational.denominator;
    long tmp = gcd(up,down);
    up /= tmp;
    down /= tmp;
    this->numerator = up;
    this->denominator = down;
    return *this;
}

Rational& Rational::operator*=(Rational &secondRational) {
    long up = 0, down = 0;
    up = numerator * secondRational.numerator;
    down = denominator * secondRational.denominator;
    long tmp = gcd(up,down);
    up /= tmp;
    down /= tmp;
    this->numerator = up;
    this->denominator = down;
    return *this;
}

Rational& Rational::operator/=(Rational &secondRational) {
    long up = 0, down = 0;
    up = numerator * secondRational.denominator;
    down = denominator * secondRational.numerator;
    long tmp = gcd(up,down);
    up /= tmp;
    down /= tmp;
    this->numerator = up;
    this->denominator = down;
    return *this;
}

// Define function operator [], 0 for numerator and 1 for denominator
long& Rational::operator[](const int &index) {
    if(index == 0) return numerator;
    else return denominator;
}

// Define function operators for prefix ++ and --
Rational& Rational::operator++() {
    numerator = numerator + denominator;
    return *this;
}

Rational& Rational::operator--() {
    numerator = numerator - denominator;
    return *this;
}

// Define function operators for postfix ++ and --                                重载后置运算符需要 临时变量 
Rational Rational::operator++(int dummy) {
    Rational tmp = *this;
    ++(*this);
    return tmp;
}

Rational Rational::operator--(int dummy) {
    Rational tmp = *this;
    --(*this);
    return tmp;
}

// Define function operators for unary + and -
Rational Rational::operator+() {
    return *this;
}

Rational Rational::operator-() {
    Rational ans;
    ans.numerator = 0 - numerator;
    ans.denominator = denominator;
    return ans;
}

// Define the output and input operator
ostream &operator<<(ostream &stream, Rational rational) {        // 输出最简分数形式 
	long a = rational.numerator, b = rational.denominator;
	long tmp = rational.gcd(a,b);
	rational.numerator /= tmp;
	rational.denominator /= tmp;
	
	if(rational.denominator == 1 || rational.numerator == 0) stream << rational.numerator;
	else stream << rational.numerator << "/" << rational.denominator;
    return stream;
}

istream &operator>>(istream &stream, Rational &rational) {
    stream >> rational.numerator >> rational.denominator;
    if(rational.denominator < 0) 
    {
    	rational.numerator = 0 - rational.numerator;
    	rational.denominator = 0 - rational.denominator;
    }
    long a = rational.numerator, b = rational.denominator;
	long tmp = rational.gcd(a,b);
	rational.numerator /= tmp;
	rational.denominator /= tmp;
    return stream;
}

// Define function operator for conversion
Rational::operator double() {
    return (double)numerator / denominator;
}

long Rational::gcd(long n, long d) {
    long a = 1;
    if(n < 0) n = (int)abs(n);
    if(d < 0) d = (int)abs(d);
    if(n > d) swap(n,d);
    for(int i = 1; i <= n; i++)
    {
        if(n % i == 0 && d % i == 0) a = i;
    } 
    return a;
}                                 
     
int main()
{
  // Create and initialize two rational numbers r1 and r2.
  long a,b;
  cin>>a>>b;
  Rational r1(a, b);
  Rational r2(100, 50);

  cout << r1 << endl << r2 << endl;
  cout << r1.toString() << endl;

  cout << r1 << " > " << r2 << " is " << (r1 > r2) << endl;

  cout << r1 << " >= " << r1 << " is " << (r1 >= r1) << endl; 

  cout << r1 << " < " << r2 << " is " << (r1 < r2) << endl;

  cout << r1 << " <= " << r1 << " is " << (r1 <= r1) << endl;

  cout << r1 << " == " << r2 << " is " << (r1 == r2) << endl;

  cout << r1 << " == " << r1 << " is " << (r1 == r1) << endl;

  cout << r1 << " != " << r2 << " is " << (r1 != r2) << endl;

  cout << r1 << " != " << r1 << " is " << (r1 != r1) << endl;

  // Test toString, add, substract, multiply, and divide operators

  cout << r1 << " + " << r2 << " = " << r1 + r2 << endl;

  cout << r1 << " - " << r2 << " = " << r1 - r2 << endl;

  cout << r1 << " * " << r2 << " = " << r1 * r2 << endl;

  cout << r1 << " / " << r2 << " = " << r1 / r2 << endl;

  // Test shorthand operators

  Rational r3(1, 2);

  r3 += r1;

  cout << "r3 is " << r3 << endl;

  r3 -= r1;

  cout << "r3 is " << r3 << endl; 

  // Test function operator []

  Rational r4(1, 3);

  r4[0] = 2; r4[1] = 3;

  cout << "r4 is " << r4 << endl;

  // Test function operators for 

  // prefix ++ and --

  // postfix ++ and --

  r3 = r4++;

  cout << "r3 is " << r3 << endl;

  cout << "r4 is " << r4 << endl;

  r3 = r4--;

  cout << "r3 is " << r3 << endl;

  cout << "r4 is " << r4 << endl;

  r3 = ++r4;

  cout << "r3 is " << r3 << endl;

  cout << "r4 is " << r4 << endl;

  r3 = --r4;

  cout << "r3 is " << r3 << endl;

  cout << "r4 is " << r4 << endl;

  // Test function operator for conversion

  cout << "1 + " << r4 << " is " << (1 + r4) << endl;

  return 0;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
