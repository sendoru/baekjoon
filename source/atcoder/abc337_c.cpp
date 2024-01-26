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
    for(auto& i : a) {
        cin >> i;
        i--;
    }

    vector<int> nxt(n, -2);
    for(int i = 0; i< n; i++) {
        if (a[i] >= 0) {
            nxt[a[i]] = i;
        }
    }


    int cur = find(a.begin(), a.end(), -2) - a.begin();
    while(cur >= 0) {
        cout << cur + 1 << ' ';
        cur = nxt[cur];
    }

    return 0;
}

// 10 17 12 6 4 21 11 24 26 7 30 16 25 2 28 27 20 3 1 8 15 18 5 23 13 22 19 29 9 14
// 10 17 12 6 4 21 11 24 26 7 30 16 25 2 28 27 20 3 1 8 15 18 5 23 13 22 19 29 9 14
