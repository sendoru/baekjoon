'''
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (ll &x : a)
        cin >> x;

    auto b = a;
    sort(b.begin(), b.end());

    for (int i=0; i<n; ++i) {
        __uint128_t x = 1;
        x = x * a[i] * b[i];
        __uint128_t lo = 1, hi = x+1;
        while (lo + 1 < hi) {
            const __uint128_t mid = (lo + hi) / 2;
            if (mid*mid <= x)
                lo = mid;
            else
                hi = mid;
        }
        if (lo*lo != x) {
            cout << "NO";
            return;
        }
    }
    cout << "YES";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

'''

import sys
input = lambda: sys.stdin.readline().rstrip()

def main():
    n = int(input())
    a = list(map(int, input().split()))
    b = a.copy()
    b.sort()
    for i in range(len(a)):
        x = a[i] * b[i]
        lo = 1
        hi = x + 1
        while lo + 1 < hi:
            mid = (lo + hi) // 2
            if mid * mid <= x:
                lo = mid
            else:
                hi = mid

        if lo * lo != x:
            print("NO")
            return
    
    print("YES")

if __name__ == "__main__":
    main()