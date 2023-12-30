#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int s, e;
        cin >> s >> e;
        graph[s].push_back(e);
        graph[e].push_back(s);
    }

    bool ans = false;
    for (int i = 1; i <= n; i++)
    {
        if (graph[i].size() == n - 1)
        {
            ans = true;
            break;
        }
    }

    cout << (ans ? "Yes" : "No");

    return 0;
}