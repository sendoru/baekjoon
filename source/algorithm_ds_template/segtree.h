#include <vector>
#include <iostream>
#include <cmath>
#include <cassert>
typedef long long ll;
using namespace std;

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