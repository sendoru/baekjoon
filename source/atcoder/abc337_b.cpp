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
    char cur = 'A';
    string ans = "Yes";
    for(int i = 0; i < s.length(); i++) {
        if (s[i] == cur) {
            continue;
        }
        else if (s[i] > cur && s[i] <= 'C') {
            cur = s[i];
        }
        else {
            ans = "No";
            break;
        }
    }
    
    cout << ans;
    
    return 0;
}