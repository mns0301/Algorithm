#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> cur(3, 0);
	vector<int> mi_new(3, 0);
	vector<int> ma_new(3, 0);

	for (int i = 0; i < n; i++) {
		cin >> cur[0] >> cur[1] >> cur[2];
		vector<int> ma(ma_new);
		vector<int> mi(mi_new);
		ma_new[0] = cur[0] + max(ma[0], ma[1]);
		ma_new[1] = cur[1] + max(ma[0], max(ma[1], ma[2]));
		ma_new[2] = cur[2] + max(ma[1], ma[2]);
		mi_new[0] = cur[0] + min(mi[0], mi[1]);
		mi_new[1] = cur[1] + min(mi[0], min(mi[1], mi[2]));
		mi_new[2] = cur[2] + min(mi[1], mi[2]);
	}
	cout << max(ma_new[0], max(ma_new[1], ma_new[2])) << " " << min(mi_new[0], min(mi_new[1], mi_new[2]));


	return 0;
}