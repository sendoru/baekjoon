#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
typedef long long ll;
using namespace std;
constexpr ll INF = 1e12;

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

vector<ll> maxSumId()
{

    // 전체구간 합 = 0
    // 조건없음 합 = -INF
    return { -INF, -INF, -INF, -INF };
}

// 각 구간에 대해, 4개의 조건 하에서 연속합의 최댓값을 구해야 할 것 같다.
// 1. 왼쪽 끝을 포함하는 경우
// 2. 오른쪽 끝을 포함하는 경우
// 3. 왼쪽 끝과 오른쪽 끝 전부 포함 (=구간 전체)
// 4. 둘 다 신경 안써도 되는 경우
// kSum[n + 1][4]
// [i][0]: 왼쪽끝
// [i][1]: 오른쪽끝
// [i][2]: 전체구간
// [i][3]: 조건 상관없음

vector<ll> maxSumOP(vector<ll> l, vector<ll> r)
{
    if (l == maxSumId()) return r;
    if (r == maxSumId()) return l;
    vector<ll> ret(4);
    // 0: 왼쪽 끝
    // (l의 왼쪽 끝) or (l의 전체 + r의 왼쪽 끝)
    ret[0] = max(l[0], l[2] + r[0]);
    // 1: 오른쪽 끝
    // (r의 오른쪽 끝) or (r의 전체 + l의 오른쪽 끝)
    ret[1] = max(r[1], r[2] + l[1]);
    // 2: 전체 구간
    // (l의 전체구간 + r의 전체구간)
    ret[2] = l[2] + r[2];
    // 3: 조건 없음
    // (l의 조건없음) or (r의 조건없음) or (l의 오른쪽끝 + r의 왼쪽끝) 
    ret[3] = max(max(l[3], r[3]), l[1] + r[0]);

    return ret;
}


int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	ll n, q, u, v;
	cin >> n >> q >> u >> v;
	vector<ll> k(n);
    // 사실 u랑 v를 직접 쓰는 것보단 그냥 모든 k값에 uk + v가 되어 있다고 생각하고 하는게 더 편할듯 ㅇㅇ...
    // 아 k[0]은 건들면 안되지
    for (int i = 0; i < n; i++)
    {
        cin >> k[i];
        k[i] *= u;
        k[i] += v;
    }

    vector<vector<ll>> kSum(n, vector<ll>(4));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            kSum[i][j] = k[i];
        }
    }

    segtree<vector<ll>, maxSumOP, maxSumId> seg(kSum);
    while (q--)
    {
        ll c, a, b;
        cin >> c >> a >> b;
        // prod
        if (c == 0)
        {
            // atcoder library에서는 prod의 구간이 받닫힌구간이다
            a--;
            b--;
            auto temp = seg.prod(a, b + 1);
            cout << temp[3] - v << '\n';
        }
        //update
        else
        {
            a--;
            vector<ll> newVal(4, u * b + v);
            seg.set(a, newVal);
        }
    }

    return 0;
}