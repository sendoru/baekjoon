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
    for(int i = 0; i <= n; i++) {
        bool printed = false;
        for(int j = 1; j < 10; j++) {
            if (n % j == 0 && i % (n / j) == 0) {
                cout << j;
                printed = true;
                break;
            }
        }
        if (!printed) {
            cout << '-';
        }
    }

    return 0;
}