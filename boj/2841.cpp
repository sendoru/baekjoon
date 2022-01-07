#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, P, cnt = 0;
	vector<vector<int>> melody = { {}, {}, {}, {}, {}, {} };
	vector<int> stack;
	int line, fret;

	cin >> N >> P;
	

	for (int i = 0; i < N; i++)
	{
		cin >> line >> fret;
		melody[line - 1].push_back(fret);
	}

	for (int i = 0; i < melody.size(); i++)
	{
		stack.clear();
		for (int j = 0; j < melody[i].size(); j++)
		{
			if (stack.size() == 0)
			{
				cnt++;
				stack.push_back(melody[i][j]);
			}
			else if (*max(stack.begin(), stack.end()) < melody[i][j])
			{
				cnt++;
				stack.push_back(melody[i][j]);
			}
			else
			{
				cnt += 1 + stack.size();
				stack.clear();
				stack.push_back(melody[i][j]);
			}
		}
	}

	cout << cnt << '\n';
}