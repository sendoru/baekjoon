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

    int n, d;
    cin >> n >> d;
    if (d > (n - 1) / 2) {
        cout << "No";
        return 0;
    }

    vector<pii> ans;
    for(int i = 0; i < d; i++) {
        for(int j = 0; j < n; j++) {
            ans.emplace_back(j, (j + i + 1) % n);
        }
    }

    cout << "Yes\n";

    for(auto elem : ans) {
        cout << elem.first + 1 << ' ' << elem.second + 1 << '\n';
    }

    return 0;
}