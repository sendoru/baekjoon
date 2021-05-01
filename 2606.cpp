#include <iostream>

using namespace std;

bool map[100][100];
bool isInfected[100];

void infect(int n)
{
	isInfected[n] = true;
	for (int i = 0; i < 100; i++)
	{
		if (map[n][i] && isInfected[i] == false)
		{
			isInfected[i] = true;
			infect(i);
		}
	}
}

int main(void)
{
	int countofComputer, countofLine;
	cin >> countofComputer;
	cin >> countofLine;

	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			map[i][j] = false;

	int tempCom1, tempCom2;
	for (int i = 0; i < countofLine; i++)
	{
		cin >> tempCom1 >> tempCom2;
		map[tempCom1 - 1][tempCom2 - 1] = true;
		map[tempCom2 - 1][tempCom1 - 1] = true;
	}

	infect(0);

	int cnt = 0;

	for (int i = 0; i < countofComputer; i++)
		if (isInfected[i])
			cnt++;

	cout << cnt - 1 << endl;
	return 0;
}