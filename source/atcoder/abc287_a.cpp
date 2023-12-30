//
// Created by sendo on 2023-01-28.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> s(2);
    for(int i = 0; i < n; i++)
    {
        string si;
        cin >> si;
        if (si[0] == 'F')
            s[1]++;
        else
            s[0]++;
    }

    cout << (s[1] > s[0] ? "Yes" : "No");
    return 0;
}