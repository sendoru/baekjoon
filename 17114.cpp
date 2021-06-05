#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef vector<int> v1;
typedef vector<v1> v2;
typedef vector<v2> v3;
typedef vector<v3> v4;
typedef vector<v4> v5;
typedef vector<v5> v6;
typedef vector<v6> v7;
typedef vector<v7> v8;
typedef vector<v8> v9;
typedef vector<v9> v10;
typedef vector<v10> v11;

queue<vector<int> > q;

void bfs(vector<int> size, vector<int>& tomatoes)
{
	vector<vector<int> > directions(22, vector<int>(11));
	for (int i = 0; i < 11; i++)
	{
		directions[2 * i][i] = -1;
		directions[2 * i + 1][i] = 1;
	}

	while (!q.empty())
	{
		vector<int> cur = q.front();
		q.pop();

		for (int i = 0; i < 22; i++)
		{
			bool flag = false;
			vector<int> next = cur;
			for (int j = 0; j < 11; j++)
			{
				next[j] += directions[i][j];
				// 배열의 인덱스를 벗어날 때 예외처리
				if (next[j] < 0 || next[j] >= size[j])
				{
					flag = true;
					break;
				}
			}

			if (flag)
			{
				continue;
			}

			// 안익은 토마토 익게 하기
			if (tomatoes[next[0] +
				size[0] * next[1] +
				size[0] * size[1] * next[2] +
				size[0] * size[1] * size[2] * next[3] +
				size[0] * size[1] * size[2] * size[3] * next[4] +
				size[0] * size[1] * size[2] * size[3] * size[4] * next[5] +
				size[0] * size[1] * size[2] * size[3] * size[4] * size[5] * next[6] +
				size[0] * size[1] * size[2] * size[3] * size[4] * size[5] * size[6] * next[7] +
				size[0] * size[1] * size[2] * size[3] * size[4] * size[5] * size[6] * size[7] * next[8] +
				size[0] * size[1] * size[2] * size[3] * size[4] * size[5] * size[6] * size[7] * size[8] * next[9] +
				size[0] * size[1] * size[2] * size[3] * size[4] * size[5] * size[6] * size[7] * size[8] * size[9] * next[10]] == 0)
			{
				tomatoes[next[0] +
					size[0] * next[1] +
					size[0] * size[1] * next[2] +
					size[0] * size[1] * size[2] * next[3] +
					size[0] * size[1] * size[2] * size[3] * next[4] +
					size[0] * size[1] * size[2] * size[3] * size[4] * next[5] +
					size[0] * size[1] * size[2] * size[3] * size[4] * size[5] * next[6] +
					size[0] * size[1] * size[2] * size[3] * size[4] * size[5] * size[6] * next[7] +
					size[0] * size[1] * size[2] * size[3] * size[4] * size[5] * size[6] * size[7] * next[8] +
					size[0] * size[1] * size[2] * size[3] * size[4] * size[5] * size[6] * size[7] * size[8] * next[9] +
					size[0] * size[1] * size[2] * size[3] * size[4] * size[5] * size[6] * size[7] * size[8] * size[9] * next[10]]
					= tomatoes[cur[0] +
					size[0] * cur[1] +
					size[0] * size[1] * cur[2] +
					size[0] * size[1] * size[2] * cur[3] +
					size[0] * size[1] * size[2] * size[3] * cur[4] +
					size[0] * size[1] * size[2] * size[3] * size[4] * cur[5] +
					size[0] * size[1] * size[2] * size[3] * size[4] * size[5] * cur[6] +
					size[0] * size[1] * size[2] * size[3] * size[4] * size[5] * size[6] * cur[7] +
					size[0] * size[1] * size[2] * size[3] * size[4] * size[5] * size[6] * size[7] * cur[8] +
					size[0] * size[1] * size[2] * size[3] * size[4] * size[5] * size[6] * size[7] * size[8] * cur[9] +
					size[0] * size[1] * size[2] * size[3] * size[4] * size[5] * size[6] * size[7] * size[8] * size[9] * cur[10]] + 1;
				q.push(next);
			}
		}
	}
}

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<int> size(11);
	for (int i = 0; i < 11; i++)
	{
		cin >> size[i];
	}

	vector<int> tomatoes(size[0] * size[1] * size[2] * size[3] * size[4] * size[5] * size[6] * size[7] * size[8] * size[9] * size[10]);

	for (int i10 = 0; i10 < size[10]; i10++)
	{
		for (int i9 = 0; i9 < size[9]; i9++)
		{
			for (int i8 = 0; i8 < size[8]; i8++)
			{
				for (int i7 = 0; i7 < size[7]; i7++)
				{
					for (int i6 = 0; i6 < size[6]; i6++)
					{
						for (int i5 = 0; i5 < size[5]; i5++)
						{
							for (int i4 = 0; i4 < size[4]; i4++)
							{
								for (int i3 = 0; i3 < size[3]; i3++)
								{
									for (int i2 = 0; i2 < size[2]; i2++)
									{
										for (int i1 = 0; i1 < size[1]; i1++)
										{
											for (int i0 = 0; i0 < size[0]; i0++)
											{
												cin >> tomatoes[i0 +
													size[0] * i1 +
													size[0] * size[1] * i2 +
													size[0] * size[1] * size[2] * i3 +
													size[0] * size[1] * size[2] * size[3] * i4 +
													size[0] * size[1] * size[2] * size[3] * size[4] * i5 + 
													size[0] * size[1] * size[2] * size[3] * size[4] * size[5] * i6 + 
													size[0] * size[1] * size[2] * size[3] * size[4] * size[5] * size[6] * i7 + 
													size[0] * size[1] * size[2] * size[3] * size[4] * size[5] * size[6] * size[7] * i8 + 
													size[0] * size[1] * size[2] * size[3] * size[4] * size[5] * size[6] * size[7] * size[8] * i9 + 
													size[0] * size[1] * size[2] * size[3] * size[4] * size[5] * size[6] * size[7] * size[8] * size[9] * i10];
												if (tomatoes[i0 +
													size[0] * i1 +
													size[0] * size[1] * i2 +
													size[0] * size[1] * size[2] * i3 +
													size[0] * size[1] * size[2] * size[3] * i4 +
													size[0] * size[1] * size[2] * size[3] * size[4] * i5 +
													size[0] * size[1] * size[2] * size[3] * size[4] * size[5] * i6 +
													size[0] * size[1] * size[2] * size[3] * size[4] * size[5] * size[6] * i7 +
													size[0] * size[1] * size[2] * size[3] * size[4] * size[5] * size[6] * size[7] * i8 +
													size[0] * size[1] * size[2] * size[3] * size[4] * size[5] * size[6] * size[7] * size[8] * i9 +
													size[0] * size[1] * size[2] * size[3] * size[4] * size[5] * size[6] * size[7] * size[8] * size[9] * i10] == 1)
												{
													q.push(vector<int>{i0, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10});
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	bfs(size, tomatoes);

	int result = 0;

	for (int i10 = 0; i10 < size[10]; i10++)
	{
		for (int i9 = 0; i9 < size[9]; i9++)
		{
			for (int i8 = 0; i8 < size[8]; i8++)
			{
				for (int i7 = 0; i7 < size[7]; i7++)
				{
					for (int i6 = 0; i6 < size[6]; i6++)
					{
						for (int i5 = 0; i5 < size[5]; i5++)
						{
							for (int i4 = 0; i4 < size[4]; i4++)
							{
								for (int i3 = 0; i3 < size[3]; i3++)
								{
									for (int i2 = 0; i2 < size[2]; i2++)
									{
										for (int i1 = 0; i1 < size[1]; i1++)
										{
											for (int i0 = 0; i0 < size[0]; i0++)
											{
												if (tomatoes[i0 +
													size[0] * i1 +
													size[0] * size[1] * i2 +
													size[0] * size[1] * size[2] * i3 +
													size[0] * size[1] * size[2] * size[3] * i4 +
													size[0] * size[1] * size[2] * size[3] * size[4] * i5 +
													size[0] * size[1] * size[2] * size[3] * size[4] * size[5] * i6 +
													size[0] * size[1] * size[2] * size[3] * size[4] * size[5] * size[6] * i7 +
													size[0] * size[1] * size[2] * size[3] * size[4] * size[5] * size[6] * size[7] * i8 +
													size[0] * size[1] * size[2] * size[3] * size[4] * size[5] * size[6] * size[7] * size[8] * i9 +
													size[0] * size[1] * size[2] * size[3] * size[4] * size[5] * size[6] * size[7] * size[8] * size[9] * i10] == 0)
												{
													cout << -1 << '\n';
													return 0;
												}
												if (tomatoes[i0 +
													size[0] * i1 +
													size[0] * size[1] * i2 +
													size[0] * size[1] * size[2] * i3 +
													size[0] * size[1] * size[2] * size[3] * i4 +
													size[0] * size[1] * size[2] * size[3] * size[4] * i5 +
													size[0] * size[1] * size[2] * size[3] * size[4] * size[5] * i6 +
													size[0] * size[1] * size[2] * size[3] * size[4] * size[5] * size[6] * i7 +
													size[0] * size[1] * size[2] * size[3] * size[4] * size[5] * size[6] * size[7] * i8 +
													size[0] * size[1] * size[2] * size[3] * size[4] * size[5] * size[6] * size[7] * size[8] * i9 +
													size[0] * size[1] * size[2] * size[3] * size[4] * size[5] * size[6] * size[7] * size[8] * size[9] * i10] > result)
												{
													result = tomatoes[i0 +
														size[0] * i1 +
														size[0] * size[1] * i2 +
														size[0] * size[1] * size[2] * i3 +
														size[0] * size[1] * size[2] * size[3] * i4 +
														size[0] * size[1] * size[2] * size[3] * size[4] * i5 +
														size[0] * size[1] * size[2] * size[3] * size[4] * size[5] * i6 +
														size[0] * size[1] * size[2] * size[3] * size[4] * size[5] * size[6] * i7 +
														size[0] * size[1] * size[2] * size[3] * size[4] * size[5] * size[6] * size[7] * i8 +
														size[0] * size[1] * size[2] * size[3] * size[4] * size[5] * size[6] * size[7] * size[8] * i9 +
														size[0] * size[1] * size[2] * size[3] * size[4] * size[5] * size[6] * size[7] * size[8] * size[9] * i10];
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	cout << result - 1 << '\n';
	return 0;
}