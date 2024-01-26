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

    int n;
    cin >> n;

    string s, t;
    cin >> s >> t;

    // does greedy works?

    // s[i] == 'A', t[i] == 'B'이고 

    vector<int> a, b, b_to_a;
    set<int> a_to_b;


    for (int i = 0; i < n; i++) {
        if (s[i] == 'A' && t[i] == 'A') {
            a.push_back(i);
        }
        else if (s[i] == 'A' && t[i] == 'B') {
            a_to_b.insert(i);
        }
        else if (s[i] == 'B' && t[i] == 'A') {
            b_to_a.push_back(i);
        }
        else {
            b.push_back(i);
        }
    }

    // 가능한 조건 :    a_to_b의 최솟값이 a의 최솟값보다 크거나 b_to_a의 최솟값보다 큼
    //             AND b_to_a의 최댓값이 b의 최댓값보다 작거나 a_to_b의 최댓값보다 작
    // 가능할 때 최소 횟수의 하한은 min(a_to_b.size(), b_to_a.size()) 이긴한데

    int low_th = 998244353, high_th = -MOD9;
    if (!a.empty()) {
        low_th = min(low_th, *a.begin());
    }
    if (!b_to_a.empty()) {
        low_th = min(low_th, *b_to_a.begin());
    }

    if (!b.empty()) {
        high_th = max(high_th, *(--b.end()));
    }

    if (!a_to_b.empty()) {
        high_th = max(high_th, *(--a_to_b.end()));
    }

    if ((a_to_b.empty() || *(a_to_b.begin()) > low_th) && (b_to_a.empty() || *(--b_to_a.end()) < high_th)) {
        int ans = 0;
        for(auto iter = b_to_a.begin(); iter != b_to_a.end(); iter++) {
            ans++;
            auto a_to_b_iter = a_to_b.lower_bound(*iter);
            if (a_to_b_iter != a_to_b.end()) {
                a_to_b.erase(a_to_b_iter);
            }
        }
        ans += a_to_b.size();

        cout << ans;
    }

    else {
        cout << -1;
    }


    return 0;
}