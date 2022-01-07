#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
typedef long long ll;
constexpr ll INF = 98765432100;
using namespace std;


ll min(ll a, ll b)
{
	return a < b ? a : b;
}

ll max(ll a, ll b)
{
	return a > b ? a : b;
}

template <typename T>
T initMin(vector<T>& a, vector<T>& tree, int node, int start, int end)
{
	// node�� ���� ����� ���
	if (start == end)
	{
		return tree[node] = a[start];
	}
	else
	{
		return tree[node] = min(initMin(a, tree, node * 2, start, (start + end) / 2), initMin(a, tree, node * 2 + 1, (start + end) / 2 + 1, end));
	}
}

template <typename T>
T initMax(vector<T>& a, vector<T>& tree, int node, int start, int end)
{
	// node�� ���� ����� ���
	if (start == end)
	{
		return tree[node] = a[start];
	}
	else
	{
		return tree[node] = max(initMax(a, tree, node * 2, start, (start + end) / 2), initMax(a, tree, node * 2 + 1, (start + end) / 2 + 1, end));
	}
}

template <typename T>
// left, right: �ּڰ��� ���ϴ� ������ left ~ right
// ������ ���������� init�� �Ȱ���
T getMin(vector<T>& tree, int node, int start, int end, int left, int right)
{
	// ���� [start, end]�� [left, right]�� ��ġ�� ���� ���
	if (left > end || right < start)
	{
		return make_pair(INF, INF);
	}
	// ���� [left, right]�� ���� [start, end]�� ������ ������ ���
	if (left <= start && right >= end)
	{
		return tree[node];
	}
	return min(getMin(tree, node * 2, start, (start + end) / 2, left, right), getMin(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}

template <typename T>
T getMax(vector<T>& tree, int node, int start, int end, int left, int right)
{
	// ���� [start, end]�� [left, right]�� ��ġ�� ���� ���
	if (left > end || right < start)
	{
		return make_pair(-INF, -INF);
	}
	// ���� [left, right]�� ���� [start, end]�� ������ ������ ���
	if (left <= start && right >= end)
	{
		return tree[node];
	}
	return max(getMax(tree, node * 2, start, (start + end) / 2, left, right), getMax(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<ll> initVec(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> initVec[i];
	}
	vector<pair<ll, ll>> prefixSum(n + 1);
	for (int i = 1; i <= n; i++)
	{
		prefixSum[i].first = prefixSum[i - 1].first + initVec[i];
		prefixSum[i].second = i;
	}
	
	ll treeSize = 1;
	while (treeSize < prefixSum.size() * 2)
	{
		treeSize <<= 1;
	}
	vector<pair<ll, ll>> minTree(treeSize), maxTree(treeSize);
	initMin(prefixSum, minTree, 1, 0, n);
	initMax(prefixSum, maxTree, 1, 0, n);

	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		auto maxSum = getMax(maxTree, 1, 0, n, x2, y2);
		int maxIndex = maxSum.second;
		auto minSum = getMin(minTree, 1, 0, n, x1 - 1, min(y1, maxIndex) - 1);
		ll ans = maxSum.first - minSum.first;
		minSum = getMin(minTree, 1, 0, n, x1 - 1, y1 - 1);
		int minIndex = minSum.second;
		maxSum = getMax(maxTree, 1, 0, n, max(x2, minIndex + 1), y2);
		ans = max(ans, maxSum.first - minSum.first);
		cout << ans << '\n';
	}
	return 0;
}