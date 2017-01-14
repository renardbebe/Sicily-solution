#include <bits/stdc++.h>
using namespace std;
#define SIZE 2005

struct Node {
	int num;
	int in;  // index of first put_in
	int out; // index of put_out
	Node *parent;
	Node() {
		num = in = out = 0;
		parent = NULL;
	}
	Node(const Node *n) {
		num = n->num;
		in = n->in;
		out = n->out;
		parent = n->parent;
	}
};

struct Stack{
	Node* node[SIZE];
	int cnt;
	Stack() {
		cnt = 0;
	}
	void push(Node *n) {
		node[cnt++] = n;
	}
	void pop() {
		cnt--;
	}
	bool empty() {
		return (cnt == 0);
	}
	Node* top() {
		return node[cnt-1];
	}
};

Node* find(Node *b, Node *p) {
	Node *tmp = b;
	while(tmp) {
		if(tmp == p) return tmp;
		else tmp = tmp->parent;
	}
}

int main () {
	int t, n, A, B;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		string str;
		cin >> str;
		scanf("%d%d", &A, &B);
		// build the tree
		Stack s;
		int cnt = 1;
		Node *a;  // first wormy apple
		Node *b;  // second wormy apple
		for(int i = 0; i < str.length(); i++) {
			if(str[i] == '0') {
				Node *p = new Node;
				p->num = cnt++;
				p->in = i+1;
				s.push(p);
				if(i == A-1) a = p;
				if(i == B-1) b = p;
			}
			else {
				Node *p = s.top();  // Ö±½ÓÌæ´ú!
				s.pop();
				p->out = i+1;
				if(!s.empty()) p->parent = s.top();
				else p->parent = NULL;
				if(i == A-1) a = p;
				if(i == B-1) b = p;
			}
		}
		// find the nearest ancestor
		while(a) {
			Node *tmp = find(b, a);
			if(tmp) {
				cout << tmp->in << " " << tmp->out << endl;
				break;
			}
			else a = a->parent;
		}
	}
}
