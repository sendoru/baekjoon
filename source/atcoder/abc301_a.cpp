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

    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char, int> m;
    for(int i = 0; i < s.length(); i++) {
        m[s[i]]++;
        if (m[s[i]] >= (s.length() + 1) / 2) {
            cout << s[i];
            break;
        }
    }
    return 0;
}