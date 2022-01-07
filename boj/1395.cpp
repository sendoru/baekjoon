#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
typedef long long ll;

// a: 처음 주어지는 벡터
// tree: 세그먼트 트리
// node: 세그먼트 트리의 노드 번호
// start, end: 세그먼트 트리가 담당하는 합의 범위가 start ~ end
vector<ll> init(vector<ll>& a)
{
	int n = a.size();
	int h = (int)ceil(log2(n));
	a.resize(1ll << h);
	vector<ll> segTree(1ll << (h + 1));

	for (int i = 1ll << h; i < 1ll << (h + 1); i++)
	{
		segTree[i] = a[i - (1ll << h)];
	}

	h--;
	while (h >= 0)
	{
		for (int i = 1 << h; i < 1 << (h + 1); i++)
		{
			segTree[i] = segTree[2 * i] + segTree[2 * i + 1];
		}
		h--;
	}

	return segTree;
}


void updateLazy(vector<ll>& tree, vector<ll>& lazy, int node, int start, int end)
{
	if (lazy[node] != 0)
	{
		tree[node] = end - start + 1 - tree[node];
		if (start != end)
		{
			lazy[node * 2] = !lazy[node * 2];
			lazy[node * 2 + 1] = !lazy[node * 2 + 1];
		}
		lazy[node] = 0;
	}
}

void updateRange(vector<ll>& tree, vector<ll>& lazy, int node, int start, int end, int left, int right, ll diff)
{
	updateLazy(tree, lazy, node, start, end);
	if (left > end || right < start)
	{
		return;
	}
	if (left <= start && right >= end)
	{
		tree[node] = end - start + 1 - tree[node];
		if (start != end)
		{
			lazy[node * 2] = !lazy[node * 2];
			lazy[node * 2 + 1] = !lazy[node * 2 + 1];
		}
		return;
	}
	updateRange(tree, lazy, node * 2, start, (start + end) / 2, left, right, diff);
	updateRange(tree, lazy, node * 2 + 1, (start + end) / 2 + 1, end, left, right, diff);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}


// left, right: 합을 구하는 범위가 left ~ right
// 나머지 지역변수는 init랑 똑같음
ll sum(vector<ll>& tree, vector<ll>& lazy, int node, int start, int end, int left, int right)
{
	updateLazy(tree, lazy, node, start, end);
	// 구간 [start, end]와 [left, right]가 겹치지 않을 경우
	if (left > end || right < start)
	{
		return 0;
	}
	// 구간 [left, right]가 구간 [start, end]를 완전히 포함할 경우
	if (left <= start && right >= end)
	{
		return tree[node];
	}
	return sum(tree, lazy, node * 2, start, (start + end) / 2, left, right) + sum(tree, lazy, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n;
	vector<ll> a(n);
	vector<ll> tree = init(a);
	vector<ll> lazy(tree.size());

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		ll q1, q2, q3, q4;
		cin >> q1;
		if (q1 == 0)
		{
			cin >> q2 >> q3;
			updateRange(tree, lazy, 1, 0, a.size() - 1, q2 - 1, q3 - 1, 1);
		}
		else if (q1 == 1)
		{
			cin >> q2 >> q3;
			cout << sum(tree, lazy, 1, 0, a.size() - 1, q2 - 1, q3 - 1) << '\n';
		}
	}

	return 0;
}