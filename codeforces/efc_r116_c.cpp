#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
typedef long long ll;
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<bool> flags(20);
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            flags[temp] = true;
        }
        ll ans = 0, used = 0;
        int highest = 0;
        bool solved = false;
        // 9¿ø, 99¿ø, 999¿ø, ......
        for (int i = 0; i < 20; i++)
        {
            if (flags[i]) highest = i;
            ll cur = (ll)powl(10, i + 1) - 1;
            used += (ll)powl(10, i - highest) * 9;
            if (k < used)
            {
                solved = true;
                for (int j = i; j >= 0; j--)
                {
                    if (flags[j])
                    {
                        if (k < used - cur / (ll)powl(10, j))
                        {
                            cur -= (cur / (ll)powl(10, j)) * (ll)powl(10, j);
                            used -= (cur / (ll)powl(10, j));
                        }
                        else
                        {
                            ll target = used - k - 1;
                            cur -= (ll)powl(10, j) * target;
                            break;
                        }
                    }
                }
                ans = cur;
                break;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}