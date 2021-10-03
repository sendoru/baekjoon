#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
constexpr ll MOD = 998244353, MAX = 300003;

// a: 처음 주어지는 벡터
// tree: 세그먼트 트리
// node: 세그먼트 트리의 노드 번호
// start, end: 세그먼트 트리가 담당하는 합의 범위가 start ~ end
ll init(vector<ll>& a, vector<ll>& tree, int node, int start, int end) {
	// node가 리프 노드인 경우
	if (start == end) return tree[node] = a[start];

	else return tree[node] = (init(a, tree, node * 2, start, (start + end) / 2) + init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end)) % MOD;
}

// left, right: 합을 구하는 범위가 left ~ right
// 나머지 지역변수는 init랑 똑같음
ll sum(vector<ll>& tree, int node, int start, int end, int left, int right) {
	// 구간 [start, end]와 [left, right]가 겹치지 않을 경우
	if (left > end || right < start) return 0;
	// 구간 [left, right]가 구간 [start, end]를 완전히 포함할 경우
	if (left <= start && right >= end) return tree[node];
	return (sum(tree, node * 2, start, (start + end) / 2, left, right) + sum(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right)) % MOD;
}

// diff: (업데이트하려는 값) - (기존 값)
void update(vector<ll>& tree, int node, int start, int end, int index, ll diff) {
	if (index < start || index > end) return;

	if (start != end) {
		update(tree, node * 2, start, (start + end) / 2, index, diff);
		update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
	}
	tree[node] += diff;
	tree[node] % MOD;
}


ll modPow(ll base, ll exp)
{
	ll ret = 1;
	while (exp > 0)
	{
		if (exp % 2 == 1)
		{
			ret *= base;
			ret %= MOD;
		}
		base *= base;
		base %= MOD;
		exp /= 2;
	}
	return ret;
}

int main(void)
{
	int n;
	cin >> n;
	vector<ll> pows(MAX), invs(MAX);
	pows[0] = 1, invs[0] = 1, invs[1] = modPow(2, MOD - 2);
	for (int i = 1; i < MAX; i++)
	{
		pows[i] = (pows[i - 1] * 2) % MOD;
		invs[i] = (invs[i - 1] * invs[1]) % MOD;
	}

	vector<pair<ll, ll>> a(n);
	vector<pair<ll, ll>> compressed(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].first;
		a[i].second = i;
		compressed[i].first = a[i].first;
		compressed[i].second = i;
	}
	sort(a.begin(), a.end());
	sort(compressed.begin(), compressed.end());
	compressed[0].first = 0;
	for (int i = 1; i < compressed.size(); i++)
	{
		if (a[i].first == a[i - 1].first) compressed[i].first = compressed[i - 1].first;
		else compressed[i].first = compressed[i - 1].first + 1;
	}
	sort(compressed.begin(), compressed.end(), [](pair<ll, ll> a, pair<ll, ll> b) { return a.second < b.second; });

	vector<ll> segTree(1ll << ((ll)(ceil(log2l(compressed.size())) + 1)));
	ll ans = 0;
	for (int i = 0; i < compressed.size(); i++)
	{
		ans += sum(segTree, 1, 0, compressed.size() - 1, 0, compressed[i].first) * pows[i];
		ans %= MOD;
		update(segTree, 1, 0, compressed.size() - 1, compressed[i].first, invs[i + 1]);
	}
	cout << ans;
	return 0;
}