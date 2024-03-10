#include <bits/stdc++.h>

#include "atcoder/all"

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MOD9 = 998244353;
const ll MOD1 = (ll)1e9 + 7;

bool is_palindrome(ll n)
{
    string s = to_string(n);
    string rev = s;
    reverse(rev.begin(), rev.end());
    return s == rev;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n;
    cin >> n;

    ll ans = 0;
    for (ll i = 1; i * i * i <= n; i++) {
        if (is_palindrome(i * i * i)) {
            ans = i * i * i;
        }
    }

    cout << ans;
    return 0;
}