#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
typedef long long ll;
constexpr ll MAX = 1000000;

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
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<pair<ll, ll>> ab(n);
	for (int i = 0; i < n; i++) cin >> ab[i].first;
	for (int i = 0; i < n; i++) cin >> ab[i].second;
	sort(ab.begin(), ab.end());

	vector<ll> segTree(2 * MAX + 5);
	ll ans = 0;
	ll idx = 0;
	for (int i = 0; i <= MAX; i++)
	{
		ll initIdx = idx;

		// 합구하기
		while (idx < ab.size() && i >= ab[idx].first)
		{
			ll cnt = sum(segTree, 1, 0, MAX, 0, ab[idx].second - 1);
			ans += cnt * (cnt - 1) / 2;
			idx++;
		}

		// 업데이트
		idx = initIdx;
		while (idx < ab.size() && i >= ab[idx].first)
		{
			ll cnt = sum(segTree, 1, 0, MAX, ab[idx].second, ab[idx].second);
			if (cnt == 0)
				update(segTree, 1, 0, MAX, ab[idx].second, 1);
			idx++;
		}
	}

	cout << ans;
	return 0;
}