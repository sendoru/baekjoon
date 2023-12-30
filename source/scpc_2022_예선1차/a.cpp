#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> pv(n);
        vector<int> initP(n);
        for (int i = 0; i < n; i++)
        {
            cin >> pv[i].second;
            initP[i] = pv[i].second;
        }
        for (int i = 0; i < n; i++)
            cin >> pv[i].first;
        sort(pv.begin(), pv.end());
        ll ans = 0;
        for (int i = 0; i < n; i++)
            ans += abs(pv[i].second - initP[i]);

        cout << "Case #" << t << '\n';
        cout << ans << '\n';
    }
    
    return 0;
}