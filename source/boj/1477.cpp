#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main(void)
{
	int n, m, l;
	cin >> n >> m >> l;
	vector<int> rest(n);
	for (int i = 0; i < n; i++)
	{
		cin >> rest[i];
	}
	rest.push_back(0);
	rest.push_back(l);
	sort(rest.begin(), rest.end());
	int pLeft = 0, pRight = l, ans = l;
	// 이게몰까
	while (pLeft <= pRight)
	{
		if (pRight == 0)
		{
			ans = 1;
			break;
		}
		int mid = (pRight + pLeft) / 2, cnt = 0;
		// cnt := 최대 거리의 최솟값을 mid로 만들기 위해 필요한 최소한의 휴게소 갯수
		for (int i = 1; i < rest.size(); i++)
		{
			cnt += (rest[i] - rest[i - 1] - 1) / mid;
		}
		// 최대 거리의 최솟값을 mid 이하로 만들기 위해 세워야 하는 휴게소 갯수가 m개보다 많을 때
		if (cnt > m)
		{
			pLeft = mid + 1;
		}
		// m개 이하의 휴게소로 최대 거리의 최솟값을 mid 이하로 만들 수 있을 때
		else
		{
			ans = min(ans, mid);
			pRight = mid - 1;
		}
	}
	cout << ans;
	return 0;
}