#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;


int main(void)
{
	string n;
	cin >> n;
	vector<int> per(n.length());
	ll ans = 0;
	for (int i = 0; i < per.size(); i++) per[i] = i + 1;
	while (true)
	{
		for (int i = 1; i < per.size(); i++)
		{
			string s1, s2;
			for (int j = 0; j < i; j++)
			{
				s1.push_back(n[per[j] - 1]);
			}
			for (int j = i; j < per.size(); j++)
			{
				s2.push_back(n[per[j] - 1]);
			}
			ll num1 = stoll(s1), num2 = stoll(s2);
			ans = max(ans, num1 * num2);
		}
		bool notFinished = next_permutation(per.begin(), per.end());
		if (!notFinished) break;
	}

	cout << ans;
	return 0;
}