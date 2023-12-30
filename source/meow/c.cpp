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

    int m, n, q;
    cin >> m >> n >> q;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<int> ans(n + 1, 1);
    for(int i = 1; i <= m; i++) {
        cout << "? " << i << ' '<< i << endl;
        int cur;
        cin >> cur;
        if (cur == 1)
            ans[i] = 2;
    }

    cout << "! ";
    for(int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
    cout << endl;

    return 0;
}