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

    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    int plain_clean = m, plain_worn = 0, logo_clean = 0, logo_worn = 0;
    int ans = 0;
    for(int i = 0 ; i < n; i++) {
        if (s[i] == '0') {
            plain_clean += plain_worn;
            plain_worn = 0;
            logo_clean += logo_worn;
            logo_worn = 0;
        }
        else if (s[i] == '1') {
            if (plain_clean != 0) {
                plain_clean--;
                plain_worn++;
            }
            else if (logo_clean != 0) {
                logo_clean--;
                logo_worn++;
            }
            else {
                ans++;
                logo_worn++;
            }
        }
        else {
            if (logo_clean != 0) {
                logo_clean--;
                logo_worn++;
            }
            else {
                ans++;
                logo_worn++;
            }
        }
    }

    cout << ans;

    return 0;
}