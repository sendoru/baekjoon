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

    int n, d, w;
    cin >> n >> d >> w;
    vector<vector<int>> apples(2 * 1e5 + 10);
    for(int i = 0; i < n; i++) {
        int t, x;
        cin >> t >> x;
        apples[t].push_back(x);
    }

    for(auto& elem : apples) {
        sort(elem.begin(), elem.end());
    }

    int x0 = 0, x1 = 0, t0 = 0, t1 = 0;

    return 0;

}