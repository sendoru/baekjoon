#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MOD9 = 998244353;
const ll MOD1 = (ll)1e9 + 7;

// from atcoder library
template <class S, S(*op)(S, S), S(*e)()> struct segtree {
public:
    segtree() : segtree(0) {}
    explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}
    explicit segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = ceil(log2(_n));
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) const {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() const { return d[1]; }

    template <bool (*f)(S)> int max_right(int l) const {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) const {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*f)(S)> int min_left(int r) const {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) const {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

private:
    int _n, size, log;
    std::vector<S> d;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

template <typename S, typename comp = less<S>>
class MergeSortTree
{
private:
    int _n, size, log;
    vector<vector<S>> d;

    void update(int k)
    {
        d[k].resize(d[2 * k].size() + d[2 * k + 1].size());
        merge(d[2 * k].begin(), d[2 * k].end(), d[2 * k + 1].begin(), d[2 * k + 1].end(), d[k].begin(), comp());
    }

public:
    MergeSortTree(const std::vector<S>& v)
    {
        _n = v.size();
        log = ceil(log2(_n));
        size = 1 << log;
        d = vector<vector<S>>(2 * size);
        for (int i = 0; i < _n; i++)
            d[size + i] = { v[i] };
        for (int i = size - 1; i >= 1; i--)
            update(i);
    }

    S prod(int l, int r, S k) const
    {
        assert(0 <= l && l <= r && r <= _n);
        l += size;
        r += size;
        int ret = 0;

        while (l <= r)
        {
            if (l & 1)
            {
                ret += d[l].end() - upper_bound(d[l].begin(), d[l].end(), k, comp());
                l++;
            }
            if (!(r & 1))
            {
                ret += d[r].end() - upper_bound(d[r].begin(), d[r].end(), k, comp());
                r--;
            }
            l >>= 1;
            r >>= 1;
        }
        return ret;
    }
};

void dfs(vector<vector<int>>& adjList, vector<int>& levels, vector<int>& order, int curNode, int curLevel)
{
    levels[curNode] = curLevel;
    order.push_back(curNode);
    for (auto nextNode : adjList[curNode])
    {
        if (!levels[nextNode])
        {
            dfs(adjList, levels, order, nextNode, curLevel + 1);
        }
    }
    order.push_back(curNode);
}

ll tree_dp(vector<vector<int>>& adjList, vector<ll>& dp, MergeSortTree<int>& mst, vector<vector<int>>& pos, int curNode) {
    // curNode 자식들 중 자기보다 번호 낮은놈들 갯수
    ll& ret = dp[curNode] = (pos[curNode][1] - pos[curNode][0] + 1 - mst.prod(pos[curNode][0], pos[curNode][1], curNode)) / 2 - 1;
    for(auto next: adjList[curNode]) {
        if (dp[next] == -1) {
            ret += tree_dp(adjList, dp, mst, pos, next);
        }
    }
    return ret;
}

ll tree_dp_2 (vector<vector<int>>& adjList, vector<ll>& dp_before, vector<ll>& dp, MergeSortTree<int>& mst, vector<vector<int>>& pos, int curNode, int par) {
    if (par != -1) {
        dp[curNode] = dp[par];
        // curNode 서브트리 노드들 중 par보다 번호 낮은놈들 갯수 곱하기 2
        dp[curNode] -= (pos[curNode][1] - pos[curNode][0] + 1 - mst.prod(pos[curNode][0], pos[curNode][1], par)) / 2;
        dp[curNode] -= (pos[curNode][1] - pos[curNode][0] + 1 - mst.prod(pos[curNode][0], pos[curNode][1], curNode)) / 2 - 1;
        // 전체 노드들 중 curNode보다 작은놈 갯수
        dp[curNode] += (pos[1][1] - pos[1][0] + 1 - mst.prod(pos[1][0], pos[1][1], curNode)) / 2 - 1;
    }
    else {
        dp[curNode] = dp_before[curNode];
    }
    for (auto next: adjList[curNode]) {
        if (dp[next] == -1) {
            tree_dp_2(adjList, dp_before, dp, mst, pos, next, curNode);
        }
    }
    return dp[curNode];
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < n - 1; i++) {
        int s, e;
        cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    int c = 1;
    vector<int> levels(n + 1);
    vector<int> order;
    dfs(adj, levels, order, c, 1);
    vector<vector<int>> pos(n + 1);
    for (int i = 0; i < order.size(); i++)
    {
        int nodeNo = order[i];
        pos[nodeNo].push_back(i);
    }

    vector<int>segtree_base (order.size());
    for(int i = 1; i < pos.size(); i++) {
        segtree_base[pos[i][0]] = i;
        segtree_base[pos[i][1]] = i;
    }

    MergeSortTree<int> mst(segtree_base);
    vector<ll> inversion_cnt(n + 1, -1);

    // 이제 1번 노드에 대한 건 구했슴
    tree_dp(adj, inversion_cnt, mst, pos, 1);

    vector<ll> inversion_cnt_2(n + 1, -1);
    inversion_cnt_2[1] = inversion_cnt[1];
    tree_dp_2(adj, inversion_cnt, inversion_cnt_2, mst, pos, 1, -1);

    for(int i = 1; i <= n; i++) {
        cout << inversion_cnt_2[i] << ' ';
    }

    return 0;
}