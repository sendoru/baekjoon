#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <queue>
#include <map>
#include <set>
using namespace std;
typedef long long ll;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, a, b;
    cin >> n >> a >> b;

    // vs2022 병신새끼
    vector<ll> aa(n);
    ll lo = *min_element(aa.begin(), aa.end()), hi = *max_element(aa.begin(), aa.end()), ans = lo, mid = (lo + hi) / 2;
    while (lo <= hi)
    {
        mid = (lo + hi) / 2;
        ll addCnt = 0, subCnt = 0;
        for (auto& elem : aa)
        {
            if (elem < mid)
            {
                addCnt += (mid - elem) / a + ((elem - mid) % a != 0);
            }
            else if (elem > mid)
            {
                subCnt += (elem - mid) / b;
            }
        }

        if (addCnt <= subCnt)
        {
            ans = max(ans, mid);
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }

    cout << ans;
    return 0;
}