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

    int h, w;
    cin >> h >> w;
    
    int r, c, d;
    cin >> r >> c >> d;

    vector a(h, vector(w, 0)), b(h, vector(w, 0));

    for(int i = 0 ; i < h; i++) {
        string temp;
        cin >> temp;
        for(int j = 0; j < w; j++) {
            a[i][j] = temp[j] - '0';
        }
    }

    for(int i = 0 ; i < h; i++) {
        string temp;
        cin >> temp;
        for(int j = 0; j < w; j++) {
            b[i][j] = temp[j] - '0';
        }
    }

    int ans = 0;
    vector dust(h, vector(w, 1));

    for(int i = 0; i < 4 * h * h * w * w; i++) {
        if (r < 0 || r >= h || c < 0 || c >= w) {
            break;
        }
        if (dust[r][c]) {
            dust[r][c] = 0;
            ans = i;
            d = (d + a[r][c]) % 4;
            r += dr[d];
            c += dc[d];
        }
        else {
            d = (d + b[r][c]) % 4;
            r += dr[d];
            c += dc[d];
        }
    }

    cout << ans + 1;

    return 0;
}