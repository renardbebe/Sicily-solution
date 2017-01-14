#include <bits/stdc++.h>
using namespace std;

struct Node {
	char data;
	Node *left;
	Node *right;
	Node(char x) {
		data = x;
		left = NULL;
		right = NULL;
	}
};

string s1, s2;      // s1 -> postorder , s2 -> inorder 
int root_pos;

void build(Node *&root, int start, int end) {	
	if(start > end || root_pos >= s2.length()) return;
	
	root = new Node(s1[root_pos]);	
	int pos = s2.find(root->data);
	root_pos--;
	build(root->right,pos+1,end);
	build(root->left,start,pos-1);
}

int main () {
	int t;
	cin >> t;
	while(t--) {
		cin >> s1 >> s2;
		int len = s1.length();
		Node *root = new Node(s1[len-1]);
		root_pos = len-1;
		build(root,0,len-1);
		
		queue<Node*> q;
		q.push(root);
		while(!q.empty()) {
			cout << q.front()->data;
			if(q.front()->left) q.push(q.front()->left);
			if(q.front()->right) q.push(q.front()->right);
			q.pop();
		}
		cout << endl;
	}
}
