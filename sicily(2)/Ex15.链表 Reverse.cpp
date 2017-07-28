/*
����һ�������Լ�����λ��m,n����Ҫ������λ��m��λ��n��Ԫ�ط�ת������������

��������Ϊ1->2->3->4->5��m��n�ֱ�Ϊ2,4����ô��Ӧ�÷�������1->4->3->2->5
*/
#include <stdio.h>
#include <algorithm>
#include <cstddef>
#include <vector>
using namespace std;
 
struct ListNode{
	int val;
	ListNode *next;
	ListNode():val(0), next(NULL){};
	ListNode(int val):val(val), next(NULL){}
};

ListNode* reverse(ListNode *head, int m, int n)
{
	vector<int>a;
	ListNode *k = head;
	a.push_back(head->val); 
	while(head->next)
	{
		head = head->next;
		a.push_back(head->val); 
	}
	reverse(a.begin()+m-1,a.end()-(a.size()-n));	
	k->val = a[0];
	head = k;
	for(int p=0;p<a.size();p++)
	{
		head->val = a[p];
		head = head->next;
	}
	head = k;
	return head;	
}
 
bool check(ListNode *head, int arr[], int size){
	for (int i = 0; i < size; i++){
		if (!head) return false;
		if (head->val != arr[i]) return false;
		head = head->next;
	}
	return true;
}
 
int main(){
	int size = rand() % 100000 + 1;
	int m = rand() % size + 1, n = rand() % size + 1;
	if (m > n) swap(n, m);
	ListNode *dummy = new ListNode(0);
	ListNode *prev = dummy;
	int arr[size + 1];
	for (int i = 0; i < size; i++){
		int val = rand() % 100000;
		arr[i] = val;
		ListNode *temp = new ListNode(val);
		prev->next = temp;
		prev = temp;
	}
 
	ListNode *head = reverse(dummy->next, m, n);
	reverse(arr + m - 1, arr + n);
	if (check(head, arr, size)){
		puts("YES");
	} else{
		puts("NO");
	}
	return 0;
}

