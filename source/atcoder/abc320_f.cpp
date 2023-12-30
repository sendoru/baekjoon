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

    int n, h;
    cin >> n >> h;
    vector<vector<ll>> xpf(n, vector<ll>(3));
    for(int i = 0; i < n; i++) {
        cin >> xpf[i][0];
    }
    for(int i = 0; i < n; i++) {
        cin >> xpf[i][1] >> xpf[i][2];
    }



    return 0;
}