#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int rate[5], weight[4];

int Calweight(int w){
	if(w <= weight[1])
		return w*rate[1];
	else if(w <= weight[2])
		return w*rate[2];
	else if(w <= weight[3])
		return w*rate[3];
	else
		return w*rate[4];
}

int main()
{
	int num = 0;
	while(cin>>weight[1]>>rate[1])
	{
		cin >> weight[2] >> rate[2]
			>> weight[3] >> rate[3]
			>> rate[4];
		
		num++;
		int w;
		int cost, cost1, cost2, cost3;
		cout << "Set number " << num << ":" << endl; 
		while(cin>>w && w)
		{
			int pound = 0;
			if(w > weight[3])
			{
				cost = Calweight(w);
			}
			else if(w > weight[2])
			{
				cost = Calweight(w);
				cost1 = (weight[3]+1)*rate[4];
				if(cost1 < cost){
					cost = cost1;
					pound = weight[3]+1-w;
				}
			}
			else if(w > weight[1])
			{
				cost = Calweight(w);
				cost1 = (weight[2]+1)*rate[3];
				cost2 = (weight[3]+1)*rate[4];
				if(cost1 < cost){
					cost = cost1;
					pound = weight[2]+1-w;
				}
				if(cost2 < cost)
				{
					cost = cost2;
					pound = weight[3]+1-w;
				}
			}
			else{
				cost = Calweight(w);
				cost1 = (weight[1]+1)*rate[2];
				cost2 = (weight[2]+1)*rate[3];
				cost3 = (weight[3]+1)*rate[4];
				if(cost1 < cost)
				{
					cost = cost1;
					pound = weight[1]+1-w;
				}
				if(cost2 < cost)
				{
					cost = cost2;
					pound = weight[2]+1-w;
				}
				if(cost3 < cost)
				{
					cost = cost3;
					pound = weight[3]+1-w;
				}
			}
			cout << "Weight (" << w << ") has best price $" << cost
			<< " (add " << pound << " pounds)" << endl;	
		}
		cout << endl;
	}
}

