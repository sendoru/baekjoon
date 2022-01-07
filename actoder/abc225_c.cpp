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
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> b(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> b[i][j];
        }
    }

    bool ans = true;
    for (int i = 1; i < m; i++)
    {
        if (b[0][i] != b[0][i - 1] + 1 || b[0][i - 1] % 7 == 0)
        {
            ans = false;
            break;
        }
    }

    if (ans)
    {
        for (int i = 1; i < n; i++)
        {
            if (b[i][0] != b[i - 1][0] + 7)
            {
                ans = false;
                break;
            }
            for (int j = 1; j < m; j++)
            {
                if (b[i][j] != b[i - 1][j] + 7 || b[i][j] != b[i][j - 1] + 1)
                {
                    ans = false;
                    break;
                }
            }
            if (!ans) break;
        }
    }

    cout << (ans ? "Yes" : "No");

    return 0;
}