// 循环控制输出空格和换行 ? 
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;
int main ()
{
	int year,firstday,month,k;
	while(cin >> year >> firstday >> month)   // 2005 6 3
	{
		if(year%4==0&&year%100!=0||year%400==0)
		{
			switch(month)
			{
				case 1: k = firstday; 
						cout << "January " << year << endl;
						cout << setw(8) << setiosflags(ios::right) << "Sun" << setw(8) << setiosflags(ios::right) << "Mon" << setw(8) << setiosflags(ios::right) << "Tue" << setw(8) << setiosflags(ios::right) << "Wed" << setw(8) << setiosflags(ios::right) << "Thu" << setw(8) << setiosflags(ios::right) << "Fri" << setw(8) << setiosflags(ios::right) << "Sat" << endl;
						for(int i=k;i>0;i--)
						{
							cout << setw(8) << setiosflags(ios::right) << " ";
						}
						for(int i=k,j=1;i<=6,j<=31;i++,j++)
						{
							if(i==6||i==13||i==20||i==27||i==34&&j!=31) cout << setw(8) << setiosflags(ios::right) << j << endl;
							else cout << setw(8) << setiosflags(ios::right) << j;
						}
						cout << endl;
				break;	
				
				case 2: k = (firstday+3)%7; 
						cout << "February " << year << endl;
						cout << setw(8) << setiosflags(ios::right) << "Sun" << setw(8) << setiosflags(ios::right) << "Mon" << setw(8) << setiosflags(ios::right) << "Tue" << setw(8) << setiosflags(ios::right) << "Wed" << setw(8) << setiosflags(ios::right) << "Thu" << setw(8) << setiosflags(ios::right) << "Fri" << setw(8) << setiosflags(ios::right) << "Sat" << endl;
						for(int i=k;i>0;i--)
						{
							cout << setw(8) << setiosflags(ios::right) << " ";
						}
						for(int i=k,j=1;i<=6,j<=29;i++,j++)
						{
							if(i==6||i==13||i==20||(i==27&&j!=29)||i==34&&j!=29) cout << setw(8) << setiosflags(ios::right) << j << endl;
							else cout << setw(8) << setiosflags(ios::right) << j;
						}
						cout << endl;
				break;	
				
				case 3: k = (firstday+4)%7 ; 
						cout << "March " << year << endl;
						cout << setw(8) << setiosflags(ios::right) << "Sun" << setw(8) << setiosflags(ios::right) << "Mon" << setw(8) << setiosflags(ios::right) << "Tue" << setw(8) << setiosflags(ios::right) << "Wed" << setw(8) << setiosflags(ios::right) << "Thu" << setw(8) << setiosflags(ios::right) << "Fri" << setw(8) << setiosflags(ios::right) << "Sat" << endl;
						for(int i=k;i>0;i--)
						{
							cout << setw(8) << setiosflags(ios::right) << " ";
						}
						for(int i=k,j=1;i<=6,j<=31;i++,j++)
						{
							if(i==6||i==13||i==20||i==27||i==34&&j!=31) cout << setw(8) << setiosflags(ios::right) << j << endl;
							else cout << setw(8) << setiosflags(ios::right) << j;
						}
						cout << endl;
				break;	
				
				case 4: k = (firstday+7)%7 ; 
						cout << "April " << year << endl;
						cout << setw(8) << setiosflags(ios::right) << "Sun" << setw(8) << setiosflags(ios::right) << "Mon" << setw(8) << setiosflags(ios::right) << "Tue" << setw(8) << setiosflags(ios::right) << "Wed" << setw(8) << setiosflags(ios::right) << "Thu" << setw(8) << setiosflags(ios::right) << "Fri" << setw(8) << setiosflags(ios::right) << "Sat" << endl;
						for(int i=k;i>0;i--)
						{
							cout << setw(8) << setiosflags(ios::right) << " ";
						}
						for(int i=k,j=1;i<=6,j<=30;i++,j++)
						{
							if(i==6||i==13||i==20||i==27||i==34&&j!=30) cout << setw(8) << setiosflags(ios::right) << j << endl;
							else cout << setw(8) << setiosflags(ios::right) << j;
						}
						cout << endl;
				break;	
				
				case 5: k = (firstday+2)%7 ; 
						cout << "May " << year << endl;
						cout << setw(8) << setiosflags(ios::right) << "Sun" << setw(8) << setiosflags(ios::right) << "Mon" << setw(8) << setiosflags(ios::right) << "Tue" << setw(8) << setiosflags(ios::right) << "Wed" << setw(8) << setiosflags(ios::right) << "Thu" << setw(8) << setiosflags(ios::right) << "Fri" << setw(8) << setiosflags(ios::right) << "Sat" << endl;
						for(int i=k;i>0;i--)
						{
							cout << setw(8) << setiosflags(ios::right) << " ";
						}
						for(int i=k,j=1;i<=6,j<=31;i++,j++)
						{
							if(i==6||i==13||i==20||i==27||i==34&&j!=31) cout << setw(8) << setiosflags(ios::right) << j << endl;
							else cout << setw(8) << setiosflags(ios::right) << j;
						}
						cout << endl;
				break;	
				
				case 6: k = (firstday+5)%7 ; 
						cout << "June " << year << endl;
						cout << setw(8) << setiosflags(ios::right) << "Sun" << setw(8) << setiosflags(ios::right) << "Mon" << setw(8) << setiosflags(ios::right) << "Tue" << setw(8) << setiosflags(ios::right) << "Wed" << setw(8) << setiosflags(ios::right) << "Thu" << setw(8) << setiosflags(ios::right) << "Fri" << setw(8) << setiosflags(ios::right) << "Sat" << endl;
						for(int i=k;i>0;i--)
						{
							cout << setw(8) << setiosflags(ios::right) << " ";
						}
						for(int i=k,j=1;i<=6,j<=30;i++,j++)
						{
							if(i==6||i==13||i==20||i==27||i==34&&j!=30) cout << setw(8) << setiosflags(ios::right) << j << endl;
							else cout << setw(8) << setiosflags(ios::right) << j;
						}
						cout << endl;
				break;	
				
				case 7: k = (firstday+7)%7 ; 
						cout << "July " << year << endl;
						cout << setw(8) << setiosflags(ios::right) << "Sun" << setw(8) << setiosflags(ios::right) << "Mon" << setw(8) << setiosflags(ios::right) << "Tue" << setw(8) << setiosflags(ios::right) << "Wed" << setw(8) << setiosflags(ios::right) << "Thu" << setw(8) << setiosflags(ios::right) << "Fri" << setw(8) << setiosflags(ios::right) << "Sat" << endl;
						for(int i=k;i>0;i--)
						{
							cout << setw(8) << setiosflags(ios::right) << " ";
						}
						for(int i=k,j=1;i<=6,j<=31;i++,j++)
						{
							if(i==6||i==13||i==20||i==27||i==34&&j!=31) cout << setw(8) << setiosflags(ios::right) << j << endl;
							else cout << setw(8) << setiosflags(ios::right) << j;
						}
						cout << endl;
				break;	
				
				case 8: k = (firstday+3)%7 ; 
						cout << "August " << year << endl;
						cout << setw(8) << setiosflags(ios::right) << "Sun" << setw(8) << setiosflags(ios::right) << "Mon" << setw(8) << setiosflags(ios::right) << "Tue" << setw(8) << setiosflags(ios::right) << "Wed" << setw(8) << setiosflags(ios::right) << "Thu" << setw(8) << setiosflags(ios::right) << "Fri" << setw(8) << setiosflags(ios::right) << "Sat" << endl;
						for(int i=k;i>0;i--)
						{
							cout << setw(8) << setiosflags(ios::right) << " ";
						}
						for(int i=k,j=1;i<=6,j<=31;i++,j++)
						{
							if(i==6||i==13||i==20||i==27||i==34&&j!=31) cout << setw(8) << setiosflags(ios::right) << j << endl;
							else cout << setw(8) << setiosflags(ios::right) << j;
						}
						cout << endl;
				break;	
				
				case 9: k = (firstday+6)%7 ; 
						cout << "September " << year << endl;
						cout << setw(8) << setiosflags(ios::right) << "Sun" << setw(8) << setiosflags(ios::right) << "Mon" << setw(8) << setiosflags(ios::right) << "Tue" << setw(8) << setiosflags(ios::right) << "Wed" << setw(8) << setiosflags(ios::right) << "Thu" << setw(8) << setiosflags(ios::right) << "Fri" << setw(8) << setiosflags(ios::right) << "Sat" << endl;
						for(int i=k;i>0;i--)
						{
							cout << setw(8) << setiosflags(ios::right) << " ";
						}
						for(int i=k,j=1;i<=6,j<=30;i++,j++)
						{
							if(i==6||i==13||i==20||i==27||i==34&&j!=30) cout << setw(8) << setiosflags(ios::right) << j << endl;
							else cout << setw(8) << setiosflags(ios::right) << j;
						}
						cout << endl;
				break;	
				
				case 10: k = (firstday+1)%7 ; 
						cout << "October " << year << endl;
						cout << setw(8) << setiosflags(ios::right) << "Sun" << setw(8) << setiosflags(ios::right) << "Mon" << setw(8) << setiosflags(ios::right) << "Tue" << setw(8) << setiosflags(ios::right) << "Wed" << setw(8) << setiosflags(ios::right) << "Thu" << setw(8) << setiosflags(ios::right) << "Fri" << setw(8) << setiosflags(ios::right) << "Sat" << endl;
						for(int i=k;i>0;i--)
						{
							cout << setw(8) << setiosflags(ios::right) << " ";
						}
						for(int i=k,j=1;i<=6,j<=31;i++,j++)
						{
							if(i==6||i==13||i==20||i==27||i==34&&j!=31) cout << setw(8) << setiosflags(ios::right) << j << endl;
							else cout << setw(8) << setiosflags(ios::right) << j;
						}
						cout << endl;
				break;	
				
				case 11: k = (firstday+4)%7 ; 
						cout << "November " << year << endl;
						cout << setw(8) << setiosflags(ios::right) << "Sun" << setw(8) << setiosflags(ios::right) << "Mon" << setw(8) << setiosflags(ios::right) << "Tue" << setw(8) << setiosflags(ios::right) << "Wed" << setw(8) << setiosflags(ios::right) << "Thu" << setw(8) << setiosflags(ios::right) << "Fri" << setw(8) << setiosflags(ios::right) << "Sat" << endl;
						for(int i=k;i>0;i--)
						{
							cout << setw(8) << setiosflags(ios::right) << " ";
						}
						for(int i=k,j=1;i<=6,j<=30;i++,j++)
						{
							if(i==6||i==13||i==20||i==27||i==34&&j!=30) cout << setw(8) << setiosflags(ios::right) << j << endl;
							else cout << setw(8) << setiosflags(ios::right) << j;
						}
						cout << endl;
				break;	
				
				case 12: k = (firstday+6)%7 ; 
						cout << "December " << year << endl;
						cout << setw(8) << setiosflags(ios::right) << "Sun" << setw(8) << setiosflags(ios::right) << "Mon" << setw(8) << setiosflags(ios::right) << "Tue" << setw(8) << setiosflags(ios::right) << "Wed" << setw(8) << setiosflags(ios::right) << "Thu" << setw(8) << setiosflags(ios::right) << "Fri" << setw(8) << setiosflags(ios::right) << "Sat" << endl;
						for(int i=k;i>0;i--)
						{
							cout << setw(8) << setiosflags(ios::right) << " ";
						}
						for(int i=k,j=1;i<=6,j<=31;i++,j++)
						{
							if(i==6||i==13||i==20||i==27||i==34&&j!=31) cout << setw(8) << setiosflags(ios::right) << j << endl;
							else cout << setw(8) << setiosflags(ios::right) << j;
						}
						cout << endl;
				break;	
			}
		}
		
		else 
		{
			switch(month)
			{
				case 1: k = firstday; 
						cout << "January " << year << endl;
						cout << setw(8) << setiosflags(ios::right) << "Sun" << setw(8) << setiosflags(ios::right) << "Mon" << setw(8) << setiosflags(ios::right) << "Tue" << setw(8) << setiosflags(ios::right) << "Wed" << setw(8) << setiosflags(ios::right) << "Thu" << setw(8) << setiosflags(ios::right) << "Fri" << setw(8) << setiosflags(ios::right) << "Sat" << endl;
						for(int i=k;i>0;i--)
						{
							cout << setw(8) << setiosflags(ios::right) << " ";
						}
						for(int i=k,j=1;i<=6,j<=31;i++,j++)
						{
							if(i==6||i==13||i==20||i==27||i==34&&j!=31) cout << setw(8) << setiosflags(ios::right) << j << endl;
							else cout << setw(8) << setiosflags(ios::right) << j;
						}
						cout << endl;
				break;	
				
				case 2: k = (firstday+3)%7; 
						cout << "February " << year << endl;
						cout << setw(8) << setiosflags(ios::right) << "Sun" << setw(8) << setiosflags(ios::right) << "Mon" << setw(8) << setiosflags(ios::right) << "Tue" << setw(8) << setiosflags(ios::right) << "Wed" << setw(8) << setiosflags(ios::right) << "Thu" << setw(8) << setiosflags(ios::right) << "Fri" << setw(8) << setiosflags(ios::right) << "Sat" << endl;
						for(int i=k;i>0;i--)
						{
							cout << setw(8) << setiosflags(ios::right) << " ";
						}
						for(int i=k,j=1;i<=6,j<=28;i++,j++)
						{
							if(i==6||i==13||i==20||(i==27&&j!=28)||i==34&&j!=28) cout << setw(8) << setiosflags(ios::right) << j << endl;
							else cout << setw(8) << setiosflags(ios::right) << j;
						}
						cout << endl;
				break;	
				
				case 3: k = (firstday+3)%7 ; 
						cout << "March " << year << endl;
						cout << setw(8) << setiosflags(ios::right) << "Sun" << setw(8) << setiosflags(ios::right) << "Mon" << setw(8) << setiosflags(ios::right) << "Tue" << setw(8) << setiosflags(ios::right) << "Wed" << setw(8) << setiosflags(ios::right) << "Thu" << setw(8) << setiosflags(ios::right) << "Fri" << setw(8) << setiosflags(ios::right) << "Sat" << endl;
						for(int i=k;i>0;i--)
						{
							cout << setw(8) << setiosflags(ios::right) << " ";
						}
						for(int i=k,j=1;i<=6,j<=31;i++,j++)
						{
							if(i==6||i==13||i==20||i==27||i==34&&j!=31) cout << setw(8) << setiosflags(ios::right) << j << endl;
							else cout << setw(8) << setiosflags(ios::right) << j;
						}
						cout << endl;
				break;	
				
				case 4: k = (firstday+6)%7 ; 
						cout << "April " << year << endl;
						cout << setw(8) << setiosflags(ios::right) << "Sun" << setw(8) << setiosflags(ios::right) << "Mon" << setw(8) << setiosflags(ios::right) << "Tue" << setw(8) << setiosflags(ios::right) << "Wed" << setw(8) << setiosflags(ios::right) << "Thu" << setw(8) << setiosflags(ios::right) << "Fri" << setw(8) << setiosflags(ios::right) << "Sat" << endl;
						for(int i=k;i>0;i--)
						{
							cout << setw(8) << setiosflags(ios::right) << " ";
						}
						for(int i=k,j=1;i<=6,j<=30;i++,j++)
						{
							if(i==6||i==13||i==20||i==27||i==34&&j!=30) cout << setw(8) << setiosflags(ios::right) << j << endl;
							else cout << setw(8) << setiosflags(ios::right) << j;
						}
						cout << endl;
				break;	
				
				case 5: k = (firstday+1)%7 ; 
						cout << "May " << year << endl;
						cout << setw(8) << setiosflags(ios::right) << "Sun" << setw(8) << setiosflags(ios::right) << "Mon" << setw(8) << setiosflags(ios::right) << "Tue" << setw(8) << setiosflags(ios::right) << "Wed" << setw(8) << setiosflags(ios::right) << "Thu" << setw(8) << setiosflags(ios::right) << "Fri" << setw(8) << setiosflags(ios::right) << "Sat" << endl;
						for(int i=k;i>0;i--)
						{
							cout << setw(8) << setiosflags(ios::right) << " ";
						}
						for(int i=k,j=1;i<=6,j<=31;i++,j++)
						{
							if(i==6||i==13||i==20||i==27||i==34&&j!=31) cout << setw(8) << setiosflags(ios::right) << j << endl;
							else cout << setw(8) << setiosflags(ios::right) << j;
						}
						cout << endl;
				break;	
				
				case 6: k = (firstday+4)%7 ; 
						cout << "June " << year << endl;
						cout << setw(8) << setiosflags(ios::right) << "Sun" << setw(8) << setiosflags(ios::right) << "Mon" << setw(8) << setiosflags(ios::right) << "Tue" << setw(8) << setiosflags(ios::right) << "Wed" << setw(8) << setiosflags(ios::right) << "Thu" << setw(8) << setiosflags(ios::right) << "Fri" << setw(8) << setiosflags(ios::right) << "Sat" << endl;
						for(int i=k;i>0;i--)
						{
							cout << setw(8) << setiosflags(ios::right) << " ";
						}
						for(int i=k,j=1;i<=6,j<=30;i++,j++)
						{
							if(i==6||i==13||i==20||i==27||i==34&&j!=30) cout << setw(8) << setiosflags(ios::right) << j << endl;
							else cout << setw(8) << setiosflags(ios::right) << j;
						}
						cout << endl;
				break;	
				
				case 7: k = (firstday+6)%7 ; 
						cout << "July " << year << endl;
						cout << setw(8) << setiosflags(ios::right) << "Sun" << setw(8) << setiosflags(ios::right) << "Mon" << setw(8) << setiosflags(ios::right) << "Tue" << setw(8) << setiosflags(ios::right) << "Wed" << setw(8) << setiosflags(ios::right) << "Thu" << setw(8) << setiosflags(ios::right) << "Fri" << setw(8) << setiosflags(ios::right) << "Sat" << endl;
						for(int i=k;i>0;i--)
						{
							cout << setw(8) << setiosflags(ios::right) << " ";
						}
						for(int i=k,j=1;i<=6,j<=31;i++,j++)
						{
							if(i==6||i==13||i==20||i==27||i==34&&j!=31) cout << setw(8) << setiosflags(ios::right) << j << endl;
							else cout << setw(8) << setiosflags(ios::right) << j;
						}
						cout << endl;
				break;	
				
				case 8: k = (firstday+2)%7 ; 
						cout << "August " << year << endl;
						cout << setw(8) << setiosflags(ios::right) << "Sun" << setw(8) << setiosflags(ios::right) << "Mon" << setw(8) << setiosflags(ios::right) << "Tue" << setw(8) << setiosflags(ios::right) << "Wed" << setw(8) << setiosflags(ios::right) << "Thu" << setw(8) << setiosflags(ios::right) << "Fri" << setw(8) << setiosflags(ios::right) << "Sat" << endl;
						for(int i=k;i>0;i--)
						{
							cout << setw(8) << setiosflags(ios::right) << " ";
						}
						for(int i=k,j=1;i<=6,j<=31;i++,j++)
						{
							if(i==6||i==13||i==20||i==27||i==34&&j!=31) cout << setw(8) << setiosflags(ios::right) << j << endl;
							else cout << setw(8) << setiosflags(ios::right) << j;
						}
						cout << endl;
				break;	
				
				case 9: k = (firstday+5)%7 ; 
						cout << "September " << year << endl;
						cout << setw(8) << setiosflags(ios::right) << "Sun" << setw(8) << setiosflags(ios::right) << "Mon" << setw(8) << setiosflags(ios::right) << "Tue" << setw(8) << setiosflags(ios::right) << "Wed" << setw(8) << setiosflags(ios::right) << "Thu" << setw(8) << setiosflags(ios::right) << "Fri" << setw(8) << setiosflags(ios::right) << "Sat" << endl;
						for(int i=k;i>0;i--)
						{
							cout << setw(8) << setiosflags(ios::right) << " ";
						}
						for(int i=k,j=1;i<=6,j<=30;i++,j++)
						{
							if(i==6||i==13||i==20||i==27||i==34&&j!=30) cout << setw(8) << setiosflags(ios::right) << j << endl;
							else cout << setw(8) << setiosflags(ios::right) << j;
						}
						cout << endl;
				break;	
				
				case 10: k = firstday%7 ; 
						cout << "October " << year << endl;
						cout << setw(8) << setiosflags(ios::right) << "Sun" << setw(8) << setiosflags(ios::right) << "Mon" << setw(8) << setiosflags(ios::right) << "Tue" << setw(8) << setiosflags(ios::right) << "Wed" << setw(8) << setiosflags(ios::right) << "Thu" << setw(8) << setiosflags(ios::right) << "Fri" << setw(8) << setiosflags(ios::right) << "Sat" << endl;
						for(int i=k;i>0;i--)
						{
							cout << setw(8) << setiosflags(ios::right) << " ";
						}
						for(int i=k,j=1;i<=6,j<=31;i++,j++)
						{
							if(i==6||i==13||i==20||i==27||i==34&&j!=31) cout << setw(8) << setiosflags(ios::right) << j << endl;
							else cout << setw(8) << setiosflags(ios::right) << j;
						}
						cout << endl;
				break;	
				
				case 11: k = (firstday+3)%7 ; 
						cout << "November " << year << endl;
						cout << setw(8) << setiosflags(ios::right) << "Sun" << setw(8) << setiosflags(ios::right) << "Mon" << setw(8) << setiosflags(ios::right) << "Tue" << setw(8) << setiosflags(ios::right) << "Wed" << setw(8) << setiosflags(ios::right) << "Thu" << setw(8) << setiosflags(ios::right) << "Fri" << setw(8) << setiosflags(ios::right) << "Sat" << endl;
						for(int i=k;i>0;i--)
						{
							cout << setw(8) << setiosflags(ios::right) << " ";
						}
						for(int i=k,j=1;i<=6,j<=30;i++,j++)
						{
							if(i==6||i==13||i==20||i==27||i==34&&j!=30) cout << setw(8) << setiosflags(ios::right) << j << endl;
							else cout << setw(8) << setiosflags(ios::right) << j;
						}
						cout << endl;
				break;	
				
				case 12: k = (firstday+5)%7 ; 
						cout << "December " << year << endl;
						cout << setw(8) << setiosflags(ios::right) << "Sun" << setw(8) << setiosflags(ios::right) << "Mon" << setw(8) << setiosflags(ios::right) << "Tue" << setw(8) << setiosflags(ios::right) << "Wed" << setw(8) << setiosflags(ios::right) << "Thu" << setw(8) << setiosflags(ios::right) << "Fri" << setw(8) << setiosflags(ios::right) << "Sat" << endl;
						for(int i=k;i>0;i--)
						{
							cout << setw(8) << setiosflags(ios::right) << " ";
						}
						for(int i=k,j=1;i<=6,j<=31;i++,j++)
						{
							if(i==6||i==13||i==20||i==27||i==34&&j!=31) cout << setw(8) << setiosflags(ios::right) << j << endl;
							else cout << setw(8) << setiosflags(ios::right) << j;
						}
						cout << endl;
				break;	
			}
		}	
	}
}
