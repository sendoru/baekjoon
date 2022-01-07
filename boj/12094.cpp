#include <iostream>
#include <cstring>
#include <stack>
#include <cmath>

using namespace std;
int n;


char** moveUp(char** board, char& record, char depth)
{
	char** newBoard = new char* [n];
	for (int i = 0; i < n; i++)
	{
		newBoard[i] = new char[n];
		memset(newBoard[i], 0, n);
	}
	char curRecord = 0;
	bool flag = false;
	char* v1 = new char[n];
	memset(v1, 0, n);
	for (int c = 0; c < n; c++)
	{
		char v1Size = 0, countofZero = 0;
		for (int i = 0; i < n; i++)
		{
			if (board[i][c] != 0)
			{
				v1[v1Size] = board[i][c];
				v1Size++;
				if (v1Size > 1 && v1[v1Size - 1] == v1[v1Size - 2])
				{
					v1[v1Size - 2] += 1;
					v1[v1Size - 1] = 0;
					curRecord = max(curRecord, v1[v1Size - 2]);
				}
				else
				{
					curRecord = max(curRecord, v1[v1Size - 1]);
				}
			}
		}

		for (int i = 0; i < v1Size; i++)
		{
			if (v1[i] != 0)
			{
				newBoard[i - countofZero][c] = v1[i];
				if (newBoard[i - countofZero][c] != board[i - countofZero][c])
				{
					flag = true;
				}
			}
			else
				countofZero++;

		}
		for (int i = v1Size - countofZero; i < n; i++)
		{
			newBoard[i][c] = 0;
			if (newBoard[i][c] != board[i][c])
			{
				flag = true;
			}
		}
	}
	delete[] v1;
	if (curRecord <= (record - (10 - depth)) || !flag)
	{
		newBoard[0][0] = 40;
	}
	record = max(record, curRecord);
	return newBoard;
}

char** moveDown(char** board, char& record, char depth)
{
	char** newBoard = new char* [n];
	for (int i = 0; i < n; i++)
	{
		newBoard[i] = new char[n];
		memset(newBoard[i], 0, n);
	}
	char curRecord = 0;
	bool flag = false;
	char* v1 = new char[n];
	memset(v1, 0, n);
	for (int c = 0; c < n; c++)
	{
		char v1Size = 0, countofZero = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			if (board[i][c] != 0)
			{
				v1[v1Size] = board[i][c];
				v1Size++;
				if (v1Size > 1 && v1[v1Size - 1] == v1[v1Size - 2])
				{
					v1[v1Size - 2] += 1;
					v1[v1Size - 1] = 0;
					curRecord = max(curRecord, v1[v1Size - 2]);
				}
				else
				{
					curRecord = max(curRecord, v1[v1Size - 1]);
				}
			}
		}
		for (int i = 0; i < v1Size; i++)
		{
			if (v1[i] != 0)
			{
				newBoard[n - 1 - i + countofZero][c] = v1[i];
				if (newBoard[n - 1 - i + countofZero][c] != board[n - 1 - i + countofZero][c])
				{
					flag = true;
				}
			}
			else
			{
				countofZero++;
			}
		}
		for (int i = v1Size - countofZero; i < n; i++)
		{
			newBoard[n - 1 - i][c] = 0;
			if (newBoard[n - 1 - i][c] != board[n - 1 - i][c])
			{
				flag = true;
			}
		}
	}
	delete[] v1;
	if (curRecord <= (record - (10 - depth)) || !flag)
	{
		newBoard[0][0] = 40;
	}
	record = max(record, curRecord);
	return newBoard;
}

char** moveLeft(char** board, char& record, char depth)
{
	char** newBoard = new char* [n];
	for (int i = 0; i < n; i++)
	{
		newBoard[i] = new char[n];
		memset(newBoard[i], 0, n);
	}
	char curRecord = 0;
	bool flag = false;
	char* v1 = new char[n];
	memset(v1, 0, n);
	for (int r = 0; r < n; r++)
	{
		char v1Size = 0, countofZero = 0;
		for (int i = 0; i < n; i++)
		{
			if (board[r][i] != 0)
			{
				v1[v1Size] = board[r][i];
				v1Size++;
				if (v1Size > 1 && v1[v1Size - 1] == v1[v1Size - 2])
				{
					v1[v1Size - 2] += 1;
					v1[v1Size - 1] = 0;
					curRecord = max(curRecord, v1[v1Size - 2]);
				}
				else
				{
					curRecord = max(curRecord, v1[v1Size - 1]);
				}
			}
		}
		for (int i = 0; i < v1Size; i++)
		{
			if (v1[i] != 0)
			{
				newBoard[r][i - countofZero] = v1[i];
				if (newBoard[r][i - countofZero] != board[r][i - countofZero])
				{
					flag = true;
				}
			}
			else
			{
				countofZero++;
			}
		}
		for (int i = v1Size - countofZero; i < n; i++)
		{
			newBoard[r][i] = 0;
			if (newBoard[r][i] != board[r][i])
			{
				flag = true;
			}
		}
	}
	delete[] v1;
	if (curRecord <= (record - (10 - depth)) || !flag)
	{
		newBoard[0][0] = 40;
	}
	record = max(record, curRecord);
	return newBoard;
}

char** moveRight(char** board, char& record, char depth)
{
	char** newBoard = new char* [n];
	for (int i = 0; i < n; i++)
	{
		newBoard[i] = new char[n];
		memset(newBoard[i], 0, n);
	}
	char curRecord = 0;
	bool flag = false;
	char* v1 = new char[n];
	memset(v1, 0, n);
	for (int r = 0; r < n; r++)
	{
		char v1Size = 0, countofZero = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			if (board[r][i] != 0)
			{
				v1[v1Size] = board[r][i];
				v1Size++;
				if (v1Size > 1 && v1[v1Size - 1] == v1[v1Size - 2])
				{
					v1[v1Size - 2] += 1;
					v1[v1Size - 1] = 0;
					curRecord = max(curRecord, v1[v1Size - 2]);
				}
				else
				{
					curRecord = max(curRecord, v1[v1Size - 1]);
				}
			}
		}
		for (int i = 0; i < v1Size; i++)
		{
			if (v1[i] != 0)
			{
				newBoard[r][n - 1 - i + countofZero] = v1[i];
				if (newBoard[r][n - 1 - i] != board[r][n - 1 - i + countofZero])
				{
					flag = true;
				}
			}
			else
			{
				countofZero++;
			}
		}
		for (int i = v1Size - countofZero; i < n; i++)
		{
			newBoard[r][n - 1 - i] = 0;
			if (newBoard[r][n - 1 - i] != board[r][n - 1 - i])
			{
				flag = true;
			}
		}
	}
	delete[] v1;
	if (curRecord <= (record - (10 - depth)) || !flag)
	{
		newBoard[0][0] = 40;
	}
	record = max(record, curRecord);
	return newBoard;
}

void dfs(char** board, char& record, char depth)
{
	stack<char**> boards;
	stack<char> depths;
	boards.push(board);
	depths.push(0);

	while (!boards.empty())
	{
		char** curBoard = boards.top();
		boards.pop();
		char curDepth = depths.top();
		depths.pop();
		if (curDepth >= 10)
		{
			continue;
		}
		char** up = moveUp(curBoard, record, curDepth + 1);
		char** down = moveDown(curBoard, record, curDepth + 1);
		char** left = moveLeft(curBoard, record, curDepth + 1);
		char** right = moveRight(curBoard, record, curDepth + 1);
		if (up[0][0] != 40)
		{
			boards.push(up);
			depths.push(curDepth + 1);
		}
		if (down[0][0] != 40)
		{
			boards.push(down);
			depths.push(curDepth + 1);
		}
		if (left[0][0] != 40)
		{
			boards.push(left);
			depths.push(curDepth + 1);
		}
		if (right[0][0] != 40)
		{
			boards.push(right);
			depths.push(curDepth + 1);
		}
		for (int i = 0; i < n; i++)
		{
			delete[] curBoard[i];
		}
		delete[] curBoard;
	}

	return;
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	char** board = new char*[n];
	int temp;

	for (int i = 0; i < n; i++)
	{
		board[i] = new char[n];
		for (int j = 0; j < n; j++)
		{
			cin >> temp;
			if (temp == 0)
				board[i][j] = 0;
			else
				board[i][j] = (char)log2(temp);
		}
	}

	char record = 0;
	dfs(board, record, 0);
	cout << (1 << record) << '\n';


	return 0;
}