#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 998244353;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> ans(n, vector<int>(n));
    if (n == 3)
    {
        ans[0] = {2, 4, 5};
        ans[1] = {6, 8, 1};
        ans[2] = {3, 7, 9};
    }
    else if (!(n & 1))
    {
        int cur = 2;
        for(int r = 0; r < n/2; r++)
        {
            for(int c = 0; c < n; c++)
            {
                ans[r][(c + 1) % n] = cur;
                cur += 2;
            }
        }
        swap(ans[n/2 - 2][0], ans[n/2 - 1][0]);
        cur = 1;
        for(int r = n/2; r < n; r++)
        {
            for(int c = n - 1; c >= 0; c--)
            {
                ans[r][c] = cur;
                cur += 2;
            }
        }
    }

    else
    {
        vector<int> used(n * n + 1);
        pair<int, int> six;
        int cur = 2;
        for(int c = n/2 + 1; c < n; c++)
        {
            ans[n / 2][c] = cur;
            ans[n / 2 - 1][c] = n * n - cur;
            used[n * n - cur] = true;
            if (cur == 6)
                six = {n/2, c};
            cur += 2;
        }
        for(int c = 0; c <= n/2; c++)
        {
            ans[n / 2  + 1][c] = cur;
            ans[n / 2][c] = n * n - cur;
            used[n * n - cur] = true;
            if (cur == 6)
                six = {n/2 + 1, c};
            cur += 2;
        }

        swap(ans[n/2 + 1][n/2], ans[six.first][six.second]);
        swap(ans[n/2][n/2], ans[six.first - 1][six.second]);

        cur = 1;
        for(int r = 0; r < n/2; r++)
        {
            for(int c = 0; c < n; c++)
            {
                if (ans[r][c] != 0)
                    break;
                ans[r][c] = cur;
                used[cur] = true;
                while(used[cur])
                    cur += 2;
            }
        }

        cur = 2 * n + 2;
        for(int r = n/2 + 1; r < n; r++)
        {
            for(int c = n - 1; c >= 0; c--)
            {
                if (ans[r][c] != 0)
                    break;
                ans[r][c] = cur;
                cur += 2;
            }
        }
    }

    for(auto& r : ans)
    {
        for(auto& elem : r)
        {
            cout << elem << ' ';
        }
        cout << '\n';
    }
    return 0;
}