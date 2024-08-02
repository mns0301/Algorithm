#include <iostream>
#include <algorithm>
#include <string>
#include <deque>
#include <sstream>
using namespace std;

int main(void) {
	int t;
	cin >> t;
	string p;
	int n;
	string nums;
	deque<string> v;
	int s_pos, e_pos;
	bool is_reverse = false;
	bool is_error = false;

	while (t--) {
		cin >> p >> n >> nums;
		v.clear();
		s_pos = 1;
		e_pos = nums.size();
		if (n > 0) {
			nums = nums.substr(1, nums.size() - 2);
			stringstream ss(nums);
			string num;
			while (getline(ss, num, ',')) {
				v.push_back(num);
			}
		}
		
		int sz = p.size();
		is_error = false;
		is_reverse = false;
		if (v.empty()) {
			for (int i = 0; i < sz; i++) {
				if (p[i] == 'D') {
					is_error = true;
					break;
				}
			}
		}
		for (int i = 0; i < sz; i++) {
			if (p[i] == 'R') {
				is_reverse = !is_reverse;
			}
			else {
				if (v.empty()) {
					is_error = true;
					break;
				}
				else {
					if (is_reverse) v.pop_back();
					else v.pop_front();
				}
			}
		}

		if (is_error) cout << "error\n";
		else {
			cout << "[";
			if (is_reverse) {
				for (int i = v.size() - 1; i > 0; i--) cout << v[i] << ",";
				if (!v.empty()) cout << v[0];
			}
			else {
				sz = v.size() - 1;
				for (int i = 0; i < sz; i++) cout << v[i] << ",";
				if (!v.empty()) cout << v[sz];
			}
			cout << "]\n";
		}

	}
	return 0;
}