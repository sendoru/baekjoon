#include <iostream>
#include <cmath>
#include <vector>
#define MAX 200001ll
#define MOD 1'000'000'007ll

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
	vector<ll> loc(n);
	for (int i = 0; i < n; i++) cin >> loc[i];
	ll treeSize = 1ll << (ll)ceil(log2((MAX + 1) << 1));
	vector<ll> cnt(treeSize), dist(treeSize);
	update(cnt, 1, 0, MAX + 1, loc[0], 1);
	update(dist, 1, 0, MAX + 1, loc[0], loc[0]);

	ll ans = 1;
	for (int i = 1; i < n; i++)
	{
		ll curCost = 0;
		curCost += sum(cnt, 1, 0, MAX + 1, 0, loc[i] - 1) * loc[i] - sum(dist, 1, 0, MAX + 1, 0, loc[i] - 1);
		curCost += sum(dist, 1, 0, MAX + 1, loc[i] + 1, MAX + 1) - sum(cnt, 1, 0, MAX + 1, loc[i] + 1, MAX + 1) * loc[i];
		update(cnt, 1, 0, MAX + 1, loc[i], 1);
		update(dist, 1, 0, MAX + 1, loc[i], loc[i]);
		ans *= curCost % MOD;
		ans %= MOD;
	}

	cout << ans;
	return 0;
}