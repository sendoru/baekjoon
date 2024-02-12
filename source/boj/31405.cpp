#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MOD9 = 998244353;
const ll MOD1 = (ll)1e9 + 7;

vector<int> dr = {-1, 0, 1, 0}, dc = {0, 1, 0, -1};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(12);

    int n;
    cin >> n;
    
    vector<pll> dots(n);
    for(auto& i : dots) {
        cin >> i.first >> i.second;
    }

    // 신발끈 on
    ll total_area = 0;
    for(int i = 0; i < n; i++) {
        total_area += dots[i].first * dots[(i + 1) % n].second;
        total_area -= dots[(i + 1) % n].first * dots[i].second;
    }
    total_area = abs(total_area);

    ll cul_area = 0;
    for(int i = 2; i < n; i++) {
        ll cur_area = abs(
            dots[0].first * dots[(i - 1) % n].second - dots[(i - 1) % n].first * dots[0].second
            + dots[i - 1].first * dots[i].second - dots[i].first * dots[i - 1].second
            + dots[i].first * dots[0].second - dots[0].first * dots[i].second
        );
        

        if (cul_area * 2 < total_area && (cul_area + cur_area) * 2 >= total_area) {
            long double beta = (ld(total_area) / 2 - cul_area) / cur_area;
            cout << "YES\n";
            cout << "1 0\n";
            cout << i << ' ' << max(beta, 0.l);
            return 0;
        }
        cul_area += cur_area;
    }

    cout << "NO";
    return 0;
}