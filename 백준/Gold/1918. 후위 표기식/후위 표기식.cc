#include <iostream>
#include <stack>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	stack<char> op;
	string a;
	cin >> a;
	string ans = "";

	for (int i = 0; i < a.size(); i++) {
		
		if ('A' <= a[i] && a[i] <= 'Z') ans += a[i];
		else if (a[i] == '(') op.push('(');
		else if (a[i] == ')') {
			while (op.size()) {
				char temp = op.top();
				op.pop();
				if (temp == '(') break;
				ans += temp;
			}
		}
		else {
			while (op.size()) {
				if ((op.top() == '-' || op.top() == '+') && (a[i] == '*' || a[i] == '/')) break;
				if (op.top() == '(') break;

				ans += op.top();
				op.pop();
			}
			op.push(a[i]);
		}
	}

	while (op.size()) {
		ans += op.top();
		op.pop();
	}

	cout << ans;

	return 0;
}