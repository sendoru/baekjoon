// 참고 코드 : https://www.acmicpc.net/source/share/6713b14759e34073a63c87aad115e379

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MOD9 = 998244353;
const ll MOD1 = (ll)1e9 + 7;

struct disjoint {
    vector<ll> parents;
    disjoint(ll n) {
        parents.resize(n);
        for(ll i = 0; i < n; i++) {
            parents[i] = i;
        }
    }

    ll findParent(ll v) {
        if (parents[v] == v)
            return v;
        return parents[v] = findParent(parents[v]);
    }

    bool hasSameParents(ll a, ll b) {
        ll aPar = findParent(a), bPar = findParent(b);
        return aPar == bPar;
    }

    void unite(ll a, ll b) {
        ll aPar = findParent(a), bPar = findParent(b);
        if (aPar != bPar) {
            parents[bPar] = aPar;
        }
    }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n, m1, m2, m3;
    cin >> n >> m1 >> m2 >> m3;
    vector<pll> m11(m1), m22(m2), m33(m3);

    for(auto& [i, j] : m11)
        cin >> i >> j;
    for(auto& [i, j] : m22)
        cin >> i >> j;
    for(auto& [i, j] : m33)
        cin >> i >> j;

    disjoint d1(n + 1), d2(n + 1), d3(n + 1);

    for (auto & [i, j] : m11) {
        d1.unite(i, j);
    }

    for (auto & [i, j] : m22) {
        d2.unite(i, j);
    }

    for (auto & [i, j] : m33) {
        d3.unite(i, j);
    }

    vector<vector<ll>> group(n + 1);
    map<vector<ll>, vector<ll>> byGroup;
    for(int i = 1; i <= n; i++) {
        group[i] = {d1.findParent(i), d2.findParent(i), d3.findParent(i)};
        byGroup[group[i]].push_back(i);
    }

    vector<vector<ll>> ans;
    for (auto& [key, val] : byGroup) {
        if (val.size() >= 2) {
            ans.push_back(val);
        }
    }
    sort(ans.begin(), ans.end());

    cout << ans.size() << '\n';
    for(auto& elem : ans) {
        for(auto& i : elem) {
            cout << i << ' ';
        }
        cout << '\n';
    }

    return 0;
}