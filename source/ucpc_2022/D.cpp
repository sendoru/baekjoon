#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
#include <algorithm>
typedef long long ll;
constexpr ll MOD = 1e9 + 7;
using namespace std;
using pii = pair<int, int>;

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

ll intSum(ll a, ll b) { return a + b; }
ll zero() { return 0ll; }

using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct fenwick {
    vector<int> tree;

    void update(int x, int v) {
        for (x++; x < tree.size(); x += x & -x)
            tree[x] += v;
    }

    int sum(int x) {
        int ret = 0;
        for (x++; x > 0; x -= x & -x)
            ret += tree[x];
        return ret;
    }
};

void solve() {
    int q;
    cin >> q;
    vector<tuple<int, ll, ll>> qs(q);
    vector<ll> xs;
    xs.push_back(-1e18 - 7);
    xs.push_back(1e18 + 7);
    for (auto& [qtype, a, b] : qs) {
        cin >> qtype;
        if (qtype == 1) {
            cin >> a >> b;
            if (a < 0) {
                if (abs(b) % (-a) == 0) {
                    xs.push_back(-b / a);
                }
                if (b < 0) {
                    xs.push_back((-b) / (-a));
                }
                else {
                    xs.push_back(b / (-a) + (b % (-a) > 0));
                }
            }
            else if (a > 0) {
                if (abs(b) % a == 0) {
                    xs.push_back(-b / a);
                }
                if (b < 0) {
                    xs.push_back((-b) / a + ((-b) % a > 0));
                }
                else {
                    xs.push_back(b / a);
                }
            }
        }
        else {
            cin >> a;
            xs.push_back(a);
        }
    }

    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    fenwick ft, zero;
    ft.tree.resize(xs.size() + 10);
    zero.tree.resize(xs.size() + 10);
    auto to = [&](ll x) -> int {
        return lower_bound(xs.begin(), xs.end(), x) - xs.begin();
    };

    for (auto& [qtype, a, b] : qs) {
        if (qtype == 1) {
            if (a == 0) {
                if (b == 0)
                    zero.update(0, 1);
                else if (b < 0)
                    ft.update(0, 1);
            }
            else if (a < 0) {
                if (abs(b) % (-a) == 0) {
                    zero.update(to(-b / a), 1);
                    zero.update(to(-b / a) + 1, -1);
                }
                if (b < 0) {
                    ft.update(to((-b) / (-a)), 1);
                }
                else {
                    ft.update(to(b / (-a) + (b % (-a) > 0)), 1);
                }
            }
            else {
                if (abs(b) % a == 0) {
                    zero.update(to(-b / a), 1);
                    zero.update(to(-b / a) + 1, -1);
                }
                if (b < 0) {
                    ft.update(0, 1);
                    ft.update(to((-b) / a + ((-b) % a > 0)), -1);
                }
                else {
                    ft.update(0, 1);
                    ft.update(to(b / a), -1);
                }
            }
        }
        else {
            //            cout << zero.sum(to(a)) << ' ' << ft.sum(to(a)) << '\n';
            if (zero.sum(to(a)) > 0)
                cout << "0\n";
            else
                cout << (ft.sum(to(a)) % 2 ? "-\n" : "+\n");
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
