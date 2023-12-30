//
// Created by sendo on 2023-01-28.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> s(n), t(m);
    for(auto& i : s)
        cin >> i;
    for(auto& i : t)
        cin >> i;

    int ans = 0;
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i] % 1000 == t[j]) {
                ans++;
                break;
            }
        }
    }

    cout << ans;
    return 0;
}