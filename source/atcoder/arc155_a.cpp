//
// Created by sendo on 2023-01-29.
//
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

    int t;
    cin >> t;
    while(t--) {
        ll n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        if (k == n) {
            cout << "Yes\n";
            continue;
        }

        else if (k < n) {
            bool ans = true;
            // (1) s의 맨 뒤쪽 n - k 길이의 부분문자열이 팰린드롬인지 확인
            for(ll i = k, j = n - 1; i < n; i++, j--) {
                if (s[i] != s[j]) {
                    ans = false;
                    break;
                }
            }

            // (2) 이때 s'는 하나로 결정됨
            string sp;
            for(ll i = k - 1; i >= 0; i--) {
                sp.push_back(s[i]);
            }

            // (3) s의 맨 앞쪽 n - k
            for(ll i = 0, j = n - 1 - k; i < n - k; i++, j--) {
                if (s[i] != s[j]) {
                    ans = false;
                    break;
                }
            }

            string sp2;
            for(ll i = n - 1; i >= n - k; i--) {
                sp2.push_back(s[i]);
            }

            if (sp != sp2) {
                ans = false;
            }

            cout << (ans ? "Yes" : "No") << '\n';
        }

        else {
            if (n == 1) {
                cout << "Yes\n";
                continue;
            }

            bool ans = true, flag = false;
            if ((n + k) % 2ll == 1ll) {
                flag = true;
            }

            ll max_p = gcd(n, n + k);
            if (((n + k) / max_p) % 2ll == 1ll) {
                if (max_p % 2ll == 1ll) {
                    // 이때는 2p길이 구간이 아니라 p길이 구간이 팰린드롬인지 확인해야 됨
                    flag = true;
                }
                else {
                    max_p /= 2;
                }
            }


            for(ll i = 0; i < n / max_p - 1; i++) {
                for(ll j = 0; j < 2 * max_p; j++) {
                    if (s[i * max_p + j] != s[(i + 2) * max_p - 1 - j]) {
                        // cout << s[i * max_p + j]  << ' ' <<  s[(i + 2) * max_p - j] << endl;
                        ans = false;
                        break;
                    }
                }
                if (!ans) break;
            }

            if (flag) {
                for(ll i = 0; i < n / max_p; i++) {
                    for(ll j = 0; j < max_p; j++) {
                        if (s[i * max_p + j] != s[(i + 1) * max_p - 1 - j]) {
                            // cout << s[i * max_p + j]  << ' ' <<  s[(i + 2) * max_p - j] << endl;
                            ans = false;
                            break;
                        }
                    }
                    if (!ans) break;
                }
            }

            cout << (ans ? "Yes" : "No") << '\n';
        }
    }

    return 0;
}