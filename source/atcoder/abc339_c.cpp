#include <bits/stdc++.h>
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

    int n;
    cin >> n;
    vector<ll> a(n);
    for(auto& i : a) {
        cin >> i;
    }

    ll min_init = 0;
    ll cur_delta = 0;
    for(auto elem : a) {
        cur_delta += elem;
        min_init = max(min_init, -cur_delta);
    }

    cout << min_init + cur_delta;

    return 0;
}