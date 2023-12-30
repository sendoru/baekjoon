#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
typedef long long ll;

// a: 처음 주어지는 벡터
// tree: 세그먼트 트리
// node: 세그먼트 트리의 노드 번호
// start, end: 세그먼트 트리가 담당하는 합의 범위가 start ~ end
ll init(vector<ll>& a, vector<ll>& tree, int node, int start, int end) {
	// node가 리프 노드인 경우
	if (start == end) return tree[node] = a[start];

	else return tree[node] = init(a, tree, node * 2, start, (start + end) / 2) + init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);
}

// left, right: 합을 구하는 범위가 left ~ right
// 나머지 지역변수는 init랑 똑같음
ll sum(vector<ll>& tree, int node, int start, int end, int left, int right) {
	// 구간 [start, end]와 [left, right]가 겹치지 않을 경우
	if (left > end || right < start) return 0;
	// 구간 [left, right]가 구간 [start, end]를 완전히 포함할 경우
	if (left <= start && right >= end) return tree[node];
	return sum(tree, node * 2, start, (start + end) / 2, left, right) + sum(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

// diff: (업데이트하려는 값) - (기존 값)
void update(vector<ll>& tree, int node, int start, int end, int index, ll diff) {
	if (index < start || index > end) return;

	tree[node] += diff;
	if (start != end) {
		update(tree, node * 2, start, (start + end) / 2, index, diff);
		update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<pair<ll, ll>> a(n), compressed(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i].first;
			compressed[i].first = a[i].first;
			a[i].second = i;
			compressed[i].second = a[i].second;
		}
		sort(a.begin(), a.end());
		sort(compressed.begin(), compressed.end());
		compressed[0].first = 0;
		for (int i = 1; i < n; i++)
		{
			if (a[i].first == a[i - 1].first) compressed[i].first = compressed[i - 1].first;
			else compressed[i].first = compressed[i - 1].first + 1;
		}
		int maxVal = compressed.back().first;
		sort(compressed.begin(), compressed.end(), [](pair<ll, ll> a, pair<ll, ll> b) {return a.second < b.second; });

		vector<ll> aa(n);
		for (int i = 0; i < n; i++) aa[i] = compressed[i].first;
		a.clear(); compressed.clear();
		vector<ll> segTree(1ll << ((ll)ceil(log2l(maxVal + 4)) + 1));

		ll ans = 0;
		update(segTree, 1, 0, maxVal + 3, aa[0], 1);
		for (int i = 1; i < n; i++)
		{
			ll lower = sum(segTree, 1, 0, maxVal + 3, 0, aa[i] - 1);
			ll upper = sum(segTree, 1, 0, maxVal + 3, aa[i] + 1, maxVal + 3);
			ans += min(lower, upper);
			update(segTree, 1, 0, maxVal + 3, aa[i], 1);
		}

		cout << ans << '\n';
	}

	return 0;
}