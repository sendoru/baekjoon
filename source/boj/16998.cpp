#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll getGCD(ll a, ll b)
{
    if (b == 0) return a;
    return getGCD(b, a % b);
}

ll naiveSolve(ll p, ll q, ll n)
{
    ll ret = 0;
    for(int i = 1; i <= n; i++)
        ret += p * i % q;
    
    return ret;
}

// solve sum (i=1 to n) floor(pi/q)
ll f(ll p, ll q, ll n)
{
    if (p == 0 || n == 0 || n * (p * n / q) == 0) return 0;
    if (p >= q)
        return f(p % q, q, n) + (n * (n + 1) / 2) * (p / q);
    return n * (p * n / q) + (n / q) - f(q, p, (p * n / q));
}


ll solve(ll p, ll q, ll n)
{
    p %= q;
    ll gcd = getGCD(p, q);
    p /= gcd;
    q /= gcd;
    ll sub = f(p, q, n);
    ll ret = gcd * (p * n * (n + 1) / 2 - q * sub);
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int w;
    cin >> w;
    while(w--)
    {
        ll p, q, n;
        cin >> p >> q >> n;
        cout << solve(p, q, n) << '\n';
        // cout << flush;
    }
    
    return 0;
}