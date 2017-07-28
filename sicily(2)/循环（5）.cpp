// -- Exercise for Input and Output (5)
#include <iostream>
using namespace std;
int main ()
{
	int N;
	cin >> N;
	for(int i=0;i<N-1;i++){
		int M,sum=0;
		cin >> M;
		while(M>0){
			int a;
			cin >> a;
			sum=sum+a;
			M=M-1;
		}
		cout << sum << endl << endl;  
	}
	int m,sum=0;
	cin >> m;
	while(m>0){
		int a;
		cin >> a;
		sum=sum+a;
		m=m-1;
	}
	cout << sum << endl;
	return 0;
}
