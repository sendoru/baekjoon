#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
#include <algorithm>
typedef long long ll;
constexpr ll MOD = 1e9 + 7;
using namespace std;

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

ll intSum(ll a, ll b) { return a + b; }
ll zero() { return 0ll; }

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, c;
    cin >> n >> c;
    vector<vector<int>> adjList(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int s, e;
        cin >> s >> e;
        adjList[s].push_back(e);
        adjList[e].push_back(s);
    }

    vector<int> levels(n + 1);
    vector<int> order;
    dfs(adjList, levels, order, c, 1);
    vector<vector<int>> pos(n + 1);
    for (int i = 0; i < order.size(); i++)
    {
        int nodeNo = order[i];
        pos[nodeNo].push_back(i);
    }

    segtree<ll, intSum, zero> st(order.size());
    int q;
    cin >> q;
    while (q--)
    {
        int q1, q2;
        cin >> q1 >> q2;
        if (q1 == 1)
        {
            st.set(pos[q2][0], st.get(pos[q2][0]) + 1);
        }
        else
        {
            cout << st.prod(pos[q2][0], pos[q2][1] + 1) * levels[q2] << '\n';
        }
    }
    return 0;
}