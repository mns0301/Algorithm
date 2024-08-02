#include <iostream>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	int order;
	int num;
	map<int, int> m;
	map<int, int>::iterator it;

	while (n--) {
		cin >> order;
		if (order == 1) {
			cin >> num;
			m[num]++;
		}
		else if (order == 2) {
			cin >> num;
			it = m.find(num);
			if (it != m.end()) {
				if (--(it->second) == 0) m.erase(it);
			}
		}
		else {
			if (m.empty()) {
				cout << "0\n";
			}
			else {
				int pg = 1;
				it = m.begin();
				int price = it->first;
				it++;

				while (1) {
					it = m.lower_bound(price * 2);
					if (it == m.end()) break;
					pg++;
					price = it->first;
					//cout << pg << "\n";
				}
				cout << pg << "\n";
			}


		}
	}

	return 0;
}