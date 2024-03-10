#include <bits/stdc++.h>

#include "atcoder/all"

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MOD9 = 998244353;
const ll MOD1 = (ll)1e9 + 7;

// n자리 수에서 인접한 두 숫자가 같지 않은 수의 개수를 f(n)이라고 하면
// 맨 앞자리가 1인 거 f(n)/9개, 2인 거 f(n)/9개, ..., 9인 거 f(n)/9개
// 이걸로 n+1자리 수에서 인접한 두 숫자가 같지 않은 수의 개수를 구할 수 있음
// f(n+1) = 9 * f(n)

// f(1) = 9

ll func(ll n) {
    ll ret = 0;
    // ex: n = 8865라고 하면
    // 1자리, 2자리, 3자리에 대해서는 전부 구하면 되고
    // 4자라의 경우
    // 1000 ~ 7999, 8000 ~ 8799, 8800 ~ 8859, 8860 ~ 8865

    // 1000 ~ 7999의 경우에는, f(3) * 7
    // 8000 ~ 8799의 경우에는, f(2) * 8 <- 여긴 7이 아니라 8임
    // 8800 ~ 구간은 앞에 88때문에 그냥 끝

    if (n <= 9) {
        return n;
    }

    for (int p = 0; p <= 18; p++) {
        if (p + 1 < to_string(n).size()) {
            ret += powl(9, (p + 1));
        }
    }

    string s = to_string(n);
    reverse(s.begin(), s.end());
    for (int i = s.size() - 1; i >= 0; i--) {
        if (i + 2 <= s.size() - 1 && s[i + 1] == s[i + 2]) {
            break;
        }
        if (i == s.size() - 1) {
            ret += powl(9, i) * (s[i] - '0' - 1);
        } else if (i == 0 && s[i] < s[i + 1]) {
            ret += powl(9, i) * (s[i] - '0' + 1);
        } else if (i == 0) {
            ret += powl(9, i) * (s[i] - '0');
        } else if (s[i] > s[i + 1]) {
            ret += powl(9, i) * (s[i] - '0' - 1);
        } else {
            ret += powl(9, i) * (s[i] - '0');
        }
    }

    return ret;
}

// 여긴 O(nlogn) naive validation
ll func_naive(ll n) {
    ll ret = 0;
    for (ll i = 1; i <= n; i++) {
        string s = to_string(i);
        bool ok = true;
        for (int j = 0; j < s.size() - 1; j++) {
            if (s[j] == s[j + 1]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ret++;
        }
    }
    return ret;
}

void test(ll n) {
    for (ll i = 1; i <= n; i++) {
        if (func(i) != func_naive(i)) {
            cout << "i: " << i << ", func(i): " << func(i)
                 << ", func_naive(i): " << func_naive(i) << '\n';
        }
    }
}

int main() {
    test(903);
    int t;
    cin >> t;
    while (t--) {
        ll k;
        cin >> k;
        // find kth positive integer such that
        // leq k and no two adjacent characters are the same (in decimal
        // representation)

        // instead of finding it directly, we can find the number of positive
        // integers leq than arbitrary number n such that no two adjacent
        // characters are the same and use binary search

        // 1. find the number of positive integers leq than arbitrary number n
        // such that no two adjacent characters are the same

        // 2. use binary search to find the number of positive integers leq than
        // arbitrary number n such that no two adjacent characters are the same
        ll l = 1, r = 1e18;
        while (l < r) {
            ll m = (l + r) / 2;
            if (func(m) < k) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        cout << l << '\n';
    }
}