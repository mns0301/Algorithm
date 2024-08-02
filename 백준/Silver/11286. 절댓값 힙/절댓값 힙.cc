#include <iostream>
#include <map>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	multimap<long int, int> m;
	long int temp;

	while (n--) {
		cin >> temp;
		if (temp == 0) {
			if (m.empty()) cout << "0\n";
			else {
				cout << (m.begin()->first)*(m.begin()->second)/2 << "\n";
				m.erase(m.begin());
			}
		}
		else {
			if (temp > 0) m.insert(make_pair(temp * 2 + 1, 1));
			else m.insert(make_pair(-temp * 2, -1));
		}
	}

	return 0;
}