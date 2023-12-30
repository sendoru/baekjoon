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

    int n, d;
    cin >> n >> d;
    vector<ld> w(n);
    vector<ld> bags(d);
    ld avg = 0;
    for(auto& i : w) {
        cin >> i;
        avg += i;
    }
    avg /= (ld)d;

    vector<vector<ld>> dp(1 << n, vector<ld>(d + 1));
    for(int i = 0; i < 1 << n; i++) {
        ld cur = 0;
        for(int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                cur += w[j];
            }
        }
        dp[i][1] = (cur - avg) * (cur - avg);
        for(int j = 2; j <= d; j++) {
            dp[i][j] = dp[i][j - 1] + dp[0][1];
            int ii = i;
            while (ii > 0) {
                dp[i][j] = min(dp[i][j], dp[i - ii][j - 1] + dp[ii][1]);
                ii = (ii - 1) & i;
            }
        }
    }

    cout.precision(12);
    cout << dp.back().back() / (ld)d;

    return 0;
}