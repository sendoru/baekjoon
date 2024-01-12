#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1'000'000'007;

int main(){
    ll n, c;
    cin >> n >> c;

    // inversion 갯수가 c인 길이 n perm의 갯수

    // dp[i][j]: 길이 i이고 inversion 갯수가 j인 perm의 갯수
    // inversion 갯수가 j인 길이 n - 1 perm 맨 뒤에 n을 추가하면 갯수는 여전히 j
    // inversion 갯수가 j - 1인 길이 n - 1 perm 뒤에서 2번째에 n을 추가 (n 뒤의 원소가 1개) 하면 갯수는 j
    // ...
    // 근데 이런 방법으로 추가되는 inversion의 갯수는 최소 0개, 최대 n - 1개임
    // 점화식: dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1] + ... + dp[i - 1][max(0, j - i + 1)]
    // 우변의 항은 최대 i개
    vector<vector<ll>> dp(n + 1, vector<ll>(c + 1));
    dp[1][0] = 1;
    for(int i = 2; i <= n; i++) {
        vector<ll> prefix_sum(c + 1);
        prefix_sum[0] = dp[i - 1][0];
        for(int j = 1; j <= c; j++) {
            prefix_sum[j] = prefix_sum[j - 1] + dp[i - 1][j];
        }

        for(int j = 0; j <= c; j++) {
            if (j - i + 1 > 0) {
                dp[i][j] = (prefix_sum[j] - prefix_sum[j - i]) % MOD;
            }
            else {
                dp[i][j] = prefix_sum[j] % MOD;
            }
        }
    }

    cout << dp[n][c];
    return 0;
}