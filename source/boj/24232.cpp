#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

ll n;
vector<ll> subtreeSize;
vector<ll> subtreeCosts;
vector<ll> totalCosts;
vector<int> ans;
vector<int> visited;
vector<vector<vector<ll>>> adjList;

void getSubtreeSize(int cur)
{
    subtreeSize[cur] = 1;
    for (auto nxt : adjList[cur])
    {
        ll nxtNode = nxt[0], nxtCost = nxt[1];
        if (subtreeSize[nxtNode] == -1)
        {
            getSubtreeSize(nxtNode);
            subtreeSize[cur] += subtreeSize[nxtNode];
        }
    }
}

void getSubtreeCosts(int cur)
{
    subtreeCosts[cur] = 0;
    for (auto nxt : adjList[cur])
    {
        ll nxtNode = nxt[0], nxtCost = nxt[1];
        if (subtreeCosts[nxtNode] == -1)
        {
            getSubtreeCosts(nxtNode);
            subtreeCosts[cur] += subtreeCosts[nxtNode];
            subtreeCosts[cur] += nxtCost;
        }
    }
}

void getTotalCosts(int cur, int par, ll toCurCost)
{
    totalCosts[cur] = subtreeCosts[cur];
    if (cur != par)
    {
        ll remainCost = totalCosts[par] - subtreeCosts[cur] - toCurCost;
        // n - subTreeSize
        totalCosts[cur] += remainCost;
        totalCosts[cur] += (1 - toCurCost);
    }
    for (auto nxt : adjList[cur])
    {
        ll nxtNode = nxt[0], nxtCost = nxt[1];
        if (totalCosts[nxtNode] == -1)
        {
            getTotalCosts(nxtNode, cur, nxtCost);
        }
    }
}

void getAns(int cur)
{
    visited[cur] = true;
    for(auto nxt : adjList[cur])
    {
        int nxtNode = nxt[0], nxtCost = nxt[1], edgeIdx = nxt[2];
        if (!visited[nxtNode])
        {
            ans[edgeIdx] = nxtCost;
            getAns(nxtNode);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    subtreeSize = vector<ll>(n + 1, -1);
    subtreeCosts = vector<ll>(n + 1, -1);
    totalCosts = vector<ll>(n + 1, -1);
    ans = vector<int>(n + 1, -1);
    visited = vector<int>(n + 1, 0);
    // nxt, cost, 간선 번호
    adjList = vector<vector<vector<ll>>>(n + 1);
    for(ll i = 1; i <= n - 1; i++)
    {
        ll s, e;
        cin >> s >> e;
        adjList[s].push_back({e, 0, i});
        adjList[e].push_back({s, 1, i});
    }

    getSubtreeSize(1);
    getSubtreeCosts(1);
    getTotalCosts(1, 1, 0);

    ll root = min_element(totalCosts.begin() + 1, totalCosts.end()) - totalCosts.begin();
    getAns(root);
    for(int i = 1; i <= n - 1; i++)
        cout << ans[i];

    return 0;
}