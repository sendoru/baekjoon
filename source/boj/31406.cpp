#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MOD9 = 998244353;
const ll MOD1 = (ll)1e9 + 7;

vector<int> dr = {-1, 0, 1, 0}, dc = {0, 1, 0, -1};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(12);

    int n, q;
    cin >> n >> q;
    vector<vector<int>> adj(n + 1);
    vector<int> opened(n + 1);
    opened[1] = true;

    for(int i = 1; i <= n; i++) {
        int cnt;
        cin >> cnt;
        adj[i].resize(cnt);
        for(int j = 0; j < cnt; j++) {
            cin >> adj[i][j];
        }
    }

    int cursor = adj[1][0];

    vector<int> order;
    function<void(int)> dfs = [&] (int node) {
        order.push_back(node);
        if (opened[node]) {
            for(auto next : adj[node]) {
                dfs(next);
            }
        }
    };

    while(q--) {
        string s;
        int k;
        cin >> s;
        if (s == "toggle") {
            opened[cursor] = (opened[cursor] + 1) % 2;
        }
        else {
            cin >> k;
            order.clear();
            dfs(1);
            int idx = find(order.begin(), order.end(), cursor) - order.begin();
            idx += k;
            if (idx >= (int)order.size()) {
                idx = order.size() - 1;
            }
            else if (idx <= 0) {
                idx = 1;
            }
            cout << order[idx] << '\n';
            cursor = order[idx];
        }
    }


    return 0;
}