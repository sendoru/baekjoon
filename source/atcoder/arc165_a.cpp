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

    // 합이 n, 최소공배수가 n인 길이 2 이상의 수열의 존재성
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        // n이 소인수가 하나밖에 없는 수면 불가
        // 아니면 무조건 가능
        set<int> s;
        int p = 2, cur_n = n;
        while(p * p <= cur_n) {
            if (cur_n % p == 0) {
                s.insert(p);
                cur_n /= p;
            }
            else {
                p++;
            }
        }

        if (cur_n != 1) {
            s.insert(cur_n);
        }

        cout << (s.size() == 1 ? "No" : "Yes") << '\n';
    }

    return 0;
}