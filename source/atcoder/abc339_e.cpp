#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MOD9 = 998244353;
const ll MOD1 = (ll)1e9 + 7;

template<typename T, T(*op)(T, T), T id>
class SegTree
{
	vector<T> v;
	ll leafCnt;
	ll height;
	void update(ll k) { v[k] = op(v[2 * k], v[2 * k + 1]); }

public:
	SegTree(ll leafCnt_)
	{
		height = (ll)ceill(log2l(leafCnt_) + 1);
		leafCnt = 1ll << (height - 1);
		v = vector<T>(1ll << height, id);
	}
	SegTree(const vector<T>& orig)
	{
		height = (ll)ceill(log2l(orig.size()) + 1);
		leafCnt = 1ll << (height - 1);
		v = vector<T>(1ll << height, id);
		for (ll i = 0; i < orig.size(); i++)
		{
			v[i + leafCnt] = orig[i];
		}
		for (ll i = height - 1; i > 0; i--)
		{
			for (ll j = (1ll << (i - 1)); j < (1ll << i); j++)
			{
				update(j);
			}
		}
	}

	void set(ll idx, T val)
	{
		assert(idx >= 0 && idx < leafCnt);
		idx += leafCnt;
		v[idx] = val;
		while (!idx != 1)
		{
			idx >>= 1;
			update(idx);
		}
	}

	T get(ll idx)
	{
		assert(idx >= 0 && idx < leafCnt);
		return v[idx + leafCnt];
	}

    // prod in CLOSED RANGE [l, r], NOT SEMI-CLOSED RANGE [l, r)!!!
	T prod(ll l, ll r)
	{
		assert(0 <= l && l <= r && r < leafCnt);
		T ll = id, rr = id;
		l += leafCnt;
		r += leafCnt;
		while (l <= r)
		{
			if (l & 1)
			{
				ll = op(ll, v[l]);
				l++;
			}
			if (!(r & 1))
			{
				rr = op(rr, v[r]);
				r--;
			}
			l >>= 1;
			r >>= 1;
		}

		return op(ll, rr);
	}

	T allProd()
	{
		return v[1];
	}
};

int max(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    SegTree<int, max, -MOD1> seg(500'010);

    // dp[i] := i번째 원소가 rightmost인 것 중 조건을 만족하는 가장 진 subseq의 길이
    vector<int> dp(n);
    dp[0] = 1;
    seg.set(a[0], 1);
    int ans = 1;

    for(int i = 1; i < n; i++) {
        int left = max(0, a[i] - d), right = min(500'001, a[i] + d);
        dp[i] = max(1, seg.prod(left, right) + 1);
        ans = max(ans, dp[i]);
        if (seg.get(a[i]) < dp[i]) {
            seg.set(a[i], dp[i]);
        }
    }

    cout << ans;


    return 0;
}