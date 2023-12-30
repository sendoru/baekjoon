#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MOD9 = 998244353;
const ll MOD1 = (ll)1e9 + 7;

template <typename T>
vector<vector<T>> get_perm(vector<T>& v) {
    vector<vector<T>> ret;
    function<void(vector<T>, int)> pick = [&] (vector<T> cur, int toPick) {
        if (toPick == 0) {
            ret.push_back(cur);
            return;
        }
        for(int i = 0; i < v.size(); i++) {
            if (find(cur.begin(), cur.end(), v[i]) == cur.end()) {
                cur.push_back(v[i]);
                pick(cur, toPick - 1);
                cur.pop_back();
            }
        }
    };

    vector<T> cur;
    pick(cur, v.size());

    return ret;
}

bool check(vector<vector<int>>& v) {
    vector<vector<int>> cur = {
            {-1, -2, -3},
            {-4, -5, -6},
            {-7, -8, -9}
    };


    for(auto& elem : v) {

        int r = elem[0], c = elem[1], val = elem[2];
        cur[r][c] = val;
        // 가로 체크
        set<int> s = {cur[r][0], cur[r][1], cur[r][2]};
        if (s.size() == 2 && *s.begin() < 0) {
            return false;
        }
        // 세로 체크
        s = {cur[0][c], cur[1][c], cur[2][c]};
        if (s.size() == 2 && *s.begin() < 0) {
            return false;
        }
        // 대각선 체크
        if (r == c) {
            s = {cur[0][0], cur[1][1], cur[2][2]};
            if (s.size() == 2 && *s.begin() < 0) {
                return false;
            }
        }
        if (r + c == 2) {
            s = {cur[0][2], cur[1][1], cur[2][0]};
            if (s.size() == 2 && *s.begin() < 0) {
                return false;
            }
        }

    }

    return true;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<vector<int>> c(9, vector<int>(3));
    for(int i = 0; i < 9; i++) {
        cin >> c[i][2];
        c[i][0] = i % 3;
        c[i][1] = i / 3;
    }

    vector<vector<vector<int>>> perms = get_perm(c);

    double ans = 0;
    for(int i = 0; i < perms.size(); i++) {
        if (check(perms[i])) {
            ans++;
        }
    }

    cout.precision(12);
    cout << ans / perms.size();

    return 0;
}