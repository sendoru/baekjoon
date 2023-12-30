#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template <typename T, typename comp = less<T>>
class MergeSortTree
{
    ll n;
    vector<vector<T>> d;
    
    void update(ll k)
    {
        d[k].resize(d[2 * k].size() + d[2 * k + 1].size());
        merge(d[2 * k].begin(), d[2 * k].end(), d[2 * k + 1].begin(), d[2 * k + 1].end(), d[k].begin(), comp());
    }

public:
    MergeSortTree(vector<T>& v)
    {
        n = v.size();
        ll log = ceil(log2(n));
        n = 1ll << log;
        d = vector<vector<T>>(2 * n);
        for (int i = 0; i < v.size(); i++)
            d[n + i] = { v[i] };
        for (int i = n - 1; i >= 1; i--)
            update(i);
    }
    
    ll get_upper(ll l, ll r, T k) const
    {
        l += n;
        r += n + 1;
        ll ret = 0;
        
        while (l < r)
        {
            if (l & 1)
            {
                ret += upper_bound(d[l].begin(), d[l].end(), k, comp()) - d[l].begin();
                l++;
            }
            if (r & 1)
            {
                r--;
                ret += upper_bound(d[r].begin(), d[r].end(), k, comp()) - d[r].begin();
            }
            l >>= 1;
            r >>= 1;
        }
        return ret;
    }
    
    ll get_lower(ll l, ll r, T k) const
    {
        l += n;
        r += n + 1;
        ll ret = 0;
        
        while (l < r)
        {
            if (l & 1)
            {
                ret += lower_bound(d[l].begin(), d[l].end(), k, comp()) - d[l].begin();
                l++;
            }
            if (r & 1)
            {
                r--;
                ret += lower_bound(d[r].begin(), d[r].end(), k, comp()) - d[r].begin();
            }
            l >>= 1;
            r >>= 1;
        }
        return ret;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    vector<ll> v(n);
    for(auto& elem:v)
        cin >> elem;
    
    MergeSortTree<ll> mst(v);
    
    while(q--)
    {
        ll l, r, k;
        cin >> l >> r >> k;
        l--;
        r--;
        ll lb = -(1e9), ub = 1e9, m = 0;
        
        while(lb <= ub)
        {
            // get_upper: m 이하인 값의 갯수 반환
            // get_lower: m 미만인 값의 갯수 반환
            // k = 3이라면, 3번째 값을 찾는 것이므로 m 미만의 값이 2개, 이하의 값이 3개
            // 일반화 -> get_upper(m) == k && get_lower(m) == k - 1이어야 함
            m = (lb + ub) / 2;
            ll beq = mst.get_upper(l, r, m), below = mst.get_lower(l, r, m);
            if (beq == k && below == k - 1)
            {
                cout << m << '\n';
                break;
            }
            else if (beq < k || below < k - 1)
                lb = m + 1;
            else
                ub = m - 1;
        }
    }
    
    return 0;
}