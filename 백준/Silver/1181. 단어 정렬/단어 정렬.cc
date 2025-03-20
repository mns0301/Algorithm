#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

bool cmp(string &p, string &q){
    if(p.size() == q.size()){
        return p<q;
    }
    return p.size()<q.size();
}

int main() {
    fastio;

    int N;
    cin >> N;
    vector<string> arr(N);
    for(int i = 0; i<N; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end(), cmp);
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    for(int i = 0; i<arr.size(); i++){
            cout << arr[i] << "\n";
    }

    return 0;
}