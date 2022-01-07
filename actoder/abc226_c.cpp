#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<ll> time(n + 1);
    vector<bool> need(n + 1);
    vector<vector<int>> pre(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> time[i];
        int k;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            int a;
            cin >> a;
            pre[i].push_back(a);
        }
    }

    queue<int> q;
    q.push(n);
    need[n] = true;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (auto elem : pre[cur])
        {
            if (!need[elem])
            {
                need[elem] = true;
                q.push(elem);
            }
        }
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (need[i])
        {
            ans += time[i];
        }
    }

    cout << ans;
    return 0;
}