#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <algorithm>
using namespace std;
typedef long long ll;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int, int>> dots(n);
    for (int i = 0; i < n; i++)
    {
        cin >> dots[i].first >> dots[i].second;
    }

    set<pair<int, int>> spells;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j) continue;
            pair<int, int> dist = { dots[j].first - dots[i].first, dots[j].second - dots[i].second };
            int distGCD = gcd(abs(dist.first), abs(dist.second));
            dist.first /= distGCD;
            dist.second /= distGCD;
            spells.insert(dist);
        }
    }

    cout << spells.size();

    return 0;
}