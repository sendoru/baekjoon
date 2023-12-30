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

    int n, m;
    cin >> n >> m;
    // 데이터가 있다 -> 구현 난이도 0
    // 에디토리얼이 있다 -> 구현 난이도 floor(p/2), 아이디어 난이도 ceil(d/2)

    vector<pii> infos(n);
    for(auto& elem : infos) {
        int d, p, t, e;
        cin >> d >> p >> t >> e;
        if (t) p = 0;
        if (e) {
            p /= 2;
            d = (d + 1) / 2;
        }

        elem = {d, p};
    }
    int hd, hp;
    cin >> hd >> hp;

    // 내가 풀 수 있는 것 중 D가 최소인 것부터 풀기
    // P 기준으로 정렬하고 D 기준 min heap으로 스위핑?

    sort(infos.begin(), infos.end());
    auto iter = infos.begin();
    ll ans = 0, cur = 0;
    priority_queue<int, vector<int>, greater<>> pq;
    while(cur < m) {
        while (iter != infos.end() && (*iter).first <= hd) {
            pq.push((*iter).second);
            iter++;
        }
        if (pq.empty())
            break;
        ans += max(0, pq.top() - hp);
        pq.pop();
        cur++;
        hd++;
        hp++;
    }

    if (cur < m)
        cout << -1;
    else
        cout << ans;

    return 0;
}