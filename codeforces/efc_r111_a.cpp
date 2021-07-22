#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<int> squares;
	int len = 0;
	while (len * len <= 5000)
	{
		squares.push_back(len * len);
		len++;
	}
	int t;
	cin >> t;
	while (t--)
	{
		int s;
		cin >> s;
		// 어떤 아름다운 수열 a의 합이 a_s라면 합이 a_s - 1인 아름다운 수열이 존재 (a_s > 1일때)
		// 길이가 l인 아름다운 수열의 최댓값은 1 + 3 + 5 + ... + (2l - 1) = l^2
		int ans = lower_bound(squares.begin(), squares.end(), s) - squares.begin();
		cout << ans << '\n';
	}
	return 0;
}