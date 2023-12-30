#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
typedef long long ll;
using namespace std;
const ll MOD = 998244353;

ll modPow(ll b, ll e)
{
    if (e == 0) return 1;
    else if (e % 2 == 0) return modPow(b, e / 2) * modPow(b, e / 2) % MOD;
    else if (e % 2 == 1) return (modPow(b, e / 2) * modPow(b, e / 2) % MOD) * b % MOD;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, x;
    cin >> n >> x;
    if (n > x)
    {
        cout << modPow(x, n);
        return 0;
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(x + 1));
    for (int i = 1; i <= x; i++) dp[2][i] = i;
    for (int i = 3; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (dp[i - 1][j] == 0)
            {
                dp[i][j] = modPow(j, i);
            }
            else
            {
                dp[i][j] = dp[i - 1][j] * j % MOD;
            }
        }
    }




    return 0;
}