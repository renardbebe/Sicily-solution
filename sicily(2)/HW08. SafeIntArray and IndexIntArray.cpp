#include <iostream>
#include <cstdio>
#include <cstring>
 
using namespace std;
 
///////////////////////////////////////////////////////////////////////////////////////////////////

class SafeIntArray         // 基类 
{
public:
	SafeIntArray();
	SafeIntArray(int );
	~SafeIntArray();
	int get(int ) const;
	void set(int , int );
	int size;
	int *ptr;
};

SafeIntArray::SafeIntArray()
{
	size = 0;
	ptr = NULL;
}

SafeIntArray::SafeIntArray(int size)
{
	this->size = size;
	ptr = new int [size];
	for(int i = 0; i < size; i++) ptr[i] = 0;
}

SafeIntArray::~SafeIntArray()
{
	if(size) delete [] ptr;
}

int SafeIntArray::get(int i) const
{
	if(i < 0 || i >= size)
	{
		cout << "Outside the boundary!\n";
		return -1;
	}
	return ptr[i];
}

void SafeIntArray::set(int i, int value)
{
	if(i < 0 || i >= size)
	{
		cout << "Outside the boundary!\n";
		return;
	}
	ptr[i] = value;
}

class IndexIntArray : public SafeIntArray         // 表明继承关系 
{
public:
	IndexIntArray();
	IndexIntArray(int ,int );
	int get(int ) const;
	void set(int , int );
private:
	int begin;
	int end;
};

IndexIntArray::IndexIntArray()
{
	begin = 0;
	end = 0;
	ptr = NULL;
}

IndexIntArray::IndexIntArray(int a,int b)
{
	begin = a;
	end = b;
	size = end - begin + 1;
	if(ptr) delete [] ptr;
	ptr = new int [size];
	for(int i = 0; i < size; i++) ptr[i] = 0;
}

int IndexIntArray::get(int i) const
{
	return SafeIntArray::get(i-begin);
}

void IndexIntArray::set(int i, int value)
{
	SafeIntArray::set(i-begin, value);
}
 
int main(int argc, char** argv) {
    
    int test;
    cin >> test;
    while (test --) {
        int size, n;
        cin >> size;
        SafeIntArray sia(size);
        // test SafeIntArray::set(int,int) of SafeIntArray
        cin >> n;
        while (n --) {
            int index, data;
            cin >> index >> data;
            sia.set(index, data);
        }
        // test SafeIntArray::get(int) of SafeIntArray
        cin >> n;
        while (n --) {
            int index;
            cin >> index;
            int value = sia.get(index);
            if (value != -1) {
                cout << value << endl;
            }
        }
 
        int begin, end;
        cin >> begin >> end;
        IndexIntArray iia(begin, end);
        // test IndexIntArray::set(int,int) of IndexIntArray
        cin >> n;
        while (n --) {
            int index, data;
            cin >> index >> data;
            iia.set(index, data);
        }
        // test IndexIntArray::get(int) of IndexIntArray
        cin >> n;
        while (n --) {
            int index;
            cin >> index;
            int value = iia.get(index);
            if (value != -1) {
                cout << value << endl;
            }
        }
    }
    return 0;
}

