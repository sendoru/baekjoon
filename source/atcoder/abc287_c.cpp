//
// Created by sendo on 2023-01-28.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void dfs(vector<vector<int>>& adjList, vector<int>& visited, int curr)
{
    visited[curr] = 1;
    for(int next : adjList[curr]) {
        if (!visited[next]) {
            dfs(adjList, visited, next);
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adjList(n + 1);
    for(int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;
        adjList[s].push_back(e);
        adjList[e].push_back(s);
    }

    bool ans = true;
    if (m != n - 1)
        ans = false;
    else {
        vector<int> visited(n + 1);
        dfs(adjList, visited, 1);
        for(int i = 1; i <= n; i++) {
            if (!visited[i]) {
                ans = false;
                break;
            }
        }
    }

    cout << (ans ? "Yes" : "No");

    return 0;
}