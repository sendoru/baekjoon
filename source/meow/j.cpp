#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MOD9 = 998244353;
const ll MOD1 = (ll)1e9 + 7;

auto ccw = [] (const pll &a, const pll &b, const pll &c) {
    pll x = { b.first - a.first, b.second - a.second };
    pll y = { c.first - b.first, c.second - b.second };
    ll ret = 1LL * x.first * y.second - 1LL * x.second * y.first;
    return ret == 0 ? 0 : (ret > 0 ? 1 : -1);
};

int main(void) {
    int n;
    cin >> n;
    vector<pll> dots(n);
    for(int i = 0; i < n; i++) {
        cin >> dots[i].first >> dots[i].second;
    }

    if (n & 1) {
        cout << 0;
        return 0;
    }
    // 정답이 1이라면 주어진 다각형에서 오목꼭짓점은 유일
    // 이 점이 i번쨰 점이라면, 대칭축은 i번째 점과 (i + n/2) mod n번째 점

    vector<int> convex(n);
    for(int i = 0; i < n; i++) {
        convex[i] = ccw(dots[(i + n - 1) % n], dots[i], dots[(i + 1) % n]);
    }

    int cnt = 0, p1_idx = -1, p2_idx = -1;
    for(int i = 0; i < n; i++) {
        if (convex[i] == 1) {
            cnt++;
            p1_idx = i;
            p2_idx = (i + n/2) % n;
        }
    }

    if (cnt != 1) {
        cout << 0;
        return 0;
    }

    bool ans = true;
    // 볼록성 판정.. 은 안해도 되나ㅣ

    ll a = (dots[p2_idx].second - dots[p1_idx].second),
        b = -(dots[p2_idx].first - dots[p1_idx].first),
        c = dots[p1_idx].first * a + dots[p1_idx].second * b;

    // 대칭성 판정
    for(int i = 0; i <= n/2; i++) {
        auto d1 = dots[(p2_idx + i) % n], d2 = dots[(p2_idx - i + n) % n];
        if (abs(a * d1.first + b * d1.second + c)
        != abs(a * d2.first + b * d2.second + c)
        || a * (d2.second - d1.second) - b * (d2.first - d1.first) != 0) {
            ans = false;
            break;
        }
    }

    cout << (ans ? 1 : 0);

    return 0;
}