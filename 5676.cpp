#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#define MOD 1000000007

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
		return tree[node] = (init(a, tree, node * 2, start, (start + end) / 2) * init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end));
	}
}

// left, right: 합을 구하는 범위가 left ~ right
// 나머지 지역변수는 init랑 똑같음
ll product(vector<ll>& tree, int node, int start, int end, int left, int right)
{
	// 구간 [start, end]와 [left, right]가 겹치지 않을 경우
	if (left > end || right < start)
	{
		return 1;
	}
	// 구간 [left, right]가 구간 [start, end]를 완전히 포함할 경우
	if (left <= start && right >= end)
	{
		return tree[node];
	}
	return (product(tree, node * 2, start, (start + end) / 2, left, right) * product(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}

// diff: (업데이트하려는 값) - (기존 값)
void update(vector<ll>& tree, int index, ll newValue)
{
	int node = tree.size() / 2 + index;
	tree[node] = newValue;
	node /= 2;
	while (node != 0)
	{
		tree[node] = (tree[node * 2] * tree[node * 2 + 1]);
		node /= 2;
	}

}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (true)
	{
		int N, K, temp;
		string ans = "";
		cin >> N >> K;
		if (cin.eof())
		{
			break;
		}
		int h = (int)ceil(log2(N));
		int treeSize = 1 << (h + 1);
		vector<ll> a(N, 1);
		vector<ll> tree(treeSize, 1);

		for (int i = 0; i < N; i++)
		{
			cin >> temp;
			if (temp > 0)
			{
				a[i] = 1;
			}
			else if (temp == 0)
			{
				a[i] = 0;
			}
			else
			{
				a[i] = -1;
			}
		}
		a.resize(1ll << h);
		for (int i = N; i < a.size(); i++)
		{
			a[i] = 1;
		}
		N = 1 << h;

		init(a, tree, 1, 0, N - 1);
		for (int i = 0; i < K; i++)
		{
			char q1;
			ll q2, q3;
			cin >> q1;
			if (q1 == 'C')
			{
				cin >> q2 >> q3;
				q2--;
				if (q3 != 0)
				{
					q3 = q3 / abs(q3);
				}
				a[q2] = q3;
				update(tree, q2, q3);
			}
			else if (q1 == 'P')
			{
				cin >> q2 >> q3;
				ll p = product(tree, 1, 0, N - 1, q2 - 1, q3 - 1);
				if (p > 0)
				{
					ans += '+';
				}
				else if (p == 0)
				{
					ans += '0';
				}
				else
				{
					ans += '-';
				}
			}
		}

		cout << ans << '\n';
	}

	return 0;
}