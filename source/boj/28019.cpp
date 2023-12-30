#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MOD9 = 998244353;
const ll MOD1 = (ll)1e9 + 7;

template <typename T, typename op, T e>
class SegTree {
    vector<T> data;
    ll n;
public:
    SegTree(ll _n) {
        ll h = 0;
        while ((1 << h) < 2 * _n)
            h++;

        data = vector<T>(1 << h, e);
        n = 1 << (h - 1);
    }

    SegTree(vector<T>& v) {
        ll _n = v.size();
        ll h = 0;
        while ((1 << h) < 2 * _n)
            h++;

        data = vector<T>(1 << h, e);
        n = 1 << (h - 1);

        for(int i = 0; i < v.size(); i++)
            data[i + n] = v[i];
        for(int i = n - 1; i >= 1; i--)
            data[i] = op()(data[2 * i], data[2 * i + 1]);
    }

    void set(ll idx, T val) {
        idx += n;
        data[idx] = val;
        while (idx != 1) {
            idx >>= 1;
            data[idx] = op()(data[2 * idx], data[2 * idx + 1]);
        }
    }

    T get(ll idx) {
        return data[idx + n];
    }

    T get(ll l, ll r) {
        l += n;
        r += n + 1;
        ll ret = e;
        while (l < r) {
            if (l & 1) {
                ret = op()(ret, data[l]);
                l++;
            }
            if (r & 1) {
                r--;
                ret = op()(data[r], ret);
            }
            l >>= 1;
            r >>= 1;
        }
        return ret;
    }
};

struct op {
    ll operator() (ll a, ll b) {
       return a + b;
    }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n), b(n), a_inv(n), b_recon(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a_inv[a[i]] = i;
    }

    for(int i = 0; i < n; i++) {
        cin >> b[i];
        b_recon[i] = a_inv[b[i]];
    };

    // b_recon[i] : b[i]가 a에서 몇 번째로 나타나냐?
    // a = 1 2 3 0 4
    // b = 1 2 3 4 0
    // b_recon = 0 1 2 4 3


    // seg1[i]: 수 i를 체크했으면 1, 아니면 0
    // seg2[i]: 두 번 째 수가 i인 증가하는 쌍의 갯수
    SegTree<ll, op, 0ll> seg1(111'111), seg2(111'111);
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ans += seg2.get(0, b_recon[i] - 1);
        seg1.set(b_recon[i], 1);
        seg2.set(b_recon[i], seg1.get(0, b_recon[i] - 1));
    }

    if (ans == 0) {
        cout << "Attention is what I want";
    }
    else {
        cout << "My heart has gone to paradise\n";
        cout << ans;
    }


    return 0;
}