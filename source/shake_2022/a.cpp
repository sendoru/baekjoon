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

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<ll> p(2 * n);
        for(auto& i : p)
            cin >> i;
        sort(p.begin(), p.end());

        // case 1: n == 1
        if (n == 1) {
            cout << p[1] - p[0] << '\n';
            continue;
        }
        else {
            ll ans = 1e17;
            // 모든 수가 0
            ll cur =  0;
            for(auto i : p)
                cur += abs(i);
            ans = min(cur, ans);
            // 2n - 1개 수가 -1이고 다른 수가 '적당한 수'인 경우
            cur = 0;
            vector<ll> q(2 * n, -1);
            q.back() = (n & 1 ? n - 2 : n);
            for(int i = 0; i < 2 * n; i++) {
                cur += abs(p[i] - q[i]);
            }
            ans = min(cur, ans);
            if (n == 2) {
                cur = 0;
                for(auto i : p) {
                    cur += abs(i - 2);
                }
                ans = min(cur, ans);
            }
            cout << ans << '\n';
        }
    }

    return 0;
}