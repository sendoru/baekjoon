#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
typedef long long ll;
typedef long double ld;
using namespace std;
constexpr ld DELTA = 1e-5;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    vector<pair<pair<ld, ld>, ll>> dots(n * 2);
    for (int i = 0; i < n; i++)
    {
        ld x, y;
        cin >> x >> y;
        pair<ld, ld> d0 = { x - 1 + DELTA, y }, d1 = { x, y - 1 + DELTA};
        dots[2 * i].first = d0; dots[2 * i].second = 1;
        dots[2 * i + 1].first = d1; dots[2 * i + 1].second = -1;
    }

    sort(dots.begin(), dots.end(), [](pair<pair<ld, ld>, ll> a, pair<pair<ld, ld>, ll> b)
        {
            pair<ld, ld> da = a.first, db = b.first;
            if (da.second * db.first != da.first * db.second)
                return da.second * db.first > da.first * db.second;
            return a.second < b.second;
        });
    ll ans = 0;
    ll cur = 0;
    for (int i = 0; i < dots.size(); i++)
    {
        if (cur == 0 && dots[i].second == 1) ans++;
        if (dots[i].second == 1) cur = 1;
        else if (dots[i].second == -1) cur = max(0ll, cur - 1);
    }

    cout << ans;

    return 0;
}