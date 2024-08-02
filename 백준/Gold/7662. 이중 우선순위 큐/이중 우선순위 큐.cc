#include <iostream>
#include <map>
using namespace std;

int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int k;
		char temp;
		int num;
		cin >> k;
		multimap<int, bool> m;
		for (int j = 0; j < k; j++) {
			cin >> temp;
			if (temp == 'I') {
				cin >> num;
				m.insert(pair<int,char>(num, 1));

			}
			else {
				cin >> num;
				if (!m.empty()) {
					if (num == 1) m.erase(--m.end());
					else m.erase(m.begin());
				}
			}
		}

		if (m.empty()) cout << "EMPTY\n";
		else cout << (--m.end())->first << " " << m.begin()->first << "\n";

	}

	return 0;
}