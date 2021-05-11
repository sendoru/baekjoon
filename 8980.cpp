#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, c, m, curBox = 0, totalBox = 0;
	cin >> n >> c;
	cin >> m;
	// table[출발지] = {목적지, 박스 개수}
	vector<map<int, int> > table(n + 1);
	vector<int> curBoxes(n + 1);
	for (int i = 0; i < m; i++)
	{
		int start, end, boxCnt;
		cin >> start >> end >> boxCnt;
		table[start].insert({ end, boxCnt });
	}

	for (int i = 1; i < n + 1 ; i++)
	{
		curBox -= curBoxes[i];
		curBoxes[i] = 0;
		for (auto iter = table[i].begin(); iter != table[i].end(); iter++)
		{
			int destination = (*iter).first;
			int boxToDestination = (*iter).second;
			if (boxToDestination <= c - curBox)
			{
				curBox += boxToDestination;
				totalBox += boxToDestination;
				curBoxes[destination] += boxToDestination;
			}
			else
			{
				curBox += c - curBox;
				totalBox += c - curBox;
				curBoxes[destination] += c - curBox;
				int over = boxToDestination - (c - curBox);
				for (int j = n; j > destination; j--)
				{
					if (curBoxes[j] > over)
					{
						curBoxes[j] -= over;
						curBoxes[destination] += over;
						break;
					}
					else
					{
						over -= curBoxes[j];
						curBoxes[destination] += curBoxes[j];
						curBoxes[j] = 0;
					}
				}
			}
		}
	}

	cout << totalBox << '\n';
	return 0;
}