#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

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
        vector<int> a(n + 1), pfSum(n + 1);
        ll zeroCnt = 0, oneCnt = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (a[i] == 0) zeroCnt++;
            else if (a[i] == 1) oneCnt++;
        }
        ll ans = (1ll << zeroCnt) * oneCnt;
        cout << ans << '\n';
    }
    return 0;
}