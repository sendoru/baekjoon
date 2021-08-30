#include <iostream>
#include <deque>
#include <map>

using namespace std;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int bfs(int cy, int cx, int keys, int h, int w, char board[][105], map<char, pair<int, int>>& keyLoc) {
    int res = 0;
    deque<pair<int, int>> queue;
    int visited[105][105] = { 0, };
    queue.push_back(make_pair(cy, cx));
    visited[cy][cx] = 1;
    while (!queue.empty()) {
        int cy, cx;
        cy = queue.front().first;
        cx = queue.front().second;
        queue.pop_front();
        for (int i = 0; i < 4; i++) {
            int vy = cy + dy[i];
            int vx = cx + dx[i];
            if (vy > -1 && vy < h + 2 && vx > -1 && vx < w + 2 && visited[vy][vx] == 0 && board[vy][vx] != '*') {
                if (board[vy][vx] > 96) { // 소문자
                    if (((1 << (board[vy][vx] - 'a')) & keys) != (1 << (board[vy][vx] - 'a'))) {
                        keys |= (1 << (board[vy][vx] - 'a'));
                        return bfs(keyLoc[board[vy][vx] - 32].first, keyLoc[board[vy][vx] - 32].second, keys, h, w, board, keyLoc);
                    }
                    visited[vy][vx] = 1;
                    queue.push_back(make_pair(vy, vx));
                }
                else if (64 < board[vy][vx] && board[vy][vx] < 91) { // 대문자
                    if (((1 << (board[vy][vx] - 'A')) & keys) == (1 << (board[vy][vx] - 'A'))) {
                        visited[vy][vx] = 1;
                        queue.push_back(make_pair(vy, vx));
                    }
                }
                else { // 그외
                    if (board[vy][vx] == '$') res++;
                    visited[vy][vx] = 1;
                    queue.push_back(make_pair(vy, vx));
                }
            }
        }
    }
    return res;
}

void solve() {
    int h, w;
    char board[105][105] = { 0, };
    map<char, pair<int, int>> keyLoc; // 대문자 좌표 맵
    cin >> h >> w;
    int keys = 1 << ('{' - 'a');
    string tmp;
    for (int i = 0; i < h + 2; i++) {
        string tmp;
        if (i == 0 || i == h + 1) for (int j = 0; j < w + 2; j++) board[i][j] = '.';
        else {
            string tmp2 = ".";
            cin >> tmp;
            tmp2 += tmp + ".";
            for (int j = 0; j < tmp2.length(); j++) {
                board[i][j] = tmp2[j];
                if (64 < board[i][j] && board[i][j] < 91) keyLoc.insert(make_pair(board[i][j], make_pair(i, j)));
            }
        }
    }
    cin >> tmp;
    if (tmp != "0")
        for (char elem : tmp) keys |= 1 << (elem - 'a');
    cout << bfs(0, 0, keys, h, w, board, keyLoc) << endl;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) solve();
}
