#include <bits/stdc++.h>

#include "atcoder/all"

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MOD9 = 998244353;
const ll MOD1 = (ll)1e9 + 7;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n, t;
    cin >> n >> t;

    vector<ll> cur_score(n + 1);
    multiset<ll> ms;
    set<ll> s;
    for (int i = 0; i < n; i++) {
        ms.insert(0);
    }
    s.insert(0);

    vector<vector<ll>> ab(t, vector<ll>(2));
    for (int i = 0; i < t; i++) {
        cin >> ab[i][0] >> ab[i][1];
    }

    for (int i = 0; i < t; i++) {
        // pop
        auto ms_lb_iter = ms.lower_bound(cur_score[ab[i][0]]), ms_ub_iter = ms.upper_bound(cur_score[ab[i][0]]);
        // 해당 점수가 하나밖에 없으면 s에서도 pop
        if ((--ms_ub_iter) == ms_lb_iter) {
            s.erase(cur_score[ab[i][0]]);
        }
        ms.erase(ms_lb_iter);

        // push
        cur_score[ab[i][0]] += ab[i][1];
        ms.insert(cur_score[ab[i][0]]);
        s.insert(cur_score[ab[i][0]]);

        cout << s.size() << '\n';
    }

    return 0;
}