#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	int point[8] = { 0 };
	for (int i = 0; i < 8; i++) cin >> point[i];

	if ((n == 1 && m == 2) || (n == 2 && m == 1)) cout << "ChongChong";
	else cout << "GomGom";

	return 0;
}