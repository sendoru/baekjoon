#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
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
        ll ans = 0, cur = 1;
        while (cur <= k && cur < n)
        {
            cur <<= 1;
            ans++;
        }
        n -= cur;
        if (n > 0)
        {
            ans += n / k;
            ans += (n % k) ? 1 : 0;
        }

        cout << ans << '\n';
    }

    return 0;
}