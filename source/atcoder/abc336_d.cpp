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
    for (auto& elem : a) {
        cin >> elem;
    }

    vector<int> dec = a, inc = a;
    for(int i = 0, delta = n; i < n; i++, delta--) {
        dec[i] -= delta;
    }
        
    for(int i = 0, delta = 1; i < n; i++, delta++) {
        inc[i] -= delta;
    }

    vector<int> inc_min_from_left = inc;
    for(int i = 1; i < n; i++) {
        inc_min_from_left[i] = min(inc_min_from_left[i - 1], inc_min_from_left[i]);
    }

    vector<int> dec_min_from_right = dec;
    for(int i = n - 2; i >= 0; i--) {
        dec_min_from_right[i] = min(dec_min_from_right[i + 1], dec_min_from_right[i]);
    }


    int ans = 1;
    for(int i = 0; i < n; i++) {
        int peak_val = min(i + 1, n - i);
        
        // inc는 i만큼 올리고
        // dec는 n - i - 1만큼 올리고

        int left_lack = min(0, inc_min_from_left[i] + max(0, i + 1 - peak_val));
        int right_lack = min(0, dec_min_from_right[i] + max(0, n - i - peak_val));


        ans = max(ans, min(peak_val, min(peak_val + left_lack, peak_val + right_lack)));

    }

    cout << ans;

    return 0;
}