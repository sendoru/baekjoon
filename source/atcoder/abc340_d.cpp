#include <bits/stdc++.h>
// #include "atcoder/all"
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MOD9 = 998244353;
const ll MOD1 = (ll)1e9 + 7;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    ll n;
    cin >> n;
    vector<ll> a(n), b(n), x(n);
    for(int i = 0; i < n - 1; i++) {
        cin >> a[i] >> b[i] >> x[i];
        x[i]--;
    }

    vector<ll> dist(n, 1e17);
    dist[0] = 0;
    priority_queue<pll, vector<pll>, greater<>> pq;
    pq.push({0, 0});
    while(!pq.empty()) {
        auto [cur_dist, cur_node] = pq.top();
        pq.pop();
        
        if (cur_node != n - 1 && dist[cur_node + 1] > cur_dist + a[cur_node]) {
            dist[cur_node + 1] = cur_dist + a[cur_node];
            pq.push({cur_dist + a[cur_node], cur_node + 1});
        }

        if (cur_node != n - 1 && dist[x[cur_node]] > cur_dist + b[cur_node]) {
            dist[x[cur_node]] = cur_dist + b[cur_node];
            pq.push({cur_dist + b[cur_node], x[cur_node]});
        }
    }

    cout << dist[n - 1];

    return 0;
}