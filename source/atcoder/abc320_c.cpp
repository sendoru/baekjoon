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

    int m;
    cin >> m;
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    // O(M^3) 경우의 수 전부 체크?
    // 이게 제일 편하겠네
    // ㅅㅂ
    int ans = MOD9;
    for(int i = 0 ; i < m * 3; i++) {
        for(int j = i + 1; j < m * 3; j++) {
            for(int k = j + 1; k < m * 3; k++) {
                if (s1[i % m] == s2[j % m] && s2[j % m] == s3[k % m] ||
                    s1[i % m] == s2[k % m] && s2[k % m] == s3[j % m] ||
                    s1[j % m] == s2[i % m] && s2[i % m] == s3[k % m] ||
                    s1[j % m] == s2[k % m] && s2[k % m] == s3[i % m] ||
                    s1[k % m] == s2[i % m] && s2[i % m] == s3[j % m] ||
                    s1[k % m] == s2[j % m] && s2[j % m] == s3[i % m]) {
                    ans = min(ans, k);
                }
            }
        }
    }

    if (ans == MOD9) {
        cout << -1;
    }
    else {
        cout << ans;
    }

    return 0;
}