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

    vector<ll> fx3;
    for(int i = 0; i < 63; i++) {
        for(int j = i + 1; j < 63; j++) {
            for(int k = j + 1; k < 63; k++){
                ll num = (1ll << i) + (1ll << j) + (1ll << k);
                fx3.push_back(num);
            }
        }
    }

    sort(fx3.begin(), fx3.end());

    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        auto iter = upper_bound(fx3.begin(), fx3.end(), n);
        if (iter == fx3.begin()) {
            cout << -1 << '\n';
        }
        else {
            cout << *(iter - 1) << '\n';
        }
    }

    return 0;
}