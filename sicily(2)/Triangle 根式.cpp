// Problem#: 15101
// Submission#: 3840130
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <iomanip>
#include <cmath> 
using namespace std;
int main()
{
    double area,p,q;
    int a,b,c; 
    cin >> a >> b >> c;
    p=(a+b+c)/2;
    q=p*(p-a)*(p-b)*(p-c);
    area=sqrt(q);
    cout << fixed << setprecision(2) << area;
    cout << endl;
    return 0;
}      
