#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MOD9 = 998244353;
const ll MOD1 = (ll)1e9 + 7;

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<pii> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].first;
    }
    for(int i = 0; i < n; i++) {
        cin >> v[i].second;
    }

    sort(v.begin(), v.end());

    vector<int> sum_inc_seq_min(n, 0);
    sum_inc_seq_min[0] = 0;

    vector<int> cul_sum_min(n);
    cul_sum_min[0] = min(v[0].first, v[0].second);
    for(int i = 1; i < n; i++) {
        cul_sum_min[i] = cul_sum_min[i - 1] + min(v[i].first, v[i].second);
    }

    vector<int> prev(n, -1);
    vector<bool> in_lis(n, false);
    int curr = -1, curr_inc_seq_min = 0;
    for(int i = 0; i < n; i++) {
        sum_inc_seq_min[i] = min(v[i].first, v[i].second);
        for (int j = 0; j < i; j++) {
            if (v[j].second < v[i].second) {
                if (sum_inc_seq_min[j] + min(v[i].first, v[i].second) > sum_inc_seq_min[i]) {
                    sum_inc_seq_min[i] = sum_inc_seq_min[j] + min(v[i].first, v[i].second);
                    prev[i] = j;
                }
            }
        }

        if (sum_inc_seq_min[i] > curr_inc_seq_min) {
            curr = i;
            curr_inc_seq_min = sum_inc_seq_min[i];
        }
    }

    while(curr != -1) {
        in_lis[curr] = true;
        curr = prev[curr];
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        if (in_lis[i]) {
            ans += v[i].first + v[i].second;

        }

        else {
            ans += max(v[i].first, v[i].second);
        }
    }

    cout << ans;
}

int main() {
    solve();
    return 0;
}