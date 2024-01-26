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

    int m = 0;
    while ((1) << m < n) {
        m++;
    }

    cout << m << '\n';
    cout.flush();

    for(int i = 0; i < m; i++) {
        vector<int> out;
        for(int j = 0; j < n; j++) {
            if (j & (1 << i)) {
                out.push_back(j + 1);
            }
        }

        cout << out.size() << ' ';
        for(auto i : out) {
            cout << i << ' ';
        }

        cout << '\n';
        cout.flush();
    }
    
    string s;
    cin >> s;

    int ans = 0;
    for(int i = 0; i < s.length(); i++) {
        ans += (int)(s[i] == '1') << i;
    }

    cout << ans + 1;
    cout.flush();

    return 0;
}