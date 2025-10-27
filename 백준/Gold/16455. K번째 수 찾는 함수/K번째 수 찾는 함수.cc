#include <bits/stdc++.h>

int kth(std::vector<int> &a, int k) {
    std::random_shuffle(a.begin(), a.end());
    std::nth_element(a.begin(), a.begin() + k - 1, a.end());
    return a[k - 1];
}