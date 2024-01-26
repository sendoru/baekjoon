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
    // (l, r) 범위의 부분수열에 길이 3인 등차수열이 존재하게 하는 순서쌍 (l,
    // r)의 갯수

    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> pos(10);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        pos[a[i]].push_back(i);
    }

    // asdf[i] = j (i, j)가 조건을 만족하는 순서쌍이 되게 하는 최소의 j
    // 이걸 좀 빨리 구해보자

    vector<int> asdf(n, MOD9);

    for (int i = 0; i < n; i++) {
        for (int al = 0; al < 10; al++) {
            for (int d = -5; d <= 5; d++) {
                if (al + 2 * d < 0 || al + 2 * d >= 10) {
                    continue;
                }

                // 초항 al, 공차 d

                auto iter_first =
                    lower_bound(pos[al].begin(), pos[al].end(), i);
                if (iter_first == pos[al].end()) {
                    continue;
                }

                auto iter_second = lower_bound(
                    pos[al + d].begin(), pos[al + d].end(), *iter_first + 1);
                if (iter_second == pos[al + d].end()) {
                    continue;
                }

                auto iter_third =
                    lower_bound(pos[al + 2 * d].begin(), pos[al + 2 * d].end(),
                                *iter_second + 1);
                if (iter_third == pos[al + 2 * d].end()) {
                    continue;
                }

                asdf[i] = min(asdf[i], *iter_third);
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += max(0, n - asdf[i]);
    }

    cout << ans;

    return 0;
}