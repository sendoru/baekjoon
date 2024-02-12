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
    vector<int> a(n);
    for(int& i : a) {
        cin >> i;
    }

    vector<ll> cnts = {1};
    ll ans = 0;

    for(int i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) {
            cnts.back()++;
        }
        else {
            cnts.push_back(1);
        }
    }

    for(ll i : cnts) {
        ans += i * (i + 1) / 2;
    }

    cout << ans;

    return 0;
}