#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

typedef struct Node {
	char name = NULL;
	Node* r = NULL;
	Node* l = NULL;
} node;

string fun1(vector<node> nodes, Node* x, string ans) {
	string l = "";
	string r = "";
	if (x->l != NULL) l = fun1(nodes,  x->l, ans);
	if (x->r != NULL) r = fun1(nodes,  x->r, ans);
	return x->name + l + r;
}

string fun2(vector<node> nodes, Node* x, string ans) {
	string l = "";
	string r = "";
	if (x->l != NULL) l = fun2(nodes, x->l, ans);
	if (x->r != NULL) r = fun2(nodes, x->r, ans);
	return l + x->name + r;
}

string fun3(vector<node> nodes, Node* x, string ans) {
	string l = "";
	string r = "";
	if (x->l != NULL) l = fun3(nodes, x->l, ans);
	if (x->r != NULL) r = fun3(nodes, x->r, ans);
	return l + r + x->name;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	char c1, c2, c3;
	cin >> n;
	vector<node> nodes(n);
	for (int i = 0; i < n; i++) {
		cin >> c1 >> c2 >> c3;
		nodes[c1 - 'A'].name = c1;
		if (c2 != '.') nodes[c1 - 'A'].l = &nodes[c2 - 'A'];
		if (c3 != '.') nodes[c1 - 'A'].r = &nodes[c3 - 'A'];
	}
	string a = "";
	cout << fun1(nodes, &nodes[0], a) << "\n";
	cout << fun2(nodes, &nodes[0], a) << "\n";
	cout << fun3(nodes, &nodes[0], a) << "\n";

	return 0;
}