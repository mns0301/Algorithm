#include <iostream>
#include <sstream>
#include <stack>
#include <string>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	stack<string> num;
	string str;
	string temp;
	cin >> str;
	istringstream s(str);
	long long sum = 0;
	
	while (getline(s, temp, '-')) num.push(temp);
	int sz = num.size();

	for (int i = 1; i < sz; i++) {
		str = num.top();
		num.pop();
		istringstream ss(str);
		while (getline(ss, temp, '+')) sum -= stoi(temp);
	}
	str = num.top();
	num.pop();
	istringstream ss(str);
	while (getline(ss, temp, '+')) sum += stoi(temp);

	cout << sum;

	return 0;
}	