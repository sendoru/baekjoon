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

    ll n, m;
    cin >> n >> m;
    vector<ll> v(n);
    ll left = 1, right = 2 * n + 100;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        left = max(left, v[i] + 1);
        right += v[i];
    }

    // 매개변수탐색
    // 매개변수: 창의 폭

    ll ans = right;

    while(left <= right) {
        ll mid = (left + right) / 2;
        ll line = 1, cursor_pos = 0;
        for(auto elem : v) {
            // 그냥 모든 글자 "앞에" 띄어쓰기가 있다고 가정하고
            // 최종 정답에서 -1을 해주자

            if (cursor_pos + elem + 1 > mid) {
                line++;
                cursor_pos = elem + 1;
            }
            else {
                cursor_pos += elem + 1;
            }
        }

        if (line <= m) {
            ans = min(ans, mid);
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    cout << ans - 1;



    return 0;
}