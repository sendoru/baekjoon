#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MOD9 = 998244353;
const ll MOD1 = (ll)1e9 + 7;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;
    ll ans = s.length();
    for (char i : s) {
        if (i == ':')
            ans += 1;
        else if (i == '_')
            ans += 5;
    }


    cout << ans ;

    return 0;
}