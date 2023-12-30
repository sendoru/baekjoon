#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
typedef long long ll;
using namespace std;

ll getGCD(ll a, ll b)
{
    if (b == 0) return a;
    return getGCD(b, a % b);
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<ll> occ(31);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 31; j++)
            {
                if (a[i] & (1ll << j))
                {
                    occ[j]++;
                }
            }
        }

        ll gcd = 0;
        for (int i = 0; i < 31; i++)
        {
            if (occ[i] != 0)
            {
                gcd = getGCD(gcd, occ[i]);
            }
        }

        for (int i = 1; i <= n; i++)
        {
            if (gcd % i == 0)
            {
                cout << i << ' ';
            }
        }

        cout << '\n';
    }
    return 0;
}