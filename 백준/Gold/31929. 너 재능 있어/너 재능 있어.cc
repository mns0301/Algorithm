#include <iostream>
#include <algorithm>
using namespace std;

int pre(int cur, int k, int lose) {
	int temp = 1000;
	cur += k * 1000;
	if (cur > 0 && cur % k != 0) {
		temp = cur % k;
	}
	return min(lose, temp);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int w, l, k;
	cin >> w;
	int* win = new int[w];
	int** score = new int* [w + 1];
	for (int i = 0; i < w; i++) cin >> win[i];
	cin >> l;
	int* lose = new int[l];
	for (int i = 0; i < l; i++) cin >> lose[i];
	for (int i = 0; i < w + 1; i++) score[i] = new int[l + 1];
	cin >> k;

	score[0][0] = 0;
	for (int i = 1; i < l + 1; i++) {
		score[0][i] = score[0][i - 1] - pre(score[0][i - 1], k, lose[i - 1]);
	}

	for (int i = 1; i < w + 1; i++) {
		score[i][0] = score[i - 1][0] + win[i - 1];
		for (int j = 1; j < l + 1; j++) {
			score[i][j] = max(score[i][j - 1] - pre(score[i][j - 1], k, lose[j - 1]), score[i - 1][j] + win[i - 1]);
		}
	}

	cout << score[w][l];

	return 0;
}