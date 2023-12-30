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

    ll n, s;
    cin >> n >> s;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> break_point;
    ll cur_sum = 0;
    for(int i = 0; i < n; i++) {
        if (cur_sum + a[i] <= s) {
            cur_sum += a[i];
        }
        else {
            break_point.push_back(i);
            cur_sum = a[i];
        }
    }




    return 0;
}