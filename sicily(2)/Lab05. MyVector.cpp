#include <iostream>
#include <cmath>

using namespace std;

class MyVector 
{
public: 
    MyVector();
    MyVector(int size);
    void create(int size);
    void setValue(double value, int index);
    void multiply(double k);
    void display();
    ~MyVector();
private:
    double *data;           // the vector array
    int size;               // the vector size
};

//////////////////
MyVector::MyVector() {
    data = NULL;
    size = 0;
}

MyVector::MyVector(int size) {
    data = new double [size];
    this->size = size;
}

void MyVector::create(int size) {
    if(size)
    {
        delete [] data;
    }
    data = new double [size];
    this->size = size;
}

void MyVector::setValue(double value, int index) {
    if((index > 0 || index == 0) && index < size) data[index] = value;
}

void MyVector::multiply(double k) {
    for(int i = 0; i < size; i++)
    {
        data[i] *= k;
    }
}

void MyVector::display() {
    cout << "(";
    for(int i = 0; i < size; i++)
    {
        if(i == 0) cout << data[i];
        else cout << "," << data[i];
    }
    cout << ")\n";
}

MyVector::~MyVector() {
    delete data;
} 
