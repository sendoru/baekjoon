#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MOD9 = 998244353;
const ll MOD1 = (ll)1e9 + 7;

ll solveDP(vector<vector<ll>>& dpTable, vector<vector<ll>>& adjMtx, int curNode, int state) {
    if (state == 1 && curNode == 0) {
        return dpTable[curNode][state] = 0;
    }

    if (dpTable[curNode][state] != -1) return dpTable[curNode][state];

    ll& res = dpTable[curNode][state] = 1e9;
    for(int preNode = 1; preNode < dpTable.size(); preNode++) {
        if ((state & (1ll << curNode)) == 0) continue;
        ll c = adjMtx[preNode][curNode] + solveDP(dpTable, adjMtx, preNode, state ^ (1<<curNode));
        res = min(c, res);
    }

    return res;
}

vector<vector<ll>> bfs(vector<string>& a, pii start) {
    vector<vector<ll>> res(a.size(), vector<ll>(a[0].size(), 1e9));
    res[start.first][start.second] = 0;
    queue<pii> q;
    q.push(start);
    vector<int> dr = {1, -1, 0, 0};
    vector<int> dc = {0, 0, -1, 1};
    while(!q.empty()) {
        auto curNode = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            pii nxtNode = {curNode.first + dr[i], curNode.second + dc[i]};
            if (nxtNode.first >= 0 && nxtNode.first < res.size() && nxtNode.second >= 0 && nxtNode.second < res[0].size() && a[nxtNode.first][nxtNode.second] != '#' && res[nxtNode.first][nxtNode.second] >= 1e9) {
                res[nxtNode.first][nxtNode.second] = res[curNode.first][curNode.second] + 1;
                q.push(nxtNode);
            }
        }
    }

    return res;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll h, w, t;
    cin >> h >> w >> t;
    vector<string> a(h);
    for(string& i : a)
        cin >> i;

    pii start, goal;
    vector<pii> candies;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if (a[i][j] == 'S')
                start = {i, j};
            else if (a[i][j] == 'G')
                goal = {i, j};
            else if (a[i][j] == 'o')
                candies.emplace_back(i, j);
        }
    }



    vector<pii> nodes = {start, goal};
    for(auto i : candies) {
        nodes.push_back(i);
    }

    vector<vector<ll>> adjMtx(candies.size() + 2, vector<ll>(candies.size() + 2 , -1));
    // 자기 자긴
    for(int i = 0 ; i < nodes.size(); i++) {
        auto dist = bfs(a, nodes[i]);
        for(int j = 0; j < nodes.size(); j++) {
            adjMtx[i][j] = dist[nodes[j].first][nodes[j].second];
        }
    }

    // 외판원
    // dpTable[루트 마지막 노드][방문한 정점 state]
    vector<vector<ll>> dpTable(nodes.size(), vector<ll>(1 << nodes.size(), -1));

    dpTable[0][1] = 0;
    for(int i = 1; i < dpTable.size(); i++) {
        dpTable[i][(1 << i) + 1] = adjMtx[0][i];
    }
    int ans = -1;
    // solveDP(dpTable, adjMtx, 0, 1);
    for(int i = 3; i < dpTable[1].size(); i += 4) {
        if (i & (1 << 1)) {
            ll dist = solveDP(dpTable, adjMtx, 1, i);
            if (dist <= t) {
                int cur = 0;
                for (int j = 0; j < 31; j++) {
                    if (i & (1 << j)) {
                        cur++;
                    }
                }

                ans = max(ans, cur - 2);
            }
        }
    }


    cout << ans;

    return 0;
}