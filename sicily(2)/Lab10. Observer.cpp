#include <iostream>
#include <vector>
using namespace std;

const int maxObserver = 10;

class Observer
{
public:
	virtual ~Observer() {}
	virtual void notify() = 0;
};

class Subject
{
public:
	Subject();
	//add observer to observerList
	void addObserver(Observer *observer);
	//remove observer from observerList
	void removeObserver(Observer *observer);
	//send subject changed message
	void change();
private:
	Observer* observerList[maxObserver];    // 在定义时已经开辟了空间 
	int numObserver;
};

Subject::Subject()
{
	numObserver = 0;
}

void Subject::addObserver(Observer *observer)
{
	observerList[numObserver] = observer;
	numObserver++;
}

void Subject::removeObserver(Observer *observer)
{
	int pos = 0;
	for(int i = 0; i < maxObserver; i++)
	{
		if(observerList[i] == observer)
		{
			pos = i;
			break;
		}
	}
	for(int i = pos; i < maxObserver; i++)
	{
		observerList[i] = observerList[i+1];
		if(i == maxObserver-1) observerList[i] = NULL;
	}
	numObserver--;
}

void Subject::change()
{
	for(int i = 0; i < numObserver; i++)
	{
		observerList[i]->notify();
	}
}

class ObserverA : public Observer
{
public:
	ObserverA()
	{
		x = NULL;
	}
	~ObserverA()
	{
		delete x;
	} 
	void notify();
private:
	Observer * x;
};

void ObserverA::notify()
{
	cout << "ObserverA is notified that Subject changed.\n";
}

class ObserverB : public Observer
{
public:
	ObserverB()
	{
		y = NULL;
	}
	~ObserverB()
	{
		delete y;
	}
	void notify();
private:
	Observer * y;
};

void ObserverB::notify()
{
	cout << "ObserverB is notified that Subject changed.\n";
}

/////////////////////////////////////////////////////////////
int main(int argc, char *argv[])
{
	ObserverA a;
	ObserverB b;

	Subject subject;
	subject.addObserver(&a);
	subject.addObserver(&b);
	subject.change();
	
	return 0;
}
