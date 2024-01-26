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

    int n;
    cin >> n;

    vector<int> a(n);
    for(auto& i : a) {
        cin >> i;
    }

    // cases_cnt[i][j]: 구간의 끝점이 i인 상태에서 일부 원소를 선택해 부호를 적당히 붙여 선택한 원소의 합의 절댓값이 j가 되게 하는 경우의 수
    vector<vector<ll>> cases_cnt(n, vector<ll>(10001));
    cases_cnt[0][a[0]] = 2;
    for (int i = 1; i < n; i++) {
        cases_cnt[i][a[i]] = 2;
        for(int j = 0; j <= 10000; j++) {
            if(abs(j + a[i] <= 10000)) {
                cases_cnt[i][abs(j + a[i])] += cases_cnt[i - 1][j];
                cases_cnt[i][abs(j + a[i])] %= MOD1;
            }
            cases_cnt[i][abs(j - a[i])] += cases_cnt[i - 1][j];
            cases_cnt[i][abs(j - a[i])] %= MOD1;
        }
    }

    ll ans = 0;

    for(int i = 0; i < n; i++) {
        ans += cases_cnt[i][0];
        ans %= MOD1;
    }

    cout << ans;

    return 0;
}