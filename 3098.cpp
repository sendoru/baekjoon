#include <iostream>
#include <vector>

using namespace std;

int countofDays = 0;

void check(vector<vector<bool>>& isFriend, int& countofDays, int countofPeople)
{
	vector<vector<bool>> copyofIsFriend = vector<vector<bool>>(isFriend);

	int countofNewFriends = 0;
	for (int i = 0; i < countofPeople; i++)
	{
		for (int j = 0; j < countofPeople; j++)
		{
			for (int k = 0; k < countofPeople; k++)
			{
				if (i != j && i != k && j != k && copyofIsFriend[i][j] && copyofIsFriend[j][k] && !copyofIsFriend[i][k])
				{
					isFriend[i][k] = true;
					isFriend[k][i] = true;
				}
			}
		}
	}
	countofDays++;
}

int main(void)
{

	vector<vector<bool>> isFriend;
	int countofPeople, countofLines;
	cin >> countofPeople >> countofLines;
	vector<int> countofNewFriends;


	for (int i = 0; i < countofPeople; i++)
	{
		isFriend.push_back({});
		{
			for (int j = 0; j < countofPeople; j++)
				isFriend[i].push_back(false);
		}
	}

	int temp1, temp2;
	for (int i = 0; i < countofLines; i++)
	{
		cin >> temp1 >> temp2;
		isFriend[temp1 - 1][temp2 - 1] = true;
		isFriend[temp2 - 1][temp1 - 1] = true;
	}

	int prevCountofFriend = countofLines; int countofFriend = countofLines;

	bool ifContinue = 0;
	
	for (;;)
	{
		bool ifContinue = 0;

		prevCountofFriend = countofFriend;

		check(isFriend, countofDays, countofPeople);

		countofFriend = 0;
		
		for (int i = 0; i < countofPeople; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (isFriend[i][j])
					countofFriend++;
			}
		}

		countofNewFriends.push_back(countofFriend - prevCountofFriend);

		for (int i = 0; i < countofPeople; i++)
		{
			for (int j = 0; j < countofPeople; j++)
			{
				if (i != j && !isFriend[i][j])
				{
					ifContinue = 1;
					continue;
				}
			}
		}
		if (ifContinue) continue;
		break;
	}

	cout << countofDays << endl;
	for (int i = 0; i < countofNewFriends.size(); i++)
	{
		cout << countofNewFriends[i] << endl;
	}

	return 0;
}