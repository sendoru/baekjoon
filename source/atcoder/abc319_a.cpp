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

    map<string, int> m = {
            {"tourist", 3858},
            {"ksun48", 3679},
            {"Benq", 3658},
            {"Um_nik", 3648},
            {"apiad", 3638},
            {"Stonefeang", 3630},
            {"ecnerwala", 3613},
            {"mnbvmar", 3555},
            {"newbiedmy", 3516},
            {"semiexp", 3481},
    };

    string s;
    cin >> s;
    cout << m[s];

    return 0;
}