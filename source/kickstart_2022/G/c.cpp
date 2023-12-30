#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll INF = 1e16;

template<typename T, T(*op)(T, T), T id>
class SegTree
{
    vector<T> v;
    ll leafCnt;
    ll height;
    void update(ll k) { v[k] = op(v[2 * k], v[2 * k + 1]); }

public:
    SegTree(ll leafCnt_)
    {
        height = (ll)ceill(log2l(leafCnt_) + 1);
        leafCnt = 1ll << (height - 1);
        v = vector<T>(1ll << height, id);
    }
    SegTree(const vector<T>& orig)
    {
        height = (ll)ceill(log2l(orig.size()) + 1);
        leafCnt = 1ll << (height - 1);
        v = vector<T>(1ll << height, id);
        for (ll i = 0; i < orig.size(); i++)
        {
            v[i + leafCnt] = orig[i];
        }
        for (ll i = height - 1; i > 0; i--)
        {
            for (ll j = (1ll << (i - 1)); j < (1ll << i); j++)
            {
                update(j);
            }
        }
    }

    void set(ll idx, T val)
    {
        assert(idx >= 0 && idx < leafCnt);
        idx += leafCnt;
        v[idx] = val;
        while (!idx != 1)
        {
            idx >>= 1;
            update(idx);
        }
    }

    T get(ll idx)
    {
        assert(idx >= 0 && idx < leafCnt);
        return v[idx + leafCnt];
    }

    T prod(ll l, ll r)
    {
        assert(0 <= l && l <= r && r < leafCnt);
        T ll = id, rr = id;
        l += leafCnt;
        r += leafCnt + 1;
        while (l < r)
        {
            if (l & 1)
            {
                ll = op(ll, v[l]);
                l++;
            }
            if (r & 1)
            {
                rr = op(rr, v[r - 1]);
                r--;
            }
            l >>= 1;
            r >>= 1;
        }

        return op(ll, rr);
    }

    T allProd()
    {
        return v[1];
    }
};

ll minll(ll a, ll b){return a < b ? a : b;}
ll minE(){return -INF;}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        ll n;
        cin >> n;
        vector<ll> a(n + 1);
        for(int i = 1; i <= n; i++)
            cin >> a[i];
        vector<ll> pfSum(n + 1), pfSum2(n + 1);
        for(int i = 1; i <= n; i++)
            pfSum[i] = pfSum[i - 1] + a[i];
        for(int i = 1; i <= n; i++)
            pfSum2[i] = pfSum2[i - 1] + pfSum[i];

        ll ans = 0;
        SegTree<ll, minll, INF> tree(pfSum);
        for(int idx = 1; idx <= n; idx++)
        {
            ll prevSum = pfSum[idx - 1];
            ll l = idx, r = n, opt = 0, m = (l + r) / 2;
            while(l <= r)
            {
                m = (l + r) / 2;
                ll curMin = tree.prod(idx, m);
                if (curMin >= prevSum)
                {
                    opt = max(opt, m);
                    l = m + 1;
                }
                else
                {
                    r = m - 1;
                }
            }

            if (opt >= idx)
            {
                ans += pfSum2[opt] - (opt - idx + 1) * pfSum[idx - 1] - pfSum2[idx - 1];
            }
        }


        cout << "Case #" << t << ": ";
        cout << ans << '\n';
    }

    return 0;
}