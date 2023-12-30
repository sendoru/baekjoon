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
    vector<int> v(n + 1);
    v[0] = MOD1 + 1;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    n++;
    v.push_back(MOD1);

    vector<int> less_than_prev(n + 1);
    less_than_prev[1] = 1;
    for(int i = 2; i <= n; i++) {
        if (v[i] < v[i - 1]) {
            less_than_prev[i] = 1;
        }
    }

    vector<int> less_than_prev_cul_sum(n + 1);
    for(int i = 1; i <= n; i++) {
        less_than_prev_cul_sum[i] = less_than_prev_cul_sum[i - 1] + less_than_prev[i];
    }

    //    8 2 3 4 1
    // -> 1 1 0 0 1
    // -> 1 2 2 2 3

    // 8 4 3 2 1
    // -> 1 1 1 1 1
    // -> 1 2 3 4 5

    for(int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        // 구간 l ~ r + 1 제외
        int ans = less_than_prev_cul_sum.back() - (less_than_prev_cul_sum[r + 1] - less_than_prev_cul_sum[l - 1]);
        ans += (v[r] < v[l - 1]);
        ans += (v[r + 1] < v[l]);
        // 구간 l + 1 ~ r의 합 반전
        ans += (r - l) - (less_than_prev_cul_sum[r] - less_than_prev_cul_sum[l]);
        cout << ans << '\n';
    }

    return 0;
}