/*
给出一个链表，你需要返回链表中间元素的值。

例如链表元素为1->3->2，那么你需要返回3,如果链表是3->1->4->2，那么你需要返回1.
*/ 
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <cstddef>
using namespace std;
 
struct ListNode{
	int val;
	ListNode *next;
	ListNode():val(0), next(NULL){};
	ListNode(int val):val(val), next(NULL){}
};

int a[1000000];
int middleItem(ListNode *head)
{
	memset(a,0,sizeof(a));
	int l = 0;
	while(head)
	{	
		a[l] = head->val;
		l++;
		head = head->next;
	}
	return a[(l-1)/2];
}
 
int main(){
	int size = rand() % 100000 + 1;
	ListNode *dummy = new ListNode(0);
	ListNode *prev = dummy;
	int middleValue = 0;
	for (int i = 0; i < size; i++){
		int val = rand() % 100000;
		if (i == (size - 1) / 2) middleValue = val;
		ListNode *temp = new ListNode(val);
		prev->next = temp;
		prev = temp;
	}
 
	if (middleItem(dummy->next) == middleValue){
		puts("YES");
	} else{
		puts("NO");
	}
	return 0;
}

