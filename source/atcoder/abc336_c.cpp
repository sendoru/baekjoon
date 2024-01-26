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

    ll n;
    cin >> n;
    n--;
    vector<char> str_stack;
    while(n != 0) {
        str_stack.push_back('0' + (n % 5) * 2);
        n /= 5;
    }
    
    if (str_stack.empty()) {
        cout << 0;
    }

    while (!str_stack.empty()) {
        cout << str_stack.back();
        str_stack.pop_back();
    }

    return 0;
}