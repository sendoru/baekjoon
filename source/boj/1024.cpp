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

    ll n, l;
    cin >> n >> l;

    for(int i = l; i <= 100; i++) {
        if (i % 2 == 1 && n % i == 0) {
            bool done = true;
            for(int j = -(i / 2); j <= (i / 2); j++) {
                if (n / i + j < 0) {
                    done = false;
                    break;
                }
                cout << n / i + j << ' ';
            }
            if (done)
                return 0;
        }
        else if (i % 2 == 0 && n % i == i / 2) {
            bool done = true;
            for(double j = -(i / 2.0 - 0.5); j <= (i / 2.0 - 0.5); j++) {
                if ((ll)(n / (double)i + j) < 0) {
                    done = false;
                    break;
                }
                cout << (ll)(n / (double)i + j) << ' ';
            }
            if (done)
                return 0;
        }
    }

    cout << -1;
    return 0;
}