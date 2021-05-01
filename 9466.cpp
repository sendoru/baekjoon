#include <iostream>
#include <vector>
#define MAX 100001

using namespace std;

int countofCases, countofPeople, countofBelong;
int want[MAX];
bool visited[MAX] = { 0, };
bool done[MAX] = { 0, };

void dfs(int current)
{
	visited[current] = true;
	int next = want[current];

	if (!visited[next])
	{
		dfs(next);
	}

	else if (!done[next])
	{
		while (next != current)
		{
			countofBelong++;
			next = want[next];
		}
		countofBelong++;
	}

	done[current] = true;
}

int main(void)
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> countofCases;
	while (countofCases--)
	{
		for (int i = 0; i < MAX; i++)
		{
			visited[i] = 0;
			done[i] = 0;
		}
		countofBelong = 0;

		cin >> countofPeople;

		for (int i = 1; i <= countofPeople; i++)
		{
			cin >> want[i];
		}

		for (int i = 1; i <= countofPeople; i++)
		{
			if (!visited[i])
			{
				dfs(i);
			}
		}
		cout << countofPeople - countofBelong << '\n';
	}
	return 0;
}