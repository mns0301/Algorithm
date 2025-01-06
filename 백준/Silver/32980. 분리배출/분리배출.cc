#include <iostream>
#include <vector>
#include <string>
using namespace std;

int value(vector<int>& kind, char comp) {
	if (comp == 'P')
        return kind[0];
	else if (comp == 'C')
        return kind[1];
    else if (comp == 'V')
        return kind[2];
    else if (comp == 'S')
        return kind[3];
    else if (comp == 'G')
        return kind[4];
    else if (comp == 'F')
        return kind[5];
	else
        return kind[6];
}

int main(void) {

    int n;
    cin >> n;
    vector<string> trash(n);
    for (int i = 0; i < n; i++)
		cin >> trash[i];

    vector<int> kind(7);
    for (int i = 0; i < 7; i++)
        cin >> kind[i];

    long long cost = 0;
    for (int i = 0; i < n; i++) {
        string now = trash[i];

        char comp = now[0];
        int flag = 0;
        for (int j = 1; j < now.size(); j++) {
			if (now[j] != comp) {
                flag = 1;
                break;
            }
		}

		if (flag)
            comp = 'O';

        cost += now.size() * min(kind[6], value(kind, comp));
    }

    cout << cost;
}