#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MOD9 = 998244353;
const ll MOD1 = (ll)1e9 + 7;

vector<int> dr = {-1, 0, 1, 0}, dc = {0, 1, 0, -1};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int h, w, n;
    cin >> h >> w >> n;
    vector<string> board(h, string(w, '.'));

    int dir = 0, r = 0, c = 0;
    for(int i = 0; i < n; i++) {
        if (board[r][c] == '.') {
            board[r][c] = '#';
            dir = (dir + 1) % 4;
        }
        else {
            board[r][c] = '.';
            dir = (dir + 3) % 4;
        }
        r = (((r + dr[dir]) % h) + h) % h;
        c = (((c + dc[dir]) % w) + w) % w;
    }

    for(int i = 0; i < h; i++) {
        cout << board[i] << '\n';
    }

    return 0;
}