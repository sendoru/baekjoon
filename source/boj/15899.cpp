#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
#include <algorithm>
typedef long long ll;
constexpr ll MOD = 1e9 + 7;
using namespace std;

template <typename S, typename comp = less<S>>
class MergeSortTree
{
private:
    ll _n, size, log;
    vector<vector<S>> d;

    void update(ll k)
    {
        d[k].resize(d[2 * k].size() + d[2 * k + 1].size());
        merge(d[2 * k].begin(), d[2 * k].end(), d[2 * k + 1].begin(), d[2 * k + 1].end(), d[k].begin(), comp());
    }

public:
    MergeSortTree(const std::vector<S>& v)
    {
        _n = v.size();
        log = ceil(log2(_n));
        size = 1ll << log;
        d = vector<vector<S>>(2 * size);
        for (int i = 0; i < _n; i++)
            d[size + i] = { v[i] };
        for (int i = size - 1; i >= 1; i--)
            update(i);
    }

    ll prod(ll l, ll r, S k) const
    {
        assert(0 <= l && l <= r && r <= _n);
        l += size;
        r += size;
        ll ret = 0;

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

void dfs(vector<vector<int>>& adjList, vector<bool>& visited, vector<int>& order, int curNode)
{
    visited[curNode] = true;
    order.push_back(curNode);
    for (auto nextNode : adjList[curNode])
    {
        if (!visited[nextNode])
        {
            dfs(adjList, visited, order, nextNode);
        }
    }
    order.push_back(curNode);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, c;
    cin >> n >> m >> c;
    vector<vector<int>> adjList(n + 1);
    vector<int> colors(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> colors[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        int s, e;
        cin >> s >> e;
        adjList[s].push_back(e);
        adjList[e].push_back(s);
    }

    vector<bool> visited(n + 1);
    vector<int> order;
    dfs(adjList, visited, order, 1);
    vector<vector<int>> pos(n + 1);
    for (int i = 0; i < order.size(); i++)
    {
        int nodeNo = order[i];
        pos[nodeNo].push_back(i);
        order[i] = colors[nodeNo];
    }

    MergeSortTree<int, greater<int>> mst(order);
    ll ans = 0;
    while (m--)
    {
        int nodeNo, clr;
        cin >> nodeNo >> clr;
        ans += mst.prod(pos[nodeNo][0], pos[nodeNo][1], clr + 1) / 2;
        ans %= MOD;
    }
    cout << ans;
    return 0;
}