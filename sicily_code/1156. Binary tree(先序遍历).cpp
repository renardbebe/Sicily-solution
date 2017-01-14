#include <bits/stdc++.h>
using namespace std;

struct Node {
	int number;
	char data;
	int left;
	int right;
	Node() {
		number = 0;
		left = 0;
		right = 0;
	}
	Node(int a, char b, int c, int d) {
		number = a;
		data = b;
		left = c;
		right = d;
	}
};

int a[1005];
Node tree[1005];

void pre_traversal(Node node) {
	cout << node.data;
	if(tree[node.number].left) pre_traversal(tree[tree[node.number].left]);
	if(tree[node.number].right) pre_traversal(tree[tree[node.number].right]);
}

int main () {
	int n;
	while(cin >> n) {
		memset(a,0,sizeof(a));
		for(int k = 0; k < n; k++) {
			int i, l, r;
			char c;
			cin >> i >> c >> l >> r;
			Node x(i,c,l,r);
			a[i]++;
			a[l]++;
			a[r]++;
			tree[i] = x;
		}
		int pos = 0;
		for(int i = 0; i < 1005; i++) {             // ур╦Ы╫з╣Ц 
			if(a[i] == 1 && i) pos = i;
		}
		Node root;
		for(int i = 1; i <= 1000; i++) {
			if(tree[i].number == pos) {
				root.number = tree[i].number;
				root.data = tree[i].data;
				root.left = tree[i].left;
				root.right = tree[i].right;
			}
		}
		
		pre_traversal(root);
		cout << endl;
	}
}
