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

    string s;
    cin >> s;
    reverse(s.begin(), s.end());

    ll n;
    cin >> n;

    ll cur = 0;

    for(ll i = 0 ; i < s.length(); i++) {
        if (s[i] == '1') {
            cur += (1ll << i);
        }
    }

    if (cur > n) {
        cout << -1;
        return 0;
    }

    for(ll i = s.length() - 1; i >= 0; i--) {
        if (s[i] == '?' && cur + (1ll << i) <= n) {
            cur += (1ll << i);
        }
    }

    cout << cur;
    return 0;
}