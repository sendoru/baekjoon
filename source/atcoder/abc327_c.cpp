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

    vector<vector<int>> v(9, vector<int>(9));
    for(int i = 0 ; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cin >> v[i][j];
        }
    }
    bool valid = true;

    // check row
    for(int row = 0; row < 9; row++) {
        int bitmask = 0;
        for (int col = 0; col < 9; col++) {
            bitmask |= (1 << v[row][col]);
        }
        if (bitmask != (1 << 10) - 2) {
            valid = false;
        }
    }

    // check column
    for(int col = 0; col < 9; col++) {
        int bitmask = 0;
        for (int row = 0; row < 9; row++) {
            bitmask |= (1 << v[row][col]);
        }
        if (bitmask != (1 << 10) - 2) {
            valid = false;
        }
    }

    // check subsquare
    for (int outer_row = 0; outer_row < 3; outer_row++) {
        for(int outer_col = 0; outer_col < 3; outer_col++) {
            int bitmask = 0;

            for(int row = 0; row < 3; row++) {
                for(int col = 0; col < 3; col++) {
                    bitmask |= (1 << v[outer_row * 3 + row][outer_col * 3 + col]);
                }
            }

            if (bitmask != (1 << 10) - 2) {
                valid = false;
            }
        }
    }

    cout << (valid ? "Yes": "No");
    return 0;
}