#include <iostream>
using namespace std;

template <typename T, int capacity>
class Array
{
public:
	Array();                           // Construct an empty Array.
	~Array();                          // Deconstructor
	bool empty();                      // Return true if the array is empty.
	void push(T value);                // Push back an element into the array.
	T pop();                           // Remove the last element of the array and returns it.
	int size();                        // Return the number of elements in the array.
	T& operator[] (int index);         // Return the element by index.
private:
    T* elements;                       // Point to an array that stores elements.
    int num;                           // The number of the elements in the Array.
};

class ArrayException                   // 类的声明要放在前面 
{
public:
	ArrayException(const char *msg);
	const char *what() const;
private:
	const char *message;
};

template <typename T, int capacity>
Array< T, capacity >::Array()
{
	num = 0;
	elements = new T[capacity];
}

template <typename T, int capacity>
Array< T, capacity >::~Array()
{
	if(num) delete [] elements;
}

template <typename T, int capacity>
bool Array< T, capacity >::empty()
{
	return num == 0;
}

template <typename T, int capacity>
void Array< T, capacity >::push(T value)
{
	if(num == capacity) throw ArrayException("Array Full Exception");
	else elements[num++] = value;
}

template <typename T, int capacity>
T Array< T, capacity >::pop()
{
	if(num) return elements[--num];
	else throw ArrayException("Array Empty Exception");
}

template <typename T, int capacity>
int Array< T, capacity >::size()
{
	return num;
}

template <typename T, int capacity>
T& Array< T, capacity >::operator[] (int index)
{
	if(index >= 0 && index < num) return elements[index];
	else throw ArrayException("Out of Range Exception");
}

ArrayException::ArrayException(const char *msg)
{
	message = msg;
}

const char * ArrayException::what() const
{
	return message;
}

int main ()
{
	Array<int,1> intArray;
	try {
		intArray.push(1);
	}
	catch (ArrayException ex) {
		cout << ex.what() << endl;
	}
	try {
		cout << intArray[3] << endl;
	}
	catch (ArrayException ex) {
		cout << ex.what() << endl;
	}
	try {
		cout << intArray.pop() << endl;
	}
	catch (ArrayException ex) {
		cout << ex.what() << endl;
	}
}
