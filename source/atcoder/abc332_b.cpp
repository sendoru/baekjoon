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

    ll k, g, m;
    cin >> k >> g >> m;

    ll water_g = 0, water_m = 0;

    for(int i = 0; i < k; i++) {
        if (water_g == g) {
            water_g = 0;
        }
        else if (water_m == 0) {
            water_m = m;
        }
        else {
            ll moved = min(g - water_g, water_m);
            water_g += moved;
            water_m -= moved;
        }
    }

    cout << water_g << ' ' << water_m;

    return 0;
}