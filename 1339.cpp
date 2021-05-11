#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, ans = 0;
	cin >> n;
	vector<ll> alphabets(26);
	vector<string> nums(n);

	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
		for (int j = 0; j < nums[i].length(); j++)
		{
			alphabets[nums[i][j] - 'A'] += (ll)pow(10, nums[i].length() - j - 1);
		}
	}

	sort(alphabets.begin(), alphabets.end(), greater<ll>());

	for (int i = 0; i < 10; i++)
	{
		ans += alphabets[i] * (9 - i);
	}

	cout << ans << '\n';
	return 0;
}