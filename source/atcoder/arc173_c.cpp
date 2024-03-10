#include <bits/stdc++.h>

#include "atcoder/all"

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MOD9 = 998244353;
const ll MOD1 = (ll)1e9 + 7;

int main()
{
    int n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }

    // for each i,
    // find the minimum length of the subarray that contains p[i] and p[i] is
    // not the median of the subarray and it's length is odd

    // sweep with length 3 window
    vector<int> ans(n, MOD1);
    for (int i = 0; i < n - 2; i++) {
        vector<int> v = {p[i], p[i + 1], p[i + 2]};
        sort(v.begin(), v.end());
        if (v[1] != p[i]) {
            ans[i] = 3;
        }
        if (v[1] != p[i + 1]) {
            ans[i + 1] = 3;
        }
        if (v[1] != p[i + 2]) {
            ans[i + 2] = 3;
        }
    }

    // sweep with length 5 window
    for (int i = 0; i < n - 4; i++) {
        vector<int> v = {p[i], p[i + 1], p[i + 2], p[i + 3], p[i + 4]};
        sort(v.begin(), v.end());
        if (v[2] != p[i + 1]) {
            ans[i + 1] = 5;
        }
        if (v[2] != p[i + 2]) {
            ans[i + 2] = 5;
        }
        if (v[2] != p[i + 3]) {
            ans[i + 3] = 5;
        }
        if (v[2] != p[i + 4]) {
            ans[i + 4] = 5;
        }
    }
}