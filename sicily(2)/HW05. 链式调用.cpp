#include <iostream>

using namespace std;

class Number
{
public:
	Number(int );
    Number &add(int ); 
    Number &sub(int );
    void print();
private:
    int ans;
};

Number::Number(int n) {
	Number::ans = n;
}

Number &Number::add(int x) {
    ans += x;
    return *this;
}

Number &Number::sub(int x) {
    ans -= x;
    return *this;
}

void Number::print() {
	cout << ans << endl;
}
    
/********************s**²âÊÔ´úÂë**************************/ 
int main()
{
    Number n(1);
    n.add(2).sub(3).add(4);
    n.print();
    return 0;
}
