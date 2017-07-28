#include <iostream> 
#include <iomanip> 
using namespace std; 
int main () 
{ 
    double R,area;    
cin >> R;    
double PI=3.14159265358979;  
area=PI*R*R;     
cout << fixed << setprecision(8) << area << endl;   
return 0; 
}
