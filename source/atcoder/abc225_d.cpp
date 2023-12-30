#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <set>
#include <algorithm>
typedef long long ll;
using namespace std;


int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector<int> next(n + 1, -1);
    vector<int> prev(n + 1, -1);
    for (int i = 0; i < q; i++)
    {
        int q1;
        cin >> q1;
        if (q1 == 1)
        {
            int x, y;
            cin >> x >> y;
            next[y] = x;
            prev[x] = y;
        }
        else if (q1 == 2)
        {
            int x, y;
            cin >> x >> y;
            next[y] = -1;
            prev[x] = -1;
        }
        else if (q1 == 3)
        {
            int x;
            cin >> x;
            vector<int> ans;
            int cur = x;
            while (cur != -1)
            {
                ans.push_back(cur);
                cur = next[cur];
            }
            reverse(ans.begin(), ans.end());
            cur = prev[x];
            while (cur != -1)
            {
                ans.push_back(cur);
                cur = prev[cur];
            }
            cout << ans.size() << ' ';
            for (auto elem : ans) cout << elem << ' ';
            cout << '\n';
        }
    }


    return 0;
}