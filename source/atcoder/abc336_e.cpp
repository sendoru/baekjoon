#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MOD9 = 998244353;
const ll MOD1 = (ll)1e9 + 7;

ll get_digit_sum(ll n) {
    ll ret = 0;
    while (n != 0) {
        ret += n % 10;
        n /= 10;
    }
    return ret;
}

ll solve_naive(ll n) {
    ll ans = 0;
    for(ll i = 1; i <= n; i++) {
        ll digit_sum = get_digit_sum(i);
        if (i % digit_sum == 0) {
            ans++;
        }
    }

    return ans;
}

vector<ll> get_digits(ll n) {
    vector<ll> ret;
    while(n != 0) {
        ret.push_back(n % 10);
        n /= 10;
    }
    return ret;
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n;
    cin >> n;

    auto n_digit = get_digits(n);
    reverse(n_digit.begin(), n_digit.end());

    ll ans = 0;
    for (int s = 1; s <= 9 * 14; s++) {
        vector dp(n_digit.size() + 1, vector(s + 1, vector(s, vector<ll>(2, 0ll))));
        dp[0][0][0][1] = 1;
        for(int d = 0; d < n_digit.size(); d++) {
            for(int i = 0; i <= s; i++) {
                for(int j = 0; j < s; j++) {
                    for(int f = 0; f < 2; f++) {
                        for(int t = 0; t <= 9; t++) {
                            if (i + t > s) continue;
                            if (f && n_digit[d] < t ) continue;
                            // [하나][둘][셋][넷]: 결정된 자릿수 갯수, 결정된 자릿수까지의 digit sum, 나머지, tight인가 뭔가하는거
                            dp[d + 1][i + t][(10 * j + t) % s][f && n_digit[d] == t] += dp[d][i][j][f];
                        }
                    }
                }
            }
        }
        ans += dp[n_digit.size()][s][0][0] + dp[n_digit.size()][s][0][1];
    }

    cout << ans;

    return 0;
}