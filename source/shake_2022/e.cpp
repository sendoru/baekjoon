#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MOD9 = 998244353;
const ll MOD1 = (ll)1e9 + 7;

map<vector<int>, int> dp;
int a[500][500];
int prefixSum[500][500];
int n;

//int solveDP(int x, int y, int l) {
//    if (y == n) return 0;
//    if (l > x) return MOD1;
//    int& ret = dp[x][y][l];
//    if (ret < MOD1) return ret;
//    if (l == 0) return ret = a[x][y] + solveDP(x, y + 1, 0);
//    return ret = min(a[x][y] + solveDP(x, y + 1, l), solveDP(x - l, y, 0));
//}

template <typename T, typename op, T e>
class SegTree {
    vector<T> data;
    ll n;
public:
    SegTree(ll _n) {
        ll h = 0;
        while ((1 << h) < 2 * _n)
            h++;

        data = vector<T>(1 << h, e);
        n = 1 << (h - 1);
    }

    SegTree(vector<T>& v) {
        ll _n = v.size();
        ll h = 0;
        while ((1 << h) < 2 * _n)
            h++;

        data = vector<T>(1 << h, e);
        n = 1 << (h - 1);

        for(int i = 0; i < v.size(); i++)
            data[i + n] = v[i];
        for(int i = n - 1; i >= 1; i--)
            data[i] = op()(data[2 * i], data[2 * i + 1]);
    }

    void set(ll idx, T val) {
        idx += n;
        data[idx] = val;
        while (idx != 1) {
            idx >>= 1;
            data[idx] = op()(data[2 * idx], data[2 * idx + 1]);
        }
    }

    T get(ll idx) {
        return data[idx + n];
    }

    T get(ll l, ll r) {
        l += n;
        r += n + 1;
        ll ret = e;
        while (l < r) {
            if (l & 1) {
                ret = op()(ret, data[l]);
                l++;
            }
            if (r & 1) {
                r--;
                ret = op()(data[r], ret);
            }
            l >>= 1;
            r >>= 1;
        }
        return ret;
    }
};

struct op {
    int operator()(int a, int b) {
        return min(a, b);
    }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int q;
    cin >> n >> q;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        prefixSum[i][n - 1] = a[i][n - 1];
        for(int j = n - 2; j >= 0; j--) {
            prefixSum[i][j] = prefixSum[i][j + 1] + a[i][j];
        }
    }

    vector<SegTree<int, op, (int)MOD1>> segs(n, SegTree<int, op, (int)MOD1>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            segs[i].set(j, prefixSum[j][i]);
        }
    }

    while(q--) {
        int sx, sy, l;
        cin >> sx >> sy >> l;
        sx--;
        sy--;
        int ans = prefixSum[sx][sy];
        for(int i = sy; i < n - 1; i++) {
            ans = min(ans, prefixSum[sx][sy] - prefixSum[sx][i] + segs[i].get(0, sx - l));
        }
        cout << ans << '\n';
    }

    return 0;
}