#include <cstdio>
class setfixed{	
};
class Myendl{
};
class Mypres{
public:
	void setpres(int x){
		pres = x;
	}
	int getpres(){
		return pres;
	}
private:
	int pres;
};

class setjz{
public:
	setjz(){}
	setjz(int val){
		value = val;
	}
	int getjz(){
		return value;
	}
private:
	int value;
};

class MyOutstream  
{  
public:
	MyOutstream(){
 		mypres_ = myfixed_ = 0;
 		jz = 10;
    }
    MyOutstream& operator<<(int value){           // 对整型变量的重载  
    	if (jz == 16) printf("%x", value);  
        else printf("%d",value);
		return *this;
	}
    MyOutstream& operator<<(const char* str){     // 对字符串型的重载 
		printf("%s", str);  
    	return *this;
	}
	MyOutstream& operator<<(char ch){             // 对字符型的重载 
		printf("%c", ch);  
        return *this;
	} 
	MyOutstream& operator<<(Myendl myendl){ 
		printf("\n");  
        return *this;
	} 
	MyOutstream& operator<<(setfixed myfixed){ 
		myfixed_ = 1;
        return *this;
	}  
	MyOutstream& operator<<(setjz ch){ 
	    jz = ch.getjz();
        return *this;
	} 
	MyOutstream& operator<<(Mypres mypres){ 
	    mypres_ = mypres.getpres();
        return *this;
	}
	MyOutstream& operator<<(double value){ 
    	if(myfixed) printf("%.*lf",mypres_,value);     // 保留小数位数 
		else printf("%.*g",mypres_,value);             // 保留精度 	
	}
private:
	int mypres_;
	int jz;
	int myfixed_;
};
 
Mypres pres_;

Mypres mypres(int x){
	pres_.setpres(x);
	return pres_;
}

MyOutstream myout;
Myendl myendl;
setfixed myfixed;
setjz myhex(16);

int main()
{
    const char *test1 = "Test char";
    myout << test1 << myendl;
    myout << test1[0]<< myendl;
        
    double e = 6.12345;
	int pres = 1;

    myout << mypres(pres*2);           //setprecision(2)
    myout << e << myendl;
    myout << myfixed ;
    myout << e << myendl;

    int d=15;
    myout << d << myendl;
    myout << myhex << d << myendl;
}
