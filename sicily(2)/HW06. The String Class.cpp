class String {
public:
	String();                // str = ""
	String(const char*);     // str = "abc" 
	String(const String&);   // str = other_string
	String& operator=(const char *);
	String& operator=(const String&);
	String operator+(const String&);
	~String();
 
	char& operator[](int i);
	char operator[](int i) const;
	
	int size() const;

	String& operator+=(const String&);
	String& operator+=(const char*);

	friend ostream& operator<<(ostream&, const String&);
	friend istream& operator>>(istream&, String&);
	friend bool operator==(const String& x, const char* s);
	friend bool operator==(const String& x, const String& y);
	friend bool operator!=(const String& x, const char* s);
	friend bool operator!=(const String& x, const String& y);

private:
	char *str;
};

///////////////////////////////////////////
#include <iostream>
#include <cstring>
using namespace std;

String::String() {
	str = NULL;
}

String::String(const char* s) {
	int size = strlen(s);
	str = new char [size+1];
	for(int i = 0; i < size; i++) str[i] = s[i];
	str[size] = '\0';
}

String::String(const String& s) {
	int size = strlen(s.str);
	str = new char [size+1];
	for(int i = 0; i < size; i++) str[i] = s.str[i];
	str[size] = '\0';
}

String& String::operator=(const char * s) {
	int size = strlen(s);
	if(str != NULL) delete [] str;
	str = new char [size+1];
	for(int i = 0; i < size; i++)
	{
		str[i] = s[i];
		str[size] = '\0';
	}
	return *this;
}

String& String::operator=(const String& s) {
	int size = strlen(s.str);
	if(str != NULL) delete [] str;
	str = new char [size+1];
	for(int i = 0; i < size; i++)
	{
		str[i] = s.str[i];
		str[size] = '\0';
	}
	return *this;
}

String String::operator+(const String& s) {
	int size1 = strlen(str);
	int size2 = strlen(s.str);
	String tmp;
	tmp.str = new char [size1+size2+1];
	for(int i = 0; i < size1; i++)
	{
		tmp.str[i] = str[i];
	}
	
	for(int i = size1; i < size1+size2; i++)
	{
		tmp.str[i] = s.str[i-size1];
		tmp.str[size1+size2] = '\0';
	}
	return tmp;
}

String::~String() {
	delete [] str;
}

char& String::operator[](int i) {
	return str[i];
}

char String::operator[](int i) const {
	return str[i];
}

int String::size() const {
	return strlen(str);
}

String& String::operator+=(const String& s) {         // 或者 *this = *this +s.str
	int size1 = strlen(str);
	int size2 = strlen(s.str);
	String tmp;
	tmp.str = new char [size1+size2+1];
	for(int i = 0; i < size1; i++)
	{
		tmp.str[i] = str[i];
	}
	
	for(int i = size1; i < size1+size2; i++)
	{
		tmp.str[i] = s.str[i-size1];
		tmp.str[size1+size2] = '\0';
	}
	if(str != NULL)
	{
		delete [] str;
		str = new char [strlen(tmp.str)];		
	}
	for(int i = 0; i < strlen(tmp.str); i++) str[i] = tmp.str[i];
	return *this;
}

String& String::operator+=(const char* s) {         // 或者 *this = *this +s
	int size1 = strlen(str);
	int size2 = strlen(s);
	String tmp;
	tmp.str = new char [size1+size2+1];
	for(int i = 0; i < size1; i++)
	{
		tmp.str[i] = str[i];
	}
	
	for(int i = size1; i < size1+size2; i++)
	{
		tmp.str[i] = s[i-size1];
		tmp.str[size1+size2] = '\0';
	}
	if(str != NULL)
	{
		delete [] str;
		str = new char [strlen(tmp.str)];		
	}
	for(int i = 0; i < strlen(tmp.str); i++) str[i] = tmp.str[i];
	return *this;
}

ostream& operator<<(ostream& output, const String& s) {
	if(s.str != NULL)
	{
		output << s.str;
	}
	return output;
}

istream& operator>>(istream& input, String& s) {
	s.str = new char [10000];                            // 要先开辟空间，s.str此时相当于野指针 
	input >> s.str;                                      // 输入内容存储在input输入流中 
	return input;
}

bool operator==(const String& x, const char* s) {
	if(strlen(x.str) != strlen(s)) return false;
	for(int i = 0; i < strlen(x.str); i++)
	{
		if(x.str[i] != s[i]) return false;
	}
	return true;
}

bool operator==(const String& x, const String& y) {
	if(strlen(x.str) != strlen(y.str)) return false;
	for(int i = 0; i < strlen(x.str); i++)
	{
		if(x.str[i] != y.str[i]) return false;
	}
	return true;
}

bool operator!=(const String& x, const char* s) {
	if(strlen(x.str) != strlen(s)) return true;
	for(int i = 0; i < strlen(x.str); i++)
	{
		if(x.str[i] != s[i]) return true;
	}
	return false;
}

bool operator!=(const String& x, const String& y) {
	if(strlen(x.str) != strlen(y.str)) return true;
	for(int i = 0; i < strlen(x.str); i++)
	{
		if(x.str[i] != y.str[i]) return true;
	}
	return false;
}

String f1(String a, String b)
{
	a[2] = 'x';
	char c = b[2];
	cout << "in f: " << a << ' ' << b << ' ' << c << '\n';
	return b;
}

void f2(String s, const String& r)
{
	char c1 = s[1];  // c1 = s.operator[](1).operator char()
	s[1] = 'c';    // s.operator[](1).operator=('c')
	char c2 = r[1];  // c2 = r.operator[](1)
//  r[1] = 'd';    // error: assignment to non-lvalue char, r.operator[](1) = 'd'
}

void f()
{
	String x, y, s;
	cout << "Please enter two strings\n";
	cin >> x >> y;
	cout << "x= " << x << " , y = " << y << '\n';
	
    y = f1(x,y);
    cout << y << endl;
    
	f2(x,y);
	
	cout << "s = \"" << s << "\"" << endl;
	s = "abc";
	cout << "s = \"" << s << "\"" << endl;
	
    cout << "\"" << x << "\" + \"" << y << "\" = " << "\"" << x+y << "\"\n";
	String z = x;
	if (x != z) cout << "x corrupted!\n";
	x[0] = '!';
	if (x == z) cout << "write failed!\n";
	cout << "exit: " << x << ' ' << z << '\n';  
	
	z = s;
	if (s != z) cout << "s corrupted!\n";
	s[0] = '!';
	if (s == z) cout << "write failed!\n";
	cout << "exit: " << s << ' ' << z << '\n';  
}

int main ()
{
	int T;
	cin >> T;
	while (T--)
	{
		f();
	}
}
