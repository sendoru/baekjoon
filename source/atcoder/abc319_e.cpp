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

    ll n, x, y;
    cin >> n >> x >> y;

    vector<pll> pt(n - 1);
    for(int i = 0; i < n - 1; i++) {
        cin >> pt[i].first >> pt[i].second;
    }

    // dp[i][j]: 정거장 i에서 840으로 나눈 나머지가 j인 시간에 출발하려고 할 때,
    // 마지막 정거장까지 가는데 필요한 시간

    vector<vector<ll>> dp(n - 1, vector<ll>(840, MOD9));
    for(int i = 0; i < 840; i++) {
        dp[n - 2][i] = (pt[n - 2].first - (i % pt[n - 2].first)) % pt[n - 2].first + pt[n - 2].second;
    }

    for(int i = n - 3; i >= 0; i--) {
        for(int j = 0; j < 840; j++) {
            // i번째 정거장에서 출발하려면,
            // 일단 시간이 j 이상인 제일 작은 pt[i].first의 배수가 될때까지 기다려야 함
            // 그거 + 가는데 걸리는 시간 pt[i].second
            dp[i][j] = (pt[i].first - (j % pt[i].first)) % pt[i].first + pt[i].second;
            // 저 아래 두 줄은 정거장 i+1에서 기다리는 데 걸리는 시간 + dp로 미리 계산된 값 더하는거
            // 근데 i+1에서 기다리는데 걸리는 시간도 dp로 미리 계산된 거엿네
            ll arrive_next_time = (dp[i][j] + j) % 840;
            dp[i][j] += dp[i + 1][arrive_next_time];
        }
    }

    ll q;
    cin >> q;
    while(q--) {
        ll qi;
        cin >> qi;

        qi += x;
        qi += dp[0][qi % 840];
        qi += y;

        cout << qi << '\n';
    }

    return 0;
}