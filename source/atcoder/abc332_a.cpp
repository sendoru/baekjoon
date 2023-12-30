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

    ll n, s, k;
    cin >> n >> s >> k;

    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ll p, q;
        cin >> p >> q;
        ans += p * q;
    }

    if (ans < s)
        ans += k;

    cout << ans;


    return 0;
}