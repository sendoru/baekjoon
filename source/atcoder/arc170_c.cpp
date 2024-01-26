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

    // 모든 원소가 1 ~ 10 자연수인 수열이 던져진다
    // (l, r) 범위의 부분수열에 길이 3인 등차수열이 존재하게 하는 순서쌍 (l, r)의 갯수

    ll n, m;
    cin >> n >> m;
    vector<int> s(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }

    // 일단 mex(A1, A2, ... Ai - 1)는 단조증가수열임
    // Ai = mex(A1, A2, ... Ai - 1)이 되려면
    // Ai보다 작은 수는 i-1번째 인덱스까지 전부 한 번씩은 나왔어야 된다는건데
    // Ai랑 같은 값은 안나오고
    // dp로 어떻게 되나

    // 시작부분에 1이 연달아 나오면
    // 그 1이 연달아 나오는 부분은 한가지로 경우가 고정됨 (0, 1, 2, 3, ...)
    // 이걸 잘 확장해보면...

    // 처음으로 0이 나오면
    // idx + 1 //이상// 의 수를 무조건 박아야되고
    // 그 뒤에 또 0이 계속 나오면
    // 처음으로 0이 나온 곳의 idx + 1 이상의 수만 계속 박아주면 되는데
    // 그 다음에 또 1이 나오면
    // 수열 값 중에 idx는 아직 안나왔으니까
    // 바로 idx를 박아주면 됨
    // 근데 그 다음엔??/????
    // 그 전에 0이 연달아 나왔던 구간에서 넣어준 값 중 최솟값 같은 걸 알고있어야
    // 1 1 0 0 1 1 0
    // 0 1 3
    // 으아아아
    if (m > n) {
        ll ans = 1;
        for(int i = 1; i <= n; i++) {
            if (s[i] == 0) {
                ans = ans * m % MOD9;
            }
        }
        cout << ans;
        return 0;
    }

    vector<vector<ll>> dp(n + 1, vector<ll>(min(n, m) + 18));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        if (s[i + 1] == 1) {
            for (ll j = 0; j <= m; j++) {
                if (j + 1 >= dp[0].size()) {
                    break;
                }
                dp[i + 1][j + 1] += dp[i][j];
                dp[i + 1][j + 1] %= MOD9;
            }
        }
        else {
            for (ll j = 0; j <= m - 1; j++) {
                if (j + 1 >= dp[0].size()) {
                    break;
                }
                dp[i + 1][j + 1] += dp[i][j] * (m - j);
                dp[i + 1][j + 1] %= MOD9;
            }
            for(ll j = 1; j <= m + 1; j++) {
                if (j >= dp[0].size()) {
                    break;
                }
                dp[i + 1][j] += dp[i][j] * j;
                dp[i + 1][j] %= MOD9;
            }
        }
    }

    ll ans = 0;
    for (auto elem : dp.back()) {
        ans += elem;
        ans %= MOD9;
    }
    cout << ans;

    return 0;
}