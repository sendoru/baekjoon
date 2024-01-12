#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

const ll MOD9 = 998244353;
const ll MOD1 = (ll)1e9 + 7;

const int K_MAX = 500;

vector<vector<int>> mat_mul(vector<vector<int>>& a, vector<vector<int>>& b) {
    if (a[0].size() != b.size()) {
        raise(-1);
    }
    vector<vector<int>> ret(a.size(), vector<int>(b[0].size()));

    // a의 행
    for(int i = 0; i < a.size(); i++) {
        // a의 열 and b의 행
        for(int j = 0; j < a[0].size(); j++) {
            // b의 열
            for(int k = 0; k < b[0].size(); k++) {
                ret[i][k] += a[i][j] * b[j][k];
            }
        }
    }

    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vi height(n);
    for(int i = 0 ; i < n; i++) {
        cin >> height[i];
    }

    vvi adj_mat(n, vi(n));
    for(int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;
        s--;
        e--;

        adj_mat[s][e] = 1;
        adj_mat[e][s] = 1;
    }

    vvvi adj_mat_pow(K_MAX + 1, adj_mat);
    for(int i = 2; i <= K_MAX; i++) {
        adj_mat_pow[i] = mat_mul(adj_mat_pow[i - 1], adj_mat);
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                adj_mat_pow[i][j][k] = min(1, adj_mat_pow[i][j][k]);
            }
        }
    }

    int t;
    cin >> t;
    while (t--)
    {
        int a, k;
        cin >> a >> k;
        a--;
        int ans = MOD9;
        for(int i = 0; i < n; i++) {
            if (adj_mat_pow[k][a][i]) {
                ans = min(ans, height[i]);
            }
        }

        if (ans == MOD9) {
            ans = -1;
        }

        cout << ans << '\n';
    }
    
    return 0;
}