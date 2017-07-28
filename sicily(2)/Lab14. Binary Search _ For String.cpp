#include <string>
#include <cstring>

bool operator > (const string s1, const string s2)
{
	// s1 > s2 ²»ÅĞ¶Ï´óĞ¡Ğ´ 
	int len1 = s1.length();
	int len2 = s2.length();
	int len = min(len1,len2);
	
	for(int i = 0; i < len; i++)
	{
		if(s1[i] > s2[i]) return true;
		else if(s1[i] < s2[i]) return false;
		else continue;
	}
	if(len1 > len2) return true;
	else return false;
}

int binarySearch(string array[], string key, int arraySize){
	int start = 0, end = arraySize, mid;
    while (start <= end) {
        mid = (start + end)/2;
        if (key > array[mid]) {
            start = mid+1;
            continue;
        }
		else if (key < array[mid]){
            end = mid-1;
            continue;
        }
		else return mid;
    }
    return -1;
} 
