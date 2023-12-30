#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MOD9 = 998244353;
const ll MOD1 = (ll)1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    vector<pii> bwcnt(n + 1);
    for(int i = 0; i < n - 1; i++) {
        int s, e;
        cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    string ss;
    cin >> ss;

    if (n == 2) {
        cout << ss[1] << ss[0] << '\n';
        return;
    }

    int root = -1;
    for(int i = 1; i <= n; i++){
        if (adj[i].size() > 1) {
            root = i;
            break;
        }
    }

    vector<int> parent(n + 1, -1);
    parent[root] = 0;
    function<void(int)> dfs = [&] (int node) {
        for(auto nxt : adj[node]) {
            if (parent[nxt] == -1) {
                parent[nxt] = node;
                dfs(nxt);
            }
        }
    };

    vector<int> s(n + 1);
    for(int i = 1; i <= n; i++) {
        if (ss[i - 1] == 'B')
            s[i] = 0;
        else
            s[i] = 1;
    }

    vector<vector<int>> prevAdjCnt(n + 1, vector<int>(2));
    vector<int> prevS(n + 1, -1);
    for(int i = 1; i <= n; i++) {
        if (adj[i].size() == 1) {
            if (prevS[adj[i][0]] != -1 || prevS[adj[i][0]] != s[i]) {
                cout << -1 << '\n';
                return;
            }
            prevS[adj[i][0]] = s[i];
            prevAdjCnt[i][s[i]]++;
            prevS[i] = s[adj[i][0]];
            prevAdjCnt[adj[i][0]][s[adj[i][0]]]++;
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}