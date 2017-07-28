#include <iostream>
#include <set>
using namespace std;

class SetOperation
{
public:
	SetOperation(){
		setA.clear();
		setB.clear();
		s1.clear();
	}
	SetOperation(int *a, int size1, int *b, int size2){
		for(int i = 0; i < size1; i++)
		{
			setA.insert(a[i]); 
		}
		for(int i = 0; i < size2; i++)
		{
			setB.insert(b[i]); 
		}
	}
	set<int> Union(){                                    // 求并集 
		s1.clear();
		for(set<int>::iterator it = setA.begin(); it != setA.end(); it++) s1.insert(*it);
		for(set<int>::iterator it = setB.begin(); it != setB.end(); it++)
		{
			if(s1.count(*it) == 0) s1.insert(*it);
		}
		return s1; 
	}
	set<int> Intersetion(){                             // 求交集 
		s1.clear();
		for(set<int>::iterator it1 = setA.begin(); it1 != setA.end(); it1++)
		{
			for(set<int>::iterator it2 = setB.begin(); it2 != setB.end(); it2++)
			{
				if(*it1 == *it2)
				{
					s1.insert(*it1);
					break; 
				}
			}
		}
		return s1; 
	}
private:
	set<int> s1;
	set<int> setA;
	set<int> setB;
};

void printSet(const set<int> &s) {                                // 遍历输出 
    bool first = true;                                            // 用于判断是否为开头 
    for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
        if (!first) cout << " ";
        else first = false;
        cout << *it;                                              // 输出迭代器的值 
    }
	cout << endl;
} 

int main(int argc, char *argv[]) {
	int a[9] = {8, 7, 5, 3, 1, 4, 6, 9, 10};
	int b[5] = {1, 2, 3, 5, 4};
	SetOperation s1(a, 9, b, 5);
	printSet(s1.Union());
	printSet(s1.Intersetion());
	return 0;
}
