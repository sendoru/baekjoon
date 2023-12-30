//
// Created by sendo on 2023-01-28.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s, t;
    cin >> s >> t;

    // v1[i]: 앞에서부터 i개 매칭 가능?
    // v2[i]: 뒤에서부터 i개 매칭 가능?
    vector<bool> v1(t.length() + 1), v2(t.length() + 1);
    v1[0] = true;
    v2[0] = true;
    for(int i = 1; i <= t.length(); i++) {
        if (s[i - 1] == t[i - 1] || s[i - 1] == '?' || t[i - 1] == '?')
            v1[i] = true;
        else
            break;
    }

    for(int i = 1; i <= t.length(); i++) {
        if (s[s.length() - i] == t[t.length() - i] || s[s.length() - i] == '?' || t[t.length() - i] == '?')
            v2[i] = true;
        else
            break;
    }

    for(int i = 0; i <= t.length(); i++) {
        if (v1[i] && v2[t.length() - i])
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}