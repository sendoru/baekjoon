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
    vector<vector<int>> v(n, vector<int>(3));
    for(int i = 0 ; i < n; i++) {
        v[i][0] = i + 1;
        cin >> v[i][1] >> v[i][2];
    }

    sort(v.begin(), v.end(), [](vector<int>& a, vector<int>& b) -> bool {
        int asbt = a[2] * b[1], atbs = a[1] * b[2];
        if (asbt != atbs) return asbt > atbs;
        return a[0] < b[0];
    });

    for(auto& i : v) {
        cout << i[0] << ' ';
    }


    return 0;
}