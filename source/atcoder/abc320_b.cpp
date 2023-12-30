#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MOD9 = 998244353;
const ll MOD1 = (ll)1e9 + 7;

bool checkpal(string& s, int l, int r) {
    for(int i = l, j = r; i <= r; i++, j--) {
        if (s[i] != s[j]) {
            return false;
        }
    }

    return true;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;
    int ans = 1;
    for(int i = 0; i < s.length(); i++) {
        for(int j = i + 1; j < s.length(); j++) {
            if (checkpal(s, i, j)) {
                ans = max(ans, j - i + 1);
            }
        }
    }

    cout << ans;
    return 0;
}