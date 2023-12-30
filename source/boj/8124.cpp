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
    vector<vector<ll>> v(n, vector<ll>(3));
    for(int i = 0; i < n; i++) {
        double a, b;
        cin >> a >> b;
        v[i][0] = (ll)round(a * 1e6);
        v[i][1] = (ll)round(b * 1e6);
        v[i][2] = i + 1;
    }

    sort(v.begin(), v.end(), [] (vector<ll>& a, vector<ll>& b) -> bool {
        ll a_then_b = a[1] + b[0] * a[1] + b[1];
        ll b_then_a = b[1] + a[0] * b[1] + a[1];
        return a_then_b < b_then_a;
    });

    for (auto& elem: v) {
        cout << elem[2] << '\n';
    }


    return 0;
}