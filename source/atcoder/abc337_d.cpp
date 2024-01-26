#include <bits/stdc++.h>
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

    int h, w, k;
    cin >> h >> w >> k;
    auto board = vector(h, string());
    for(int i = 0; i < h; i++) {
        cin >> board[i];
    }

    int ans = MOD9;

    // 가로 확인
    if (k <= w) {
        for(int i = 0; i < h; i++) {
            int sum_x = 0, sum_dot = 0;
            for(int j = 0; j < k; j++ ) {
                sum_x += board[i][j] == 'x';
                sum_dot += board[i][j] == '.';
            }

            for (int begin = 0, end = k - 1; end < w; begin++, end++) {
                if (sum_x == 0) {
                    ans = min(ans, sum_dot);
                }
                
                sum_x -= board[i][begin] == 'x';
                sum_dot -= board[i][begin] == '.';

                if (end + 1 < w) {
                    sum_x += board[i][end + 1] == 'x';
                    sum_dot += board[i][end + 1] == '.';
                }
            }
        }
    }

    // 세로 확인

    if (k <= h) {
        for(int i = 0; i < w; i++) {
            int sum_x = 0, sum_dot = 0;
            for(int j = 0; j < k; j++ ) {
                sum_x += board[j][i] == 'x';
                sum_dot += board[j][i] == '.';
            }

            for (int begin = 0, end = k - 1; end < h; begin++, end++) {
                if (sum_x == 0) {
                    ans = min(ans, sum_dot);
                }
                
                sum_x -= board[begin][i] == 'x';
                sum_dot -= board[begin][i] == '.';

                if (end + 1 < h) {
                    sum_x += board[end + 1][i] == 'x';
                    sum_dot += board[end + 1][i] == '.';
                }
            }
        }
    }

    cout << (ans == MOD9 ? -1 : ans);

    return 0;
}