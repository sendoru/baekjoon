#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
typedef long long ll;
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto& elem : a)
		cin >> elem;

	sort(a.begin(), a.end());
	int ans = 1;
	for (int i = 1; i < a.size(); i++)
	{
		if (a[i] != a[i - 1])
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}