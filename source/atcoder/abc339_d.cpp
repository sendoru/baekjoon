#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MOD9 = 998244353;
const ll MOD1 = (ll)1e9 + 7;

vector<int> dr = {-1, 0, 1, 0}, dc = {0, 1, 0, -1};

bool is_valid(int r, int c, int n) {
    return r >= 0 && r < n && c >= 0 && c < n;
}

int solve(vector<string>& board) {
    int n = board.size();
    vector<int> init_pos;
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board.size(); j++) {
            if (board[i][j] == 'P') {
                init_pos.push_back(i);
                init_pos.push_back(j);
            }
        }
    }


    vector visited(n, vector(n, vector(n, vector(n, 0))));
    visited[init_pos[0]][init_pos[1]][init_pos[2]][init_pos[3]] = 1;
    queue<pair<int, vector<int>>> q;
    q.push({0, init_pos});
    while(!q.empty()) {
        auto [dist, pos] = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            int next_r0 = pos[0] + dr[i],
                next_c0 = pos[1] + dc[i],
                next_r1 = pos[2] + dr[i],
                next_c1 = pos[3] + dc[i];
            if (!is_valid(next_r0, next_c0, board.size()) || board[next_r0][next_c0] == '#') {
                next_r0 = pos[0], next_c0 = pos[1];
            }
            if (!is_valid(next_r1, next_c1, board.size()) || board[next_r1][next_c1] == '#') {
                next_r1 = pos[2], next_c1 = pos[3];
            }

            if (next_r0 == next_r1 && next_c0 == next_c1) {
                return dist + 1;
            }

            if (!visited[next_r0][next_c0][next_r1][next_c1]) {
                visited[next_r0][next_c0][next_r1][next_c1] = 1;
                q.push({dist + 1, {next_r0, next_c0, next_r1, next_c1}});
            }
        }
    }

    return -1;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<string> board(n);
    for(int i = 0; i < n; i++) {
        cin >> board[i];
    }

    cout << solve(board);

    return 0;
}