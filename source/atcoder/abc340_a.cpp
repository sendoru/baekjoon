#include <bits/stdc++.h>
// #include "atcoder/all"
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
    int a, b, d;
    cin >> a >> b >> d;
    for(int i = a; i <= b; i += d) {
        cout << i << ' ';
    }

    return 0;
}