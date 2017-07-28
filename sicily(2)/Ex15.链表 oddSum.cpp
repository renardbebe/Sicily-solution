/*
给出一个链表，每个节点有一个数值，你需要返回链表奇数位置的数值之和，位置从1开始计数。

例如链表为1->2->4->5->6你需要返回11
*/
#include <stdio.h>
#include <algorithm>
using namespace std;
 
struct ListNode{
	int val;
	ListNode *next;
	ListNode():val(0), next(NULL){};
	ListNode(int val):val(val), next(NULL){}
};
 
int oddSum(ListNode *head)
{
    if(head==NULL) return 0;
    else
    {
        int sum = 0;
        int cnt = 1;
        for(ListNode *curPtr = head;curPtr!=NULL;curPtr = curPtr -> next)
        {
            if(cnt%2==1) sum += curPtr->val;
            cnt++;
        }
        return sum;
    }
}
 
int main(){
	int size = rand() % 1000 + 1;
	ListNode *dummy = new ListNode(0);
	ListNode *prev = dummy;
	int middleValue = 0, sum = 0;
	for (int i = 1; i <= size; i++){
		int val = rand() % 100000;
		if (i % 2) sum += val;
		ListNode *temp = new ListNode(val);
		prev->next = temp;
		prev = temp;
	}
 
	if (sum == oddSum(dummy->next)){
		puts("YES");
	} else{
		puts("NO");
	}
	return 0;
}

