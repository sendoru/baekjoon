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
    for(ll i = 1; i <= 15; i++) {
        ll aa = 1;
        for(int j = 0; j < i; j++) {
            aa *= i;
        }
        if (aa == n) {
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}