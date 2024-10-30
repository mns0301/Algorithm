#include <iostream>
#include <deque>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main() {
	fastio;

	int n, x, print;
	string order;
	cin >> n;
	deque<int> d;

	while(n--) {
		cin >> order;
		if (order[0] == 's') print = d.size();
		else if (order[0] == 'e') print = d.empty();
		else if (order[0] == 'f') print = (d.empty() ? -1 : d.front());
		else if (order[0] == 'b') print = (d.empty() ? -1 : d.back());
		else {
			if (order[5] == 'r') {
				if (d.size()) print = d.front(), d.pop_front();
				else print = -1;
			}
			else if (order[5] == 'a') {
				if (d.size()) print = d.back(), d.pop_back();
				else print = -1;
			}
			else {
				cin >> x;
				if (order[5] == 'f') d.push_front(x);
				else if (order[5] == 'b') d.push_back(x);
				print = -2;
			}
		}
		if (print != -2) cout << print << "\n";
	}

	return 0;
}