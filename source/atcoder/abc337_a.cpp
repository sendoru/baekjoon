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
    int x = 0, y = 0;
    for(int i = 0; i < n; i++) {
        int xi, yi;
        cin >> xi >> yi;
        x += xi;
        y += yi;
    }

    if (x > y) {
        cout << "Takahashi";
    }
    else if (x == y) {
        cout << "Draw";
    }
    else {
        cout << "Aoki";
    }
    

    return 0;
}