#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;
constexpr ll MAX = 2000002;

// a: 처음 주어지는 벡터
// tree: 세그먼트 트리
// node: 세그먼트 트리의 노드 번호
// start, end: 세그먼트 트리가 담당하는 합의 범위가 start ~ end
ll init(vector<ll>& a, vector<ll>& tree, int node, int start, int end)
{
	// node가 리프 노드인 경우
	if (start == end)
	{
		return tree[node] = a[start];
	}
	else
	{
		return tree[node] = init(a, tree, node * 2, start, (start + end) / 2) + init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);
	}
}

// left, right: 합을 구하는 범위가 left ~ right
// 나머지 지역변수는 init랑 똑같음
ll sum(vector<ll>& tree, int node, int start, int end, int left, int right)
{
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
	return sum(tree, node * 2, start, (start + end) / 2, left, right) + sum(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

// diff: (업데이트하려는 값) - (기존 값)
void update(vector<ll>& tree, int node, int start, int end, int index, ll diff)
{
	if (index < start || index > end) return;

	tree[node] += diff;

	if (start != end)
	{
		update(tree, node * 2, start, (start + end) / 2, index, diff);
		update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
	}
}

int bSearch(vector<ll>& tree, int node, int left, int right, int target)
{
	if (left == right)
	{
		return left;
	}
	int mid = (left + right) / 2;
	if (tree[node * 2] >= target)
	{
		return bSearch(tree, node * 2, left, mid, target);
	}
	target -= tree[node * 2];
	if (tree[node * 2 + 1] >= target)
	{
		return bSearch(tree, node * 2 + 1, mid + 1, right, target);
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<ll> a(MAX);
	int h = (int)ceil(log2(MAX));
	int treeSize = 1 << (h + 1);
	vector<ll> tree(treeSize);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		ll t, x;
		cin >> t >> x;
		if (t == 1)
		{
			update(tree, 1, 0, MAX - 1, x, 1);

		}
		else if (t == 2)
		{
			int index = bSearch(tree, 1, 0, MAX - 1, x);
			cout << index << '\n';
			update(tree, 1, 0, MAX - 1, index, -1);
		}
	}

	return 0;
}