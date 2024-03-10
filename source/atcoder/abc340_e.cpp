#include <bits/stdc++.h>
#include "atcoder/all"
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MOD9 = 998244353;
const ll MOD1 = (ll)1e9 + 7;

ll solve(ll n) {
    if (n < 2) return 0;
    if (n % 2 == 0) {
        ll half = solve(n / 2);
        return 2 * half + n;
    }
    return solve(n / 2) + solve(n / 2 + 1) + n;
}

struct S {
    ll a, size;
};

S sum(S a, S b) {
    return S{a.a + b.a, a.size + b.size};
}

S e() {
    return S{0, 0};
}

S mapping(ll a, S b) {
    return S{b.a + a * b.size, b.size};
}

ll comp(ll a, ll b) {return a + b;}

ll id() {return 0;}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n, m;
    cin >> n >> m;
    vector<S> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].a;
        a[i].size = 1;
    }

    atcoder::lazy_segtree<S, sum, e, ll, mapping, comp, id> seg(a);

    for(int i = 0; i < m; i++) {
        ll bi;
        cin >> bi;
        ll cnt = seg.get(bi).a;
        seg.set(bi, {0, 1});

        // cnt % n개 상자에는 floor(cnt / n) + 1개가 들어가고 나머지에는 floor(cnt / n)개가 들어감

        seg.apply(0, n, cnt / n);
        if (cnt % n != 0) {
            seg.apply(bi + 1, min(bi + 1 + cnt % n, n), 1);
        }
        if (bi + 1 + cnt % n > n) {
            seg.apply(0, (bi + 1 + cnt % n) % n, 1);
        }
    }

    for(int i = 0; i < n; i++) {
        cout << seg.get(i).a << ' ';
    }

    return 0;
}