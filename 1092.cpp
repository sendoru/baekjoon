#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(void)
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int countofCrane;
	cin >> countofCrane;
	vector<int> limitsofCrane(countofCrane);
	for (int i = 0; i < countofCrane; i++)
	{
		cin >> limitsofCrane[i];
	}

	int countofBox;
	cin >> countofBox;
	priority_queue<int> weightsofBox;
	for (int i = 0; i < countofBox; i++)
	{
		int temp;
		cin >> temp;
		weightsofBox.push(temp);
	}

	sort(limitsofCrane.begin(), limitsofCrane.end(), greater<int>());

	if (weightsofBox.top() > limitsofCrane[0])
	{
		cout << -1 << '\n';
		return 0;
	}

	vector<int> countofUsesofCrane(countofCrane);

	int idealCountofUses;
	if (countofBox % countofCrane == 0)
	{
		idealCountofUses = countofBox / countofCrane;
	}
	else
	{
		idealCountofUses = countofBox / countofCrane + 1;
	}

	for (int craneNo = 0; craneNo < countofCrane; craneNo++)
	{
		while (!weightsofBox.empty() && countofUsesofCrane[craneNo] < idealCountofUses)
		{
			countofUsesofCrane[craneNo]++;
			weightsofBox.pop();
		}
		if (!weightsofBox.empty() && craneNo != countofCrane - 1 && weightsofBox.top() > limitsofCrane[craneNo + 1])
		{
			craneNo = -1; // ??????
			idealCountofUses++;
		}
	}

	cout << idealCountofUses << endl;
	return 0;
}