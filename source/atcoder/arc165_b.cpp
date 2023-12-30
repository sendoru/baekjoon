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

    int n, k;
    cin >> n >> k;
    vector<int> perm(n);
    for(int i = 0; i < n; i++) {
        cin >> perm[i];
    }

    vector<int> increasing(n);
    for(int i = 1; i < n; i++) {
        if (perm[i] > perm[i - 1]) {
            increasing[i] = 1;
        }
    }

    int pos = -1;
    for(int i = 1; i <= n - k; i++) {
        if (!increasing[i - 1] && increasing[i]) {
            pos = i - 1;
        }
    }

    // 아
    // 연속된 k개의 증가부분수열이 있으면
    // 그냥 거기를 바꿔버리면 됨
    //

    vector<int> incCurSum(n);
    for(int i = 1; i < n; i++) {
        incCurSum[i] = incCurSum[i - 1] + increasing[i];
    }

    for(int i = k - 1; i < n; i++) {
        if (incCurSum[i] - incCurSum[i - (k - 1)] == k - 1) {
            pos = i - (k - 1);
        }
    }

    if (pos == -1) {
        pos = n - k;
    }
    auto perm1 = perm;
    sort(perm1.begin() + pos, perm1.begin() + pos + k);
    auto perm2 = perm;
    sort(perm2.end() - k, perm2.end());
    auto ans = max(perm1, perm2);

    for(int i : ans) {
        cout << i << ' ';
    }

    return 0;
}