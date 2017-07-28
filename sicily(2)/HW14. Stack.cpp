#include <iostream>
using namespace std;

template <typename T, int capacity>
class Stack
{
public:
    Stack();                       // Constructs an empty stack.
    ~Stack();                      // Deconstructor
    bool empty();                  // Returns true if the stack is empty.
    T peek();                      // Returns the element at the top of the stack without removing it from the stack.
    void push(T value);            // Stores an element into the top of the stack.
    T pop();                       // Removes the element at the top of the stack and returns it.
    int size();                    // Returns the number of elements in the stack.
private:
    T* elements;                   // Points to an array that stores elements in the stack.
    int num;                       // The number of the elements in the stack.
};

template <typename T, int capacity>
Stack<T,capacity>::Stack()
{
	num = 0;
	elements = new T[capacity];
}

template <typename T, int capacity>
Stack<T,capacity>::~Stack()
{
	if(num) delete [] elements;
}
	
template <typename T, int capacity>
bool Stack<T,capacity>::empty()
{
	return num == 0;                                   // �ж�num�Ƿ�Ϊ0 
}
	
template <typename T, int capacity>
T Stack<T,capacity>::peek()
{
	if(!empty()) return elements[num-1];               // ����ջ��Ԫ�� 
}
	
template <typename T, int capacity>
void Stack<T,capacity>::push(T value)
{
	if(num != capacity) elements[num++] = value;        // Ԫ�ؽ�ջ 
}
	
template <typename T, int capacity>
T Stack<T,capacity>::pop()
{
	if(!empty()) 
	{
		return elements[--num];                          // ɾ��������ջ��Ԫ�� 
	}
}

template <typename T, int capacity>
int Stack<T,capacity>::size()
{
	return num;                                          // ����Ԫ�ظ��� 
}
	
int main()
{
	Stack<int,15> intStack;
	for (int i = 0; i < 15; i++) intStack.push(i);

	cout<<intStack.size()<<endl;
	while (!intStack.empty()) {
		cout << intStack.peek() << " ";
		intStack.pop();
	}
	cout << endl;
}
