#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

int solve(vector<pair<int, int>> a)
{
    int n = a.size();
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += abs(a[i].second - i);
    }

    return ans;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }

    cout << solve(a) << '\n';
    
    return 0;
}