#include <iostream>
#include <cmath>
#include <vector>
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

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<ll> a(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	int treeSize = 1 << ((int)(ceil(log2(n + 1))) + 1);
	vector<ll> tree(treeSize);
	init(a, tree, 1, 0, n);

	int m;
	cin >> m;
	vector<vector<ll>> q1, q2;
	for (int i = 0; i < m; i++)
	{
		ll q;
		cin >> q;
		if (q == 1)
		{
			ll idx, v;
			cin >> idx >> v;
			ll diff = v - a[idx];
			a[idx] = v;
			q1.push_back({ idx, diff });
		}
		else if (q == 2)
		{
			ll k, l, r;
			cin >> k >> l >> r;
			q2.push_back({ k, l, r, (ll)q2.size() });
		}
	}
	sort(q2.begin(), q2.end());
	vector<ll> ans(q2.size());
	for (int i = 0; i < q2[0][0]; i++)
	{
		update(tree, 1, 0, n, q1[i][0], q1[i][1]);
	}
	ans[q2[0][3]] = sum(tree, 1, 0, n, q2[0][1], q2[0][2]);
	for (int i = 1; i < q2.size(); i++)
	{
		for (int j = q2[i - 1][0]; j < q2[i][0]; j++)
		{
			update(tree, 1, 0, n, q1[j][0], q1[j][1]);
		}
		ans[q2[i][3]] = sum(tree, 1, 0, n, q2[i][1], q2[i][2]);
	}

	for (auto elem : ans) cout << elem << '\n';
	return 0;
}
