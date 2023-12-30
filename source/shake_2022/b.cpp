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

    ll n;
    cin >> n;
    vector<ll> p(n);
    for(ll& i : p)
        cin >> i;

    ll k;
    cin >> k;

    ll ans = 0;
    for (ll i : p) {
        ll cur = i;
        for(;cur <= k; cur *= i) {
            ans += k / cur;
        }
    }

    cout << ans;

    return 0;
}