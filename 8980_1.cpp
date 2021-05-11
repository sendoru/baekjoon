#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Box
{	
public:
	int start;
	int end;
	int amount;

	Box()
	{
		start = 0;
		end = 0;
		amount = 0;
	}

	Box(int start_, int end_, int amount_)
	{
		start = start_;
		end = end_;
		amount = amount_;
	}

	bool operator<(Box other)
	{
		if (end == other.end) return start < other.start;
		return end < other.end;
	}

	bool operator>(Box other)
	{
		if (end == other.end) return start > other.start;
		return end > other.end;
	}
};



int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, c, m, curBox = 0, totalBox = 0;
	cin >> n >> c;
	cin >> m;
	vector<Box> boxes;
	vector<int> curBoxes(n + 1);
	for (int i = 0; i < m; i++)
	{
		int start, end, boxCnt;
		cin >> start >> end >> boxCnt;
		boxes.push_back(Box(start, end, boxCnt));
	}

	sort(boxes.begin(), boxes.end());

	for (Box elem : boxes)
	{
		int boxesAtStart = curBoxes[elem.start];
		curBoxes[elem.start] = 0;
		curBox -= boxesAtStart;

		if (elem.amount <= c - curBox)
		{
			curBoxes[elem.end] += elem.amount;
			curBox += elem.amount;
			totalBox += elem.amount;
		}
		else if (c - curBox > 0)
		{
			int temp = c - curBox;
			curBoxes[elem.end] += temp;
			curBox = c;
			totalBox += temp;
		}
	}

	cout << totalBox << '\n';
	return 0;
}