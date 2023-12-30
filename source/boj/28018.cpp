#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MOD9 = 998244353;
const ll MOD1 = (ll)1e9 + 7;

class Dsu {
private:
    vector<int> parents;
public:
    explicit Dsu(int n) {
        parents.resize(n);
        for(int i = 0; i < n; i++) {
            parents[i] = i;
        }
    }

    size_t size() {
        return parents.size();
    }

    int find_parent(int x) {
        if (parents[x] == x) {
            return x;
        }
        return parents[x] = find_parent(parents[x]);
    }

    int has_same_parents(int x, int y) {
        return find_parent(x) == find_parent(y);
    }

    void unite(int x, int y) {
        if (has_same_parents(x, y)) {
            return;
        }
        int x_parent = find_parent(x), y_parent = find_parent(y);
        parents[x_parent] = y_parent;
    }
};

void dfs(vector<vector<pll>>& adj_list, vector<ll>& dist, vector<bool>& is_leaf, int node, ll cur_dist) {
    dist[node] = cur_dist;
    is_leaf[node] = true;
    for(auto elem : adj_list[node]) {
        ll next_node = elem.first, weight = elem.second;
        if (dist[next_node] == -1) {
            is_leaf[node] = false;
            dfs(adj_list, dist, is_leaf, next_node, cur_dist + weight);
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<ll>> edges;
    for(int i = 0 ; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        edges.push_back({c,a,b});
    }

    sort(edges.begin(), edges.end(), greater<>());

    vector<vector<ll>> mst_edges;
    ll mst_weight = 0;

    Dsu dsu(n + 1);
    for(auto elem : edges) {
        if (!dsu.has_same_parents(elem[1], elem[2])) {
            dsu.unite(elem[1], elem[2]);
            mst_edges.push_back(elem);
            mst_weight += elem[0];
        }
    }

    vector<vector<pll>> adj_list(n + 1);
    for (auto elem : mst_edges) {
        adj_list[elem[1]].push_back({elem[2], elem[0]});
        adj_list[elem[2]].push_back({elem[1], elem[0]});
    }

    int start;
    cin >> start;
    vector<ll> dist(n + 1, -1);
    vector<bool> is_leaf(n + 1);
    dfs(adj_list, dist, is_leaf, start, 0);

    // 2 * (MST 내의 간선 가중치 합) - (시작 정점에서 어떤 리프 노드까지의 거리 중 최솟값)
    // 귀찮아a

    ll min_leaf_dist = 0;
    for(int i = 1; i <= n; i++) {
        if (is_leaf[i] && min_leaf_dist < dist[i]) {
            min_leaf_dist = dist[i];
        }
    };

    cout << mst_weight * 2 - min_leaf_dist;
    return 0;
}