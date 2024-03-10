#include <bits/stdc++.h>
// #include "atcoder/all"
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MOD9 = 998244353;
const ll MOD1 = (ll)1e9 + 7;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int q;
    cin >> q;

    vector<int> v;
    while(q--) {
        int a, b;
        cin >> a >> b;
        if (a == 1) {
            v.push_back(b);
        }
        else {
            cout << v[v.size() - b] << '\n';
        }
    }

    return 0;
}