#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
typedef long long ll;

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

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	// int t;
	// cin >> t;
	// while (t--)
	{
		int n;
		cin >> n;
		vector<ll> b(n), conv(1000002);

		for (int i = 0; i < n; i++)
		{
			ll temp;
			cin >> temp;
			conv[temp] = i;
		}
		for (int i = 0; i < n; i++)
		{
			cin >> b[i];
			b[i] = conv[b[i]];
		}

		int h = (int)ceil(log2(b.size() + 1));
		int treeSize = 1 << (h + 1);
		vector<ll> tree(treeSize);
		vector<ll> treeBase(b.size() + 1);
		init(treeBase, tree, 1, 0, b.size());

		ll ans = 0;
		for (int i = 0; i < n; i++)
		{
			ans += sum(tree, 1, 0, n, b[i], n);
			update(tree, 1, 0, n, b[i], 1);
		}
		cout << ans << '\n';
	}

	return 0;
}