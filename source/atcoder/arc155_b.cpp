//
// Created by sendo on 2023-01-29.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MOD9 = 998244353;
const ll MOD1 = (ll)1e9 + 7;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<pll> s;
    set<ll> v;
    ll t, q, a, b;
    cin >> q >> a >> b;
    v.insert(a + b);
    v.insert(a - b);

    while(q--) {
        cin >> t >> a >> b;
        if (t == 1) {
            v.insert(a + b);
            v.insert(a - b);
        }

        else {
            auto iter = v.lower_bound(a);
            if (iter != v.end() && *iter <= b) {
                cout << 0 << '\n';
            }
            else {
                auto iter_ls_a = iter;
                if (iter_ls_a != v.begin())
                    iter_ls_a--;
                if (iter == v.end())
                    cout << abs(a - *iter_ls_a) << '\n';
                else
                    cout << min(abs(*iter - b), abs(a - *iter_ls_a)) << '\n';
            }
        }

    }



    return 0;
}