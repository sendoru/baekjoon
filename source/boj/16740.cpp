//
// Created by sendo on 2023-01-27.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v(n);
    for(int& i : v)
        cin >> i;
    sort(v.begin(), v.end());

    int ans = 2;
    // dp[i]의 {key, val} : i번째 수까지 썼을 때, 공차가 key인 등차수열의 최대 길이가 val
    map<int, int> dp[n];
    dp[1] = {{v[1] - v[0], 2}};
    for(int i = 2; i < n; i++) {
        // i번째 수를 확인할 때, 등차수열의 직전 항이 v[0] ~ v[i - 1]인 경우 모두 확인
        // = O(n^2)
        for(int j = 0; j < i; j++) {
            if (dp[j].find(v[i] - v[j]) == dp[j].end()) {
                dp[i][v[i] - v[j]] = 2;
            }
            else {
                dp[i][v[i] - v[j]] = dp[j][v[i] - v[j]] + 1;
            }

            // v[i + 1]과 v[j]를 매칭할 때는 공차가 v[i] - v[j]초과일 건 확실함
            auto iter = dp[j].begin();
            while (iter != dp[j].end() && (*iter).first <= v[i] - v[j])
                iter = dp[j].erase(iter);
        }
        for(auto& elem : dp[i])
            ans = max(ans, elem.second);
    }

    cout << ans;
    return 0;
}