#include <iostream>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;
 
char * convertDecimalToHex(int value)
{
	char *a = new char[100];
	sprintf(a,"%x",value);
	for(int i=0;i<strlen(a);i++) a[i] = toupper(a[i]);
	return a;
}

void convertDecimalToHex(int value, char *s)
{
	sprintf(s,"%x",value);
	for(int i=0;i<strlen(s);i++) s[i] = toupper(s[i]);
}
