#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;
typedef long long ll;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int g, p;
	cin >> g >> p;
	set<int, greater<int>> s;
	vector<int> planes;
	for (int i = 1; i <= g; i++)
	{
		s.insert(i);
	}
	for (int i = 0; i < p; i++)
	{
		int temp;
		cin >> temp;
		planes.push_back(temp);
	}
	int ans = 0;
	for (int elem : planes)
	{	
		auto iter = s.lower_bound(elem);
		if (iter == s.end() || *iter > elem)
		{
			break;
		}
		s.erase(iter);
		ans++;
	}

	cout << ans << '\n';
	return 0;
}
