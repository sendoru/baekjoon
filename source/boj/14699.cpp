#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <cmath>
using namespace std;
typedef long long ll;
const ll MOD = 1'000'000'007;

struct seg {
	int n;
	vector<int> tree;

	void update(int x, int v) {
		x += n;
		tree[x] = v;
		for (x /= 2; x > 0; x /= 2)
			tree[x] = tree[x * 2] + tree[x * 2 + 1];
	}

	int sum(int l, int r) {
		int ret = 0;
		for (l += n, r += n; l <= r; l /= 2, r /= 2) {
			if (l % 2)
				ret += tree[l++];
			if (r % 2 == 0)
				ret += tree[r--];
		}
		return ret;
	}

	int query(int x) {
		int acc, i;
		for (acc = 0, i = 1; i < n;) {
			if (acc + tree[i * 2] < x) {
				acc += tree[i * 2];
				i = i * 2 + 1;
			}
			else
				i = i * 2;
		}
		return i - n;
	}
};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	seg a, b;
	a.n = 1 << (int)ceil(log2(n+10));
	a.tree.resize(a.n * 2);
	b = a;

	for (int i = 0; i < n / 2; ++i) {
		a.update(i, 1);
		b.update(i, 1);
	}

	bool first = false, out = false;
	while (m--) {
		int q, x;
		cin >> q >> x;
		x--;
		if (q == 1) {
			if (n % 2 && x == n / 2) {
				out = true;
				a.update(n / 2, 0);
				b.update(n / 2, 0);
				continue;
			}
			if (n % 2 && !out && !first) {
				if (x < n / 2)
					a.update(n / 2, 1);
				else
					b.update(n / 2, 1);
				first = true;
			}
			if (x < n / 2)
				a.update(x, 0);
			else
				b.update(n-1-x, 0);
		}
		else {
			if (n % 2 && x == n / 2)
				cout << (out || first ? 0 : n / 2 + 1) << '\n';
			else if (x < n / 2)
				cout << (a.query(x + 1) == a.n-1 ? 0 : a.query(x+1)+1) << '\n';
			else
				cout << (b.query(n - x) == b.n-1 ? 0 : n-b.query(n - x)) << '\n';
		}
	}

	return 0;
}