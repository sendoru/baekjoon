#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

void pickPer(int n, vector<vector<int>>& allPermutation, vector<int>& picked, int toPick)
{
	// 더 고를 게 없으면 고른거 전부 뱉어내기
	if (toPick == 0)
	{
		allPermutation.push_back(picked);
		return;
	}

	for (int next = 0; next < n; next++)
	{
		if (find(picked.begin(), picked.end(), next) == picked.end())
		{
			picked.push_back(next);
			pickPer(n, allPermutation, picked, toPick - 1);
			picked.pop_back();
		}
	}
}

void pick6(int n, vector<vector<int>>& all, vector<int>& picked, int toPick)
{
	// 더 고를 게 없으면 고른거 전부 뱉어내기
	if (toPick == 0)
	{
		all.push_back(picked);
		return;
	}

	int smallest = 0;

	for (int next = smallest; next < n; next++)
	{
		picked.push_back(next);
		pick6(n, all, picked, toPick - 1);
		picked.pop_back();
	}
}

int solution(vector<vector<int>> dice)
{
	int n = dice.size();
	set<int> s;
	for (int i = 1; i <= dice.size(); i++)
	{
		vector<vector<int>> allP;
		vector<int> picked;
		pickPer(n, allP, picked, i);
		for (auto per : allP)
		{
			vector<vector<int>> all;
			vector<int> temp;
			pick6(6, all, temp, per.size());
			for (auto seq : all)
			{
				int toPut = 0;
				for (int j = 0; j < i; j++)
				{
					if (j == 0 && dice[per[j]][seq[j]] == 0)
					{
						break;
					}
					toPut *= 10;
					toPut += dice[per[j]][seq[j]];
				}
				s.insert(toPut);
			}
		}
	}
	int ans = 1;
	while (s.find(ans) != s.end())
	{
		ans++;
	}
	return ans;
}

int main(void)
{
	int n;
	cin >> n;
	vector<vector<int>> dice(n, vector<int>(6));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cin >> dice[i][j];
		}
	}
	cout << solution(dice);
}