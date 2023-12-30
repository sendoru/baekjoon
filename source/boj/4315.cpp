//
// Created by sendo on 2023-01-27.
//
//
// Created by sendo on 2023-01-27.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<int> dr = {0, 1, -1, 0, 0}, dc = {0, 0, 0, 1, -1};

ll dist(pll a, pll b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while(true) {
        int n;
        cin >> n;
        if (n == 0)
            break;
        vector<int> cnt(n + 1);
        vector<vector<int>> adjList(n + 1);
        for(int i = 1; i <= n; i++) {
            int no, c, d;
            cin >> no >> c >> d;
            cnt[no] = c - 1;
            while(d--) {
                int nxt;
                cin >> nxt;
                adjList[no].push_back(nxt);
                adjList[nxt].push_back(no);
            }
        }

        vector<int> subtreeSum(n + 1, -1e9);
        vector<int> subtreeAns(n + 1, -2);
        function<int(int)> getSubTreeSum = [&] (int node) -> int {
            if (subtreeSum[node] >= -n)
                return subtreeSum[node];
            int& ret = subtreeSum[node];
            ret = cnt[node];
            for (int& nxt : adjList[node]) {
                if (subtreeSum[nxt] < -n) {
                    ret += getSubTreeSum(nxt);
                }
            }
            return ret;
        };

        getSubTreeSum(1);

        function<int(int)> getSubTreeAns = [&] (int node) -> int {
            if (subtreeAns[node] >= 0)
                return subtreeAns[node];
            int& ret = subtreeAns[node];
            ret = abs(subtreeSum[node]);
            for (int& nxt : adjList[node]) {
                if (subtreeAns[nxt] < 0) {
                    ret += abs(getSubTreeAns(nxt));
                }
            }
            return ret;
        };

        cout << getSubTreeAns(1) << endl;
    }
    return 0;
}