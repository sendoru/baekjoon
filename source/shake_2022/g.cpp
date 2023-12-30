// 참고 코드 : https://www.acmicpc.net/source/share/481b4ad3718a44d49089494565132e2b
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MOD9 = 998244353;
const ll MOD1 = (ll)1e9 + 7;

void treeDP(vector<vector<pair<ll, ll>>>& adjList, ll curNode, vector<ll>& subtreeSize, vector<ll>& dist, vector<bool>& visited)
{
    visited[curNode] = true;
    if (curNode != 1 && adjList[curNode].size() == 1)
    {
        subtreeSize[curNode] = 1;
        return;
    }

    for (auto edge : adjList[curNode])
    {
        ll nextNode = edge.first, nextDist = edge.second;
        if (!visited[nextNode])
        {
            visited[nextNode] = true;
            dist[nextNode] = dist[curNode] + nextDist;
            treeDP(adjList, nextNode, subtreeSize, dist, visited);
            subtreeSize[curNode] += subtreeSize[nextNode];
        }
    }
    subtreeSize[curNode] += 1;
}

vector<ll> solve(vector<vector<pair<ll, ll>>>& adjList)
{
    vector<ll> ret(adjList.size(), -1);
    int treeSize = adjList.size() - 1;

    vector<ll> dist(treeSize + 1), subtreeSize(treeSize + 1);
    vector<bool> visited(treeSize + 1);

    treeDP(adjList, 1, subtreeSize, dist, visited);
    ret[1] = 0;
    for (int i = 2; i < dist.size(); i++)
        ret[1] += dist[i];

    queue<pair<ll, ll>> q;
    q.push({ 1, 0 });
    while (!q.empty())
    {
        ll curNode = q.front().first, curDist = q.front().second;
        q.pop();

        for (auto& edge : adjList[curNode])
        {
            ll nextNode = edge.first, nextDist = edge.second;
            if (ret[nextNode] == -1)
            {
                ret[nextNode] = ret[curNode] + nextDist * (treeSize - 2 * subtreeSize[nextNode]);
                q.push(edge);
            }
        }
    }

    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n;
    cin >> n;
    vector<vector<pair<ll, ll>>> e(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v, d;
        cin >> u >> v >> d;
        e[u].push_back({ v, d });
        e[v].push_back({ u, d });
    }

    ll m;
    cin >> m;
    vector<vector<pair<ll, ll>>> w(m + 1);
    for (int i = 0; i < m - 1; i++)
    {
        int u, v, d;
        cin >> u >> v >> d;
        w[u].push_back({ v, d });
        w[v].push_back({ u, d });
    }

    auto eMinDist = solve(e);
    auto eVer = min_element(eMinDist.begin() + 1, eMinDist.end()) - eMinDist.begin();
    auto wMinDist = solve(w);
    auto wVer =  min_element(wMinDist.begin() + 1, wMinDist.end()) - wMinDist.begin();

    cout << eVer << ' ' << wVer << '\n';
    ll minDist = m * (eMinDist[eVer]) + n * wMinDist[wVer] + (ll)(n * m);
    cout << minDist;

    return 0;
}