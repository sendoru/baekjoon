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


    // 줄에서 빠진 사람이 언제 다시 들어가는지는 pq로 관리

    vector<vector<ll>> tws(m, vector<ll>(3));
    for(int i = 0; i < m; i++) {
        cin >> tws[i][0] >> tws[i][1] >> tws[i][2];
    }

    vector<ll> ans(n + 1);
    priority_queue<int, vector<int>, greater<>> row;
    for(int i = 1; i <= n; i++) {
        row.push(i);
    }

    // {복귀 시간, 사람 번호}
    priority_queue<pll, vector<pll>, greater<>> out_of_row;

    ll tws_pos = 0;
    for(ll t = 0; tws_pos < tws.size() && t <= tws.back()[0];) {
        if (out_of_row.empty()) {
            t = tws[tws_pos][0];
        }
        else {
            t = min(out_of_row.top().first, tws[tws_pos][0]);
        }

        while(!out_of_row.empty() && out_of_row.top().first == t) {
            row.push(out_of_row.top().second);
            out_of_row.pop();
        }

        if (t == tws[tws_pos][0]) {
            if (!row.empty()) {
                ans[row.top()] += tws[tws_pos][1];
                out_of_row.push({t + tws[tws_pos][2], row.top()});
                row.pop();
            }
            tws_pos++;
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}