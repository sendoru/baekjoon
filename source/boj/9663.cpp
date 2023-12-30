#include <iostream>
#include <cmath>

using namespace std;

void check(int current, int& cnt, int& n, int* board)
{
	bool flag;
	if (current == n)
	{
		cnt++;
		return;
	}

	for (int i = 0; i < n; i++)
	{
		flag = 1;
		for (int j = 0; j < current; j++)
		{
			if (board[j] == i || abs(current - j) == abs(board[j] - i))
			{
				flag = 0;
				break;
			}
		}
		if (flag)
		{
			board[current] = i;
			check(current + 1, cnt, n, board);
		}
	}

}

int main(void)
{
	int N;
	int board[14];
	int cnt = 0;
	cin >> N;

	if (N == 1)
	{
		cout << 1 << endl;
		return 0;
	}
	if (N == 2 || N == 3)
	{
		cout << 0 << endl;
		return 0;
	}

	check(0, cnt, N, board);
	cout << cnt << endl;
	return 0;
}