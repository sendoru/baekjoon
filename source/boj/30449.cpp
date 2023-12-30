#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MOD9 = 998244353;
const ll MOD1 = (ll)1e9 + 7;

struct pii {
    int first, second;
    bool operator< (const pii& other) const {
        return first * other.second < second * other.first;
    }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    array<pii, 4'000'000> v;
    v[0] = {0, 1};
    int v_len = 1;

    for(int i = 1; i <= n; i += 2) {
        for(int j = 1; j <= i / 2; j++) {
            if (gcd(i, j) == 1) {
                v[v_len] = {j, i};
                v_len++;
            }
        }
    }

    for(int i = 2; i <= n; i += 2) {
        for(int j = 1; j <= i / 2; j += 2) {
            if (gcd(i, j) == 1) {
                v[v_len] = {j, i};
                v_len++;
            }
        }
    }

    sort(v.begin(), v.begin() + v_len);

    k--;
    if (k < v_len) {
        cout << v[k].first << ' ' << v[k].second;
    }

    else {
        int idx = 2 * (v_len - 1) - k;
        cout << v[idx].second - v[idx].first << ' ' << v[idx].second;
    }


    return 0;
}