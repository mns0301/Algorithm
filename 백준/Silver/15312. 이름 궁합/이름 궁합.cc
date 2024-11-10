#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int arr[26] = {3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};

    string s1, s2;
    cin >> s1 >> s2;
	vector<int> v(s1.size() * 2);
    int n = s1.size();

    for (int i = 0; i < n; i++) {
        v[2 * i] = arr[s1[i] - 'A'];
        v[2 * i + 1] = arr[s2[i] - 'A'];
    }

    for (int i = 1; i < 2 * n - 1; i++) {
        for (int j = 0; j < 2 * n - i; j++) {
            v[j] = (v[j] + v[j + 1]) % 10;
        }
    }

    cout << v[0] << v[1];

    return 0;
}
