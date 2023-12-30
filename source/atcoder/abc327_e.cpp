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

    // dp[i][j] := i번째 콘테스트가 마지막 콘테스트이고, 그동안 j개의 콘테스트를 치뤘을 때 '''(-1200/sqrt(k))는 반영하지 않은 최대 점수'''
    //

    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0 ; i < n; i++) {
        cin >> p[i];
    }

    vector<double> denom(n + 1);
    denom[1] = 1;
    for(int i = 2; i <= n; i++) {
        denom[i] = denom[i - 1] + pow(0.9, i - 1);
    }

    vector<vector<double>> dp(n, vector<double>(n + 1, 0));
    dp[0][1] = p[0];
    for(int i = 1; i < n; i++) {
        for(int j = 1; j <= i + 1; j++) {
            // i번쨰 콘테스트가 마지막으로 참가한 거다
            dp[i][j] = (dp[i - 1][j - 1] * denom[j - 1] * 0.9 + p[i]) / denom[j];

            // i번째 콘테스트는 스킵했다
            if (j != i + 1) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            }

        }
    }

    double ans = -MOD9;
    for(int i = 0; i < n; i++) {
        for(int j = 1; j <= n; j++) {
            ans = max(ans, dp[i][j] - 1200./sqrt(j));
        }
    }

    cout << fixed;
    cout.precision(10);
    cout << ans;
    return 0;

}