#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> solve(map<int, int> seqMap)
{
	vector<int> ret;
	if (seqMap.size() == 1)
	{
		while ((*seqMap.begin()).second != 0)
		{
			ret.push_back((*seqMap.begin()).first);
			(*seqMap.begin()).second--;
		}
	}
	else
	{
		while (seqMap.size() > 2)
		{
			while ((*seqMap.begin()).second != 0)
			{
				ret.push_back((*seqMap.begin()).first);
				(*seqMap.begin()).second--;
			}
			seqMap.erase(seqMap.begin());
			if (ret.back() + 1 == (*seqMap.begin()).first)
			{
				ret.push_back((*++seqMap.begin()).first);
				(*++seqMap.begin()).second--;
				if ((*++seqMap.begin()).second == 0)
				{
					seqMap.erase(++seqMap.begin());
				}
			}
		}
		if ((*seqMap.begin()).first + 1 != (*++seqMap.begin()).first)
		{
			while (!seqMap.empty())
			{
				while ((*seqMap.begin()).second != 0)
				{
					ret.push_back((*seqMap.begin()).first);
					(*seqMap.begin()).second--;
				}
				seqMap.erase(seqMap.begin());
			}
		}
		else
		{
			while ((*++seqMap.begin()).second != 0)
			{
				ret.push_back((*++seqMap.begin()).first);
				(*++seqMap.begin()).second--;
			}
			seqMap.erase(++seqMap.begin());
			while ((*seqMap.begin()).second != 0)
			{
				ret.push_back((*seqMap.begin()).first);
				(*seqMap.begin()).second--;
			}
			seqMap.erase(seqMap.begin());
		}
	}

	return ret;
}

int main(void)
{
	int n;
	cin >> n;
	map<int, int> seqMap;
	vector<int> seq;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		seqMap[temp]++;
	}
	vector<int> ans = solve(seqMap);
	for (int elem : ans)
	{
		cout << elem << ' ';
	}
	return 0;
}