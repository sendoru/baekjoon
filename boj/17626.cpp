#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
constexpr int MAX = 50002;

// time complexity : O(n^1.5)
int main(void)
{
	int n, ans = 4;
	cin >> n;
	vector<int> squares;

	for (int i = 1; i * i <= n; i++)
	{
		squares.push_back(i * i);
	}
	if (squares.back() == n)
	{
		ans = 1;
	}
	else
	{
		for (int i = 0; i < squares.size(); i++)
		{
			for (int j = i; j < squares.size(); j++)
			{
				if (squares[i] + squares[j] == n)
				{
					ans = 2;
					break;
				}
			}
			if (ans == 2)
				break;
		}
	}
	if (ans == 4)
	{
		for (int i = 0; i < squares.size(); i++)
		{
			for (int j = i; j < squares.size(); j++)
			{
				for (int k = j; k < squares.size(); k++)
				{
					if (squares[i] + squares[j] + squares[k] == n)
					{
						ans = 3;
						break;
					}
				}
				if (ans == 3)
					break;
			}
			if (ans == 3)
				break;
		}
	}

	cout << ans;
	return 0;

 }

