#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
#include <algorithm>
typedef long long ll;
using namespace std;

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

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    MergeSortTree<int> mst(v);
    int m;
    cin >> m;
    while (m--)
    {
        int l, r, k;
        cin >> l >> r >> k;
        l--; r--;
        cout << mst.prod(l, r, k) << '\n';
    }

    return 0;
}