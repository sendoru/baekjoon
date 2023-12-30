#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;

ll modPow(ll b, ll e)
{
    if (e == 0) return 1;
    ll half = modPow(b, e / 2);
    return (e & 1 ? ((half * half) % MOD * b % MOD) : half * half % MOD);
}

bool reachable(vector<vector<pair<int, int>>>& adj, vector<pair<int, int>>& edges, ll flow)
{
    ll n = adj.size();
    queue<int> q;
    
    q.push(0);
    vector<int> visited(n);
    visited[0] = 1;
    while(!q.empty())
    {
        ll cur = q.front();
        q.pop();
        if (cur == n - 1)
        {
            int s = edges[flow].first, e = edges[flow].second;
            for(auto iter = adj[s].begin(); iter != adj[s].end(); iter++)
            {
                if ((*iter).first == e)
                {
                    adj[s].erase(iter);
                    break;
                }
            }
    
            for(auto iter = adj[e].begin(); iter != adj[e].end(); iter++)
            {
                if ((*iter).first == s)
                {
                    adj[e].erase(iter);
                    break;
                }
            }
            return true;
        }
        
        for(int i = adj[cur].size() - 1; i >= 0; i--)
        {
            int nxt = adj[cur][i].first, cap = adj[cur][i].second;
            if (cap < flow)
                break;
            if (!visited[nxt])
            {
                visited[nxt] = true;
                q.push(nxt);
            }
        }
    }
    
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector < vector < pair < int, int>>> adj(n);
    vector <pair<int, int>> edges;
    for (int i = 0; i < m; i++) {
        ll s, e;
        cin >> s >> e;
        edges.push_back({s, e});
        adj[s].push_back({e, i});
        adj[e].push_back({s, i});
    }
    
    ll ans = 0;
    for (int flow = m - 1; flow >= 0; flow--) {
        if (reachable(adj, edges, flow)) {
            ans += modPow(3, flow);
            ans %= MOD;
        }
    }
    
    cout << ans;
    
    return 0;
}