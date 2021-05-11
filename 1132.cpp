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

	int n;
	ll ans = 0;
	cin >> n;
	vector<pair<ll, bool> > alphabets(10);
	vector<string> nums(n);

	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
		alphabets[nums[i][0] - 'A'].second = true;
		for (int j = 0; j < nums[i].length(); j++)
		{
			alphabets[nums[i][j] - 'A'].first += (ll)pow(10, nums[i].length() - j - 1);
		}
	}

	sort(alphabets.begin(), alphabets.end());

	int index = 0;
	while (alphabets[index].second)
	{
		index++;
	}
	ll temp = alphabets[index].first;
	for (int i = index; i >= 1; i--)
	{
		alphabets[i].first = alphabets[i - 1].first;
	}
	alphabets[0].first = temp;
	alphabets[0].second = false;

	for (int i = 0; i < 10; i++)
	{
		ans += alphabets[i].first * i;
	}

	cout << ans << '\n';
	return 0;
}