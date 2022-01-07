#include <iostream>
#include <cmath>
#include <vector>
#define INF 9998765643210

using namespace std;
typedef long long ll;

// a: 처음 주어지는 벡터
// tree: 세그먼트 트리
// node: 세그먼트 트리의 노드 번호
// start, end: 세그먼트 트리가 담당하는 합의 범위가 start ~ end
ll min(ll a, ll b)
{
	return a < b ? a : b;
}

ll max(ll a, ll b)
{
	return a > b ? a : b;
}

ll initMin(vector<ll>& a, vector<ll>& tree, int node, int start, int end)
{
	// node가 리프 노드인 경우
	if (start == end)
	{
		return tree[node] = a[start];
	}
	else
	{
		return tree[node] = min(initMin(a, tree, node * 2, start, (start + end) / 2), initMin(a, tree, node * 2 + 1, (start + end) / 2 + 1, end));
	}
}

ll initMax(vector<ll>& a, vector<ll>& tree, int node, int start, int end)
{
	// node가 리프 노드인 경우
	if (start == end)
	{
		return tree[node] = a[start];
	}
	else
	{
		return tree[node] = max(initMax(a, tree, node * 2, start, (start + end) / 2), initMax(a, tree, node * 2 + 1, (start + end) / 2 + 1, end));
	}
}

// left, right: 최솟값을 구하는 범위가 left ~ right
// 나머지 지역변수는 init랑 똑같음
ll getMin(vector<ll>& tree, int node, int start, int end, int left, int right)
{
	// 구간 [start, end]와 [left, right]가 겹치지 않을 경우
	if (left > end || right < start)
	{
		return INF;
	}
	// 구간 [left, right]가 구간 [start, end]를 완전히 포함할 경우
	if (left <= start && right >= end)
	{
		return tree[node];
	}
	return min(getMin(tree, node * 2, start, (start + end) / 2, left, right), getMin(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}

ll getMax(vector<ll>& tree, int node, int start, int end, int left, int right)
{
	// 구간 [start, end]와 [left, right]가 겹치지 않을 경우
	if (left > end || right < start)
	{
		return -INF;
	}
	// 구간 [left, right]가 구간 [start, end]를 완전히 포함할 경우
	if (left <= start && right >= end)
	{
		return tree[node];
	}
	return max(getMax(tree, node * 2, start, (start + end) / 2, left, right), getMax(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}

void updateMin(vector<ll>& tree, int node, int start, int end, int index, ll target)
{
	if (index == start && index == end)
	{
		tree[node] = target;
		return;
	}

	if (index < start || index > end) return;

	tree[node] = min(target, tree[node]);

	if (start != end)
	{
		updateMin(tree, node * 2, start, (start + end) / 2, index, target);
		updateMin(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, target);
		tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
	}
}

void updateMax(vector<ll>& tree, int node, int start, int end, int index, ll target)
{
	if (index == start && index == end)
	{
		tree[node] = target;
		return;
	}

	if (index < start || index > end) return;

	tree[node] = max(target, tree[node]);

	if (start != end)
	{
		updateMax(tree, node * 2, start, (start + end) / 2, index, target);
		updateMax(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, target);
		tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
	}
}

int main(void)
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;

		vector<ll> dvds(n + 1);
		for (int i = 1; i <= n; i++)
		{
			dvds[i] = i;
		}

		int treeSize = 1 << ((int)ceil(log2(n + 1)) + 1);
		vector<ll> minTree(treeSize, INF);
		vector<ll> maxTree(treeSize, -INF);
		initMin(dvds, minTree, 1, 0, n);
		initMax(dvds, maxTree, 1, 0, n);

		for (int i = 0; i < m; i++)
		{
			int q, a, b;
			cin >> q >> a >> b;
			if (q == 0)
			{
				ll dvdA = getMax(maxTree, 1, 0, n, a, a), dvdB = getMax(maxTree, 1, 0, n, b, b);
				updateMin(minTree, 1, 0, n, a, dvdB);
				updateMin(minTree, 1, 0, n, b, dvdA);
				updateMax(maxTree, 1, 0, n, a, dvdB);
				updateMax(maxTree, 1, 0, n, b, dvdA);
			}
			else if (q == 1)
			{
				if (getMax(maxTree, 1, 0, n, a, b) == max(a, b) && getMin(minTree, 1, 0, n, a, b) == min(a, b))
				{
					cout << "YES\n";
				}
				else
				{
					cout << "NO\n";
				}
			}
		}
	}

	return 0;
}