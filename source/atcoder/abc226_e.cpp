#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <algorithm>
using namespace std;
typedef long long ll;
constexpr ll MOD = 998244353;

ll modPow(ll base, ll exp)
{
    if (exp == 0) return 1ll;
    if (exp % 2 == 0) return modPow(base, exp / 2) * modPow(base, exp / 2) % MOD;
    else return (base * (modPow(base, exp / 2) * modPow(base, exp / 2)) % MOD) % MOD;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<set<int>> graph(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].insert(v);
        graph[v].insert(u);
    }

    bool valid = true;

    for (int i = 1; i <= n; i++)
    {
        if (graph[i].size() == 0)
        {
            valid = false;
            break;
        }
    }

    if (valid)
    {
        queue<int> q;
        for (int i = 1; i <= n; i++)
        {
            if (graph[i].size() == 1)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int curNode = q.front();
            q.pop();
            int nextNode = *(graph[curNode].begin());
            graph[curNode].clear();
            graph[nextNode].erase(curNode);
            if (graph[nextNode].size() == 0)
            {
                valid = false;
                break;
            }
            else if (graph[nextNode].size() == 1)
            {
                q.push(nextNode);
            }
        }
    }

    if (valid)
    {
        for (int i = 1; i <= n; i++)
        {
            if (graph[i].size() > 2)
            {
                valid = false;
                break;
            }
        }
    }

    ll ans = 0;
    ll loopCnt = 0;
    if (valid)
    {
        vector<bool> visited(n + 1);
        for (int i = 1; i <= n; i++)
        {
            if (graph[i].size() == 2 && !visited[i])
            {
                loopCnt++;
                queue<int> q;
                q.push(i);
                visited[i] = true;
                while (!q.empty())
                {
                    int curNode = q.front();
                    q.pop();
                    for (auto nextNode : graph[curNode])
                    {
                        if (!visited[nextNode])
                        {
                            q.push(nextNode);
                            visited[nextNode] = true;
                        }
                    }
                }
            }
        }
    }

    if (!valid)
    {
        cout << 0;
    }
    else
    {
        cout << modPow(2, loopCnt);
    }

    return 0;
}