#include <iostream>
#include <cmath>
#include <vector>

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

	int N;
	cin >> N;
	vector<ll> a(N);
	int h = (int)ceil(log2(N));
	int treeSize = 1 << (h + 1);
	vector<ll> tree(treeSize);

	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
		a[i] %= 2;
	}

	int M;
	cin >> M;

	init(a, tree, 1, 0, N - 1);
	for (int i = 0; i < M; i++)
	{
		ll q1, q2, q3;
		cin >> q1;
		if (q1 == 1)
		{
			cin >> q2 >> q3;
			q2--;
			q3 %= 2;
			ll diff = q3 - a[q2];
			a[q2] = q3;
			update(tree, 1, 0, N - 1, q2, diff);
		}
		else if (q1 == 2)
		{
			cin >> q2 >> q3;
			cout << (q3 - q2 + 1) - sum(tree, 1, 0, N - 1, q2 - 1, q3 - 1) << '\n';
		}
		else if (q1 == 3)
		{
			cin >> q2 >> q3;
			cout << sum(tree, 1, 0, N - 1, q2 - 1, q3 - 1) << '\n';
		}
	}

	return 0;
}