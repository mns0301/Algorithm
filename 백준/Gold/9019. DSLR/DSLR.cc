#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int D(int n);
int S(int n);
int L(int n);
int R(int n);

string BFS(int n, int ans) {
	queue<int> q;
	q.push(n);
	vector<pair<int, string>> v(10000, {0, ""});
	v[n].first = 1;

	while (!q.empty()) {
		n = q.front();
		q.pop();

		if (n == ans) return v[n].second;
		
		int t = D(n);
		if (v[t].first == 0) {
			v[t].second = v[n].second + "D";
			v[t].first = 1;
			q.push(t);
		}
		t = S(n);
		if (v[t].first == 0) {
			v[t].second = v[n].second + "S";
			v[t].first = 1;
			q.push(t);
		}
		t = L(n);
		if (v[t].first == 0) {
			v[t].second = v[n].second + "L";
			v[t].first = 1;
			q.push(t);
		}
		t = R(n);
		if (v[t].first == 0) {
			v[t].second = v[n].second + "R";
			v[t].first = 1;
			q.push(t);
		}
	}

	return "\0";
}

int D(int n) {
	return n * 2 % 10000;
}

int S(int n) {
	return (n + 9999) % 10000;
}

int L(int n) {
	int temp = n / 1000;
	n %= 1000;
	return n * 10 + temp;
}

int R(int n) {
	int temp = n % 10;
	n /= 10;
	return temp * 1000 + n;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n1, n2;
		cin >> n1 >> n2;
		cout << BFS(n1, n2) << "\n";
	}

	return 0;
}