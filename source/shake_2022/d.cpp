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

    ll n;
    cin >> n;
    vector<ll> a(n);
    for(auto& i : a)
        cin >> i;

    ll k;
    cin >> k;
    if (n == 1) {
        cout << k;
        return 0;
    }

    ll maxInv = 0;
    for(int i = 1 ; i < n; i++) {
        if (a[i] < a[i - 1]) {
            maxInv = max(maxInv, a[i - 1]);
        }
    }

    ll initK = 0;
    for (int i = 0; i < n; i++) {
        initK += max(0ll, maxInv - a[i]);
        a[i] = max(a[i], maxInv);
    }

    if (initK > k) {
        cout << 0;
        return 0;
    }

    ll ans = (initK == 0 ? 0 : 1);
    k -= initK;

    vector<ll> seg = {1};
    for(int i = 1; i < a.size(); i++) {
        if (a[i] == a[i - 1]) {
            seg.back()++;
        }
        else {
            seg.push_back(1);
        }
    }

    a.push_back(2e18);
    ll curSeg = 0;
    for(ll s : seg) {
        curSeg += s;
        ll diff = a[curSeg] - a[curSeg - 1];
        if (a[curSeg] <= (ll)1e18 && diff * curSeg <= k) {
            k -= diff * curSeg;
            ans += diff;
        }
        else {
            ans += k / curSeg;
            break;
        }
    }

    cout << ans;




    return 0;
}