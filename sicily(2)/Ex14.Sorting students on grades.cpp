#include <iostream>
#include <algorithm>
using namespace std;

const int size = 101; 

struct{ 
    int number; 
    int right; 
    char ans[11];
}student[size];

char key[11];

int main ()
{
	int t;
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		int n;
		cin>>n;
		for(int p=0;p<n;p++)
		{
			student[p].right = 0;
		}
		for(int p=0;p<n;p++)
		{
			student[p].number = p;
			for(int i=0;i<10;i++)
			{
				cin>>student[p].ans[i];
			}
		}
		for(int i=0;i<10;i++)
		{
			cin>>key[i];
		}
		for(int p=0;p<n;p++)
		{
			for(int i=0;i<10;i++)
			{
				if(student[p].ans[i] == key[i])
				{
					student[p].right++;
				}
			}
		}
		
		for(int i=0;i<n;i++)
		{
			for(int j=i;j<n;j++)
			{
				if(student[i].right>student[j].right)
				{
					swap(student[i].number,student[j].number);
					swap(student[i].right,student[j].right);
				}
			}
		}
		
		cout << "test case " << k << ":\n";
		for(int i=0;i<n;i++)
		{
			cout << "Student " << student[i].number << ": " << student[i].right << endl;
		}
	}
}

/*
2
3
A B A C C D E E A D
D B D C C D A E A D
E D D A C B E E A D
D B D C C D A E A D
2
B B E C C D E E A D
A B D C C D E E A D
A B D C C D E E B D

*/
