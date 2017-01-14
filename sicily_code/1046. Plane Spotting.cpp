/*
 * 题目大意： 
 *       给出一个长度为N的非负整数序列（所有数不超过200），还有两个整数M和K，求前M个最优的长度不小于K的连续子序列。 
 *       连续子序列的优先级如何比较 ?
 *       1、平均值大的序列优于平均值小的 
 *       2、条件1相同情况下，长度大的序列优于长度小的 
 *       3、条件1和2相同情况下，结束位置靠前的序列优于结束位置靠后的 
 *       1≤N≤300，1≤M≤100，1≤K≤300 
 *
 */
#include <bits/stdc++.h>
using namespace std;

class Period{	
public:
	Period() {
		start = 0;
		end = 0;
		average = 0.0;
	}
	int start;
	int end;
	double average;
};

Period p[100001];

bool operator < (const Period &a, const Period &b) {
	int len1 = a.end - a.start;
	int len2 = b.end - b.start;
	if(a.average != b.average ) return a.average > b.average;
	else if(len1 != len2) return len1 > len2;
	else return a.end < b.end;
}

int main () {
	int T, n, best, mini;
	cin >> T;
	for(int kase = 1; kase <= T; kase++) {
		cout << "Result for run " << kase << ":\n";
		int plane[301];
		cin >> n >> best >> mini;
		for(int i = 0; i < n; i++) cin >> plane[i];
		
		int cnt = 0;
		for(int i = mini; i <= n; i++){          
            for(int j = 0; j+i <= n; j++){  
                double sum = 0;  
                for(int k = j ; k-j < i; k++){  
                    sum += plane[k];  
                }  
                p[cnt].start = j+1;
                p[cnt].end = j+i;  
                p[cnt].average = sum/i;
                cnt++; 
            }                    
        }
		sort(p,p+cnt);
		for(int i = 0; i < best && i < cnt; i++) {
			cout << p[i].start << "-" << p[i].end << endl; 
		}
	}
}
