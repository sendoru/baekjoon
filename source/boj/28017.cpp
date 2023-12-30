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

    int n, m;
    cin >> n >> m;
    vector<vector<ll>> v(n, vector<ll>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }

    // dp[i][j] := i회차에서 j번 무기를 골랐을때 최소 누적 시간
    vector<vector<ll>> dp(n, vector<ll>(m, MOD9 * 1000));
    for(int i = 0; i < m; i++) {
        dp[0][i] = v[0][i];
    }

    // dp2[i][j] := i회차에서 j번 무기를 "안" 골랐을 때 최소 누적 시간
    //

    for(int i = 1; i < n; i++) {
        // j : i회차 무기
        for(int j = 0; j < m; j++) {
            // k : i-1회차 무기
            for(int k = 0; k < m; k++){
                if (j != k) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + v[i][j]);
                }
            }
        }
    }

    cout << *min_element(dp.back().begin(), dp.back().end());

    return 0;
}