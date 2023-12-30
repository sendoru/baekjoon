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
    for(auto& i : a)  {
        cin >> i;
    }

    int cur = a[0];
    cout << cur << ' ';
    for(int i = 1; i < a.size(); i++) {
        if (a[i] > cur) {
            for(int j = cur + 1; j < a[i]; j++) {
                cout << j << ' ';
            }
        }
        else if (a[i] < cur) {
            for(int j = cur - 1; j > a[i]; j--) {
                cout << j << ' ';
            }
        }
        cur = a[i];
        cout << cur << ' ';
    }

    return 0;
}
//2 3 4 5 4 3 2 1 2
//2 3 4 5 4 3 2 1 2