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

    int n, m, k;
    cin >> n >> m >> k;

    vector<ll> l(n);
    for(ll& i : l)
        cin >> i;

    sort(l.begin(), l.end());
    l.erase(upper_bound(l.begin(), l.end(), m), l.end());
    // dp[i] := i번째까지 볼 때 걸리는 최소 시간
    int ans = 0;
    int lo = 0, hi = l.size();
    while(lo <= hi) {
        int mid = (lo + hi) / 2;
        ll t = 0;
        for(int i = mid - 1; i >= 0;  i -= k) {
            t += l[i];
        }

        if (t > m) {
            hi = mid - 1;
        }
        else {
            ans = max(ans, mid);
            lo = mid + 1;
        }
    }

    cout << ans;
    return 0;
}