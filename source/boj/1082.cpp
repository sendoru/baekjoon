#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string removeZero(string str)
{
	if (str.length() == 0)
	{
		return str;
	}

	while (str.length() >= 1 && str[0] == '0')
	{
		int temp = str.length();
		str = str.substr(1, temp - 1);
	}
	return str;
}

bool isGreaterThan(string str1, string str2)
{
	str1 = removeZero(str1);
	str2 = removeZero(str2);

	if (str1.length() > str2.length())
	{
		return true;
	}

	if (str1.length() < str2.length())
	{
		return false;
	}

	for (int i = 0; i < str1.length(); i++)
	{
		if (str1[i] > str2[i])
		{
			return true;
		}
		if (str1[i] < str2[i])
		{
			return false;
		}
	}
	return false;
}

void findMaximun(int countofNums, int money, vector<int> costofNums, vector<string>& maximum)
{
	for (int i = 0; i <= money; i++)
	{
		if (maximum[i] == "")
		{
			continue;
		}
		for (int j = 0; j < countofNums; j++)
		{
			if (i + costofNums[j] > money)
			{
				continue;
			}
			if (maximum[i + costofNums[j]] == "")
			{
				maximum[i + costofNums[j]] = maximum[i] + to_string(j);
				continue;
			}
			if (isGreaterThan(maximum[i + costofNums[j]], maximum[i] + to_string(j)))
			{
				continue;
			}
			maximum[i + costofNums[j]] = maximum[i] + to_string(j);
		}
	}
}

int main(void)
{
	int countofNums, money;
	cin >> countofNums;
	vector<int> costofNums(countofNums);
	for (int i = 0; i < countofNums; i++)
	{
		cin >> costofNums[i];
	}
	cin >> money;

	// maximum[i] := i원 가지고 만들 수 있는 가장 큰 수
	vector<string> maximum(money + 1);

	for (int i = 0; i < countofNums; i++)
	{
		if (costofNums[i] <= money)
			maximum[costofNums[i]] = to_string(i);
	}

	findMaximun(countofNums, money, costofNums, maximum);

	string ans = "";

	for (int i = 0; i <= money; i++)
	{
		if (isGreaterThan(maximum[i], ans))
		{
			ans = maximum[i];
		}
	}
	ans = removeZero(ans);
	if (ans == "")
	{
		cout << 0 << endl;
	}
	else
	{
		cout << ans << endl;
	}
	return 0;
}