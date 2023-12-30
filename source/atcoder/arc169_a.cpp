#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MOD9 = 998244353;
const ll MOD1 = (ll)1e9 + 7;

void dfs(int node, int cur_dist, vector<vector<int>>& adj_list, vector<int>& dist) {
    if (dist[node] != -1) return;
    dist[node] = cur_dist;
    for(int next_node : adj_list[node]) {
        if (dist[node] != -1) {
            dfs(next_node, cur_dist + 1, adj_list, dist);
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n + 1), p(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 2; i <= n; i++)
        cin >> p[i];

    vector<vector<int>> adj_list(n + 1);
    for(int i = 2; i <= n; i++) {
        adj_list[p[i]].push_back(i);
    }

    vector<int> dist(n + 1, -1);
    dfs(1, 0, adj_list, dist);
    vector<ll> coeff(n + 1);
    for(int i = 1; i <= n; i++) {
        coeff[dist[i]] += a[i];
    }

    char sign = '0';
    for(int i = n; i >= 1; i--) {
        if (coeff[i] != 0) {
            sign = coeff[i] > 0 ? '+' : '-';
            break;
        }
    }

    if (sign == '0' && a[1] > 0) {
        sign = '+';
    }
    else if (sign == '0' && a[1] < 0) {
        sign = '-';
    }

    cout << sign;

    return 0;
}