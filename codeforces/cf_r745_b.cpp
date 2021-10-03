#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		ll n, m, k;
		cin >> n >> m >> k;
		bool ans = false;
		// 연결 그래프를 만들기 위한 최소한의 간선 갯수 mMin = n - 1;
		// 최대한의 간선 갯수 mMax = n * (n - 1) / 2
		if (m < n - 1 || m > n * (n - 1) / 2ll)
			ans = false;

		// 어떠한 경우에도 지름을 2 이하로 만들 수 있음
		else if (k >= 4)
			ans = true;

		// 지름이 1이 되려면 모든 간선이 다른 간선과 직접 연결되있어야 함
		// 즉 m == n * (n - 1) / 2
		else if (k == 3 && m == n * (n - 1) / 2)
			ans = true;

		// 지름이 0이 되려면 정점이 하나여야 함
		else if (k == 2 && n == 1)
			ans = true;

		cout << (ans ? "YES" : "NO") << '\n';
	}
	return 0;
}