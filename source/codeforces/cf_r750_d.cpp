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
        vector<pair<ll, ll>> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i].first;
            a[i].second = i;
        }
        sort(a.begin(), a.end(), [](pair<int, int> aa, pair<int, int> bb) -> bool
            {
                return abs(aa.first) > abs(bb.first);
            });
        vector<ll> pfSum(n);
        ll curSum = 0;
        vector<pair<ll, ll>> b(n);
        for (int i = 0; i < n - 1; i++)
        {
            b[i].second = a[i].second;
            if (abs(curSum + a[i].first) < abs(curSum - a[i].first))
            {
                b[i].first = a[n - 1].first;
                curSum += a[i].first;
            }
            else
            {
                b[i].first = -a[n - 1].first;
                curSum -= a[i].first;
            }
        }
        if (curSum == 0)
        {
            b[n - 2].first *= -1;
            curSum += b[n - 2].first * 2;
        }

        b[n - 1].first = -curSum;
        b[n - 1].second = a[n - 1].second;

        sort(b.begin(), b.end(), [](pair<ll, ll> aa, pair<ll, ll> bb) -> bool
            {
                return aa.second < bb.second;
            });

        for (int i = 0; i < n; i++)
        {
            cout << b[i].first << ' ';
        }
        cout << '\n';
    }

    return 0;
}