#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MOD9 = 998244353;
const ll MOD1 = (ll)1e9 + 7;

bool is_bipartite(vector<int>& a, vector<int>& b, int n) {
    vector<int> visited(n + 1, -1);
    vector<vector<int>> adj_list(n + 1);
    for(int i = 0; i < a.size(); i++) {
        adj_list[a[i]].push_back(b[i]);
        adj_list[b[i]].push_back(a[i]);
    }
    function<bool(int, int)> dfs = [&] (int node, int color) -> bool {
        if (visited[node] != -1 && visited[node] != color) {
            return false;
        }
        else if (visited[node] != -1) {
            return true;
        }

        visited[node] = color;
        for(int next : adj_list[node]) {
            bool dfs_result = dfs(next, 1 - color);
            if (!dfs_result) {
                return false;
            }
        }
        return true;
    };
    for(int i = 1; i <= n; i++) {
        if (visited[i] == -1) {
            bool dfs_result = dfs(i, 0);
            if (!dfs_result) {
                return false;
            }
        }
    }

    return true;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(m), b(m);

    for(int i = 0; i < m; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }

    // x_si != x_ti (i = 1, 2, ... , m)를 만족하는 길이 n인 binary sequence X가 존재
    bool res = is_bipartite(a, b, n);

    cout << (res ? "Yes" : "No");

    return 0;
}