#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MOD9 = 998244353;
const ll MOD1 = (ll)1e9 + 7;

int swap_row(int cur, int idx, int h, int w) {
    int high_row;
    high_row = cur >> (idx * w);
    high_row = high_row & ((1 << w) - 1);
    high_row <<= (idx * w);

    int low_row;
    low_row = cur >> ((idx + 1) * w);
    low_row = low_row & ((1 << w) - 1);
    low_row <<= ((idx + 1) * w);

    cur ^= high_row;
    cur ^= low_row;

    high_row <<= w;
    low_row >>= w;

    cur |= high_row;
    cur |= low_row;

    return cur;
}

int swap_col(int cur, int idx, int h, int w) {
    for(int i = 0; i < h; i++) {
        int s1 = (1 << (w * i + idx)) & cur;
        int s2 = (1 << (w * i + idx + 1)) & cur;
        cur ^= s1;
        cur ^= s2;
        s1 <<= 1;
        s2 >>= 1;
        cur |= s1;
        cur |= s2;
    }

    return cur;
}

int bfs(vector<vector<int>> init, vector<vector<int>>& dest, set<vector<vector<int>>>& visited, int cur_dest) {

    queue<pair<vector<vector<int>>, int>> q;
    q.push({init, 0});
    while (!q.empty()){
        auto [cur, dist] = q.front();
        q.pop();
        for(int i = 0; i < cur.size() - 1; i++) {
            vector<vector<int>> next = cur;
            swap(next[i], next[i + 1]);
            if (next == dest) {
                return dist + 1;
            }
            else if (visited.find(next) == visited.end()) {
                visited.insert(next);
                q.push({next, dist + 1});
            }
        }

        for(int i = 0; i < cur[0].size() - 1; i++) {
            vector<vector<int>> next = cur;
            for (auto & j : next) {
                swap(j[i], j[i + 1]);
            }
            if (next == dest) {
                return dist + 1;
            }
            else if (visited.find(next) == visited.end()) {
                visited.insert(next);
                q.push({next, dist + 1});
            }
        }
    }

    return -1;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    auto b = a;
    for(int i = 0 ; i < h; i++){
        for(int j = 0; j < w; j++) {
            cin >> a[i][j];
        }
    }

    for(int i = 0 ; i < h; i++){
        for(int j = 0; j < w; j++) {
            cin >> b[i][j];
        }
    }

    vector<int> a_all, b_all;

    for(auto& elem : a) {
        for (auto i : elem) {
            a_all.push_back(i);
        }
    }
    sort(a_all.begin(), a_all.end());

    for(auto& elem : b) {
        for (auto i : elem) {
            b_all.push_back(i);
        }
    }
    sort(b_all.begin(), b_all.end());

    if (a_all != b_all) {
        cout << -1;
        return 0;
    }

    if (a == b) {
        cout << 0;
        return 0;
    }

    set<vector<vector<int>>> visited;
    int ans = bfs(a, b, visited, 0);
    cout << ans;

    return 0;
}