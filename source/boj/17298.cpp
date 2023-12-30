#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for(auto& i : a) {
        cin >> i;
    }

    vector<int> oks(n, -1);
    vector<int> idxs;

    for(int i = 0; i < n; i++) {
        while(!idxs.empty() && a[idxs.back()] < a[i]) {
            oks[idxs.back()] = a[i];
            idxs.pop_back();
        }
        idxs.push_back(i);
    }

    for(auto elem : oks) {
        cout << elem << ' ';
    }

    return 0;
}