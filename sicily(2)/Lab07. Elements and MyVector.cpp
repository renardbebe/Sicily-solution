#include <iostream>
using namespace std;
class Elements{
private:
      int value;
      static int numberOfObjects;
public:
      Elements();
      Elements(const int &value);//set value
      Elements(const Elements &elem);//copy constructor
      ~Elements();//descructor 

      Elements & operator=(const Elements &elem);//assignment
      Elements & operator=(const int &value);//assignment
      friend istream& operator>>(istream& is, Elements & elem);
      friend ostream& operator<<(ostream& os, const Elements & elem);
      
      void setValue(const int &value);
      int getValue()const;
      Elements & operator+=(const Elements &elem);
      Elements & operator+=(const int &value);
      Elements operator+(const Elements &elem)const;
      Elements operator+(const int &value)const;

      bool operator ==(const Elements &elem)const;
      bool operator ==(const int &value)const;
      bool operator <(const Elements &elem)const;
      bool operator <(const int &value)const;
      
      operator int()const;//converts Elementes to int

      static int getNumberOfObjects();//return the number of objects
};

class MyVector{
private:
      Elements *elem;
      int _size;
public:
      MyVector();//default constructor
      MyVector(int n);// constructor an Array of n Elements
      MyVector(const MyVector &vec);//copy constructor
      ~MyVector();//destructor

      const MyVector & operator=(const MyVector &vec);//assignment
      Elements &operator[](int i);//return the references of elem[i]
      Elements operator[](int i) const; //return the copy of elem[i]

      int size()const;//return the size

      bool operator == (const MyVector &vec)const;//judge if it is equal 
      friend istream& operator>>(istream& is, MyVector & vec);
      friend ostream& operator<<(ostream& os, const MyVector & vec);
};

int Elements::numberOfObjects = 0;

Elements::Elements() {
    value = 0;
    ++numberOfObjects;
}

Elements::Elements(const int &value) {
    this->value = value;
    ++numberOfObjects;
}

Elements::Elements(const Elements &elem) {
    this->value = elem.value;
    ++numberOfObjects;
}

Elements::~Elements() {
    --numberOfObjects;
}

Elements & Elements::operator=(const Elements &elem) {
    this->value = elem.value;
    return *this;
}

Elements & Elements::operator=(const int &value) {
    this->value = value;
    return *this;
}

istream& operator>>(istream& is, Elements & elem) {
    is >> elem.value;
    return is;
}

ostream& operator<<(ostream& os, const Elements & elem) {
    os << elem.value;
    return os;
}

void Elements::setValue(const int &value) {
    this->value = value;
}

int Elements::getValue() const {
    return value;
}

Elements & Elements::operator+=(const Elements &elem) {
    this->value += elem.value;
    return *this;
}

Elements & Elements::operator+=(const int &value) {
    this->value += value;
    return *this;
}

Elements Elements::operator+(const Elements &elem) const {
    Elements ans;
    ans.value = this->value + elem.value;
    return ans;
}

Elements Elements::operator+(const int &value) const {
    Elements ans;
    ans.value = this->value + value;
    return ans;
}

bool Elements::operator == (const Elements &elem) const {
    if(this->value == elem.value) return true;
    else return false;
}

bool Elements::operator == (const int &value) const {
    if(this->value == value) return true;
    else return false;
}

bool Elements::operator < (const Elements &elem) const {
    if(this->value < elem.value) return true;
    else return false;
}

bool Elements::operator < ( const int &value) const {
    if(this->value < value) return true;
    else return false;
}

Elements::operator int() const {
    return (int)value;
}

int Elements::getNumberOfObjects() {
    return numberOfObjects;
}

MyVector::MyVector() {
    _size = 1;
    elem = new Elements [_size];
    elem[0] = 0;
}

MyVector::MyVector(int n) {
	_size = n;
    elem = new Elements [_size];
}

MyVector::MyVector(const MyVector &vec) {
    _size = vec._size;
    elem = new Elements [_size];
    for(int i = 0; i < _size; i++) elem[i] = vec.elem[i];
}

MyVector::~MyVector() {
    if(_size) delete [] elem;
}

const MyVector & MyVector::operator=(const MyVector &vec) {
    if(*this == vec) return *this;                                                // 考虑删除自身的情况！ 
	if(_size) delete [] elem;
    _size = vec._size;
    elem = new Elements [_size];
    for(int i = 0; i < _size; i++) elem[i] = vec.elem[i];
    return *this;
}

Elements & MyVector::operator[](int i) {
    return elem[i];
}

Elements MyVector::operator[](int i) const {
    return elem[i];
}

int MyVector::size() const {
    return _size;
}

bool MyVector::operator == (const MyVector &vec) const {
    if(_size != vec._size) return false;
    for(int i = 0; i < _size; i++)
    {
        if(elem[i] != vec.elem[i]) return false;
    }
    return true;
}

istream& operator>>(istream& is, MyVector & vec) {
    is >> vec._size;
    if(vec._size) delete [] vec.elem;
	vec.elem = new Elements [vec._size];                // 勿忘使用类的指针对象前新开辟空间 
    for(int i = 0; i < vec._size; i++)
    {
        is >> vec.elem[i];
    }
    return is;
}

ostream& operator<<(ostream& os, const MyVector & vec) {
    for(int i = 0; i < vec._size; i++)
    {
        if(i == 0) os << vec.elem[i];
        else os << " " << vec.elem[i];
    }
    return os;
}

Elements getSum(const MyVector &vec)
{
    Elements sum = 0;
    for(int i=0;i<vec.size();i++)
    {
        sum += vec[i];
    }
    return sum;
}

void sample()
{
	MyVector vec;
	while( cin >> vec )
	{
		cout << vec << endl;
		MyVector vec2(vec);
		cout << vec2 << endl;
		
		Elements sum = getSum(vec);
		int average = (int)sum / vec.size();
		for(int i=0;i<vec.size();i++)
		{
		     if( vec[i] < average )
		     {
				vec [i] = average;
		     }
		}
		cout << vec << endl;
		if( vec == vec2 )
		{
		     cout << "They are equal" << endl;
		}
	}
}

 

int main()
{
	sample();
	if(Elements::getNumberOfObjects()!=0)
	{
	    cout << "Error: occupied memory" << endl;
	    cout << "Too young too simple, sometimes naive!" << endl;
	}
	return 0;
}
