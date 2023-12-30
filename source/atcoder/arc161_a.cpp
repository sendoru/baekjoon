#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MOD9 = 998244353;
const ll MOD1 = (ll)1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& elem : a)
        cin >> elem;

    sort(a.begin(), a.end());
    // 0 ~ (n + 1) / 2 - 1 의 (n + 1) / 2개
    // (n + 1) / 2 ~ (n - 1)의 (n - 1) / 2개

    vector<int> aa(n);
    for(int i = (n + 1) / 2, j = 1; i < n; i++, j += 2) {
        aa[j] = a[i];
    }

    for(int i = 0, j = 0; i < (n + 1) / 2; i++, j += 2) {
        aa[j] = a[i];
    }

    bool ans = true;
    for(int i = 1; i < n; i += 2) {
        if (aa[i] <= aa[i - 1] || aa[i] <= aa[i + 1]) {
            ans = false;
            break;
        }
    }

    cout << (ans ? "Yes" : "No");

    return 0;
}