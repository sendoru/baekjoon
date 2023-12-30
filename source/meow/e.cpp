#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MOD9 = 998244353;
const ll MOD1 = (ll)1e9 + 7;

vector<vector<int>> bfs(vector<string>& maze, int r, int c) {
    vector<int> dr = {1, -1, 0, 0}, dc = {0, 0, 1, -1};
    vector<vector<int>> ret(maze.size(), vector<int>(maze[0].size(), 1e9));
    ret[r][c] = 0;

    queue<pii> q;
    q.push({r, c});
    while(!q.empty()) {
        int curR = q.front().first, curC = q.front().second;
        q.pop();
        for(int d = 0; d < 4; d++) {
            int nxtR = curR + dr[d], nxtC = curC + dc[d];
            if (nxtR >= 0 && nxtR < maze.size() && nxtC >= 0 && nxtC < maze[0].size()
            && maze[nxtR][nxtC] != 'X' && ret[nxtR][nxtC] > ret[curR][curC] + 1) {
                ret[nxtR][nxtC] = ret[curR][curC] + 1;
                q.push({nxtR, nxtC});
            }
        }
    }

    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<string> maze(n);
    vector<pii> pPos, sPos;
    pii hPos;
    for(int i = 0 ; i < n; i++) {
        cin >> maze[i];
        for (int j = 0; j < m; j++) {
            if (maze[i][j] == 'P') {
                pPos.push_back({i, j});
            }
            else if (maze[i][j] == 'H') {
                hPos = {i, j};
            }
            else if (maze[i][j] == '#') {
                sPos.push_back({i, j});
            }
        }
    }

    int ans = 0;
    vector<vector<int>> hDist = bfs(maze, hPos.first, hPos.second);
    vector<vector<vector<int>>> pDist(pPos.size());
    for(int i = 0; i < pPos.size(); i++) {
        pDist[i] = bfs(maze, pPos[i].first, pPos[i].second);
    }

    for(auto [r, c] : sPos) {
        int cur = 0;
        if (hDist[r][c] > 1e8){
            continue;
        }
        for(int i = 0; i < pPos.size(); i++) {
            if (pDist[i][r][c] <= hDist[r][c]) {
                cur++;
            }
        }
        ans = max(ans, cur);
    }

    cout << ans;

    return 0;
}