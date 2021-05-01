#include <iostream>

int minSquares[50001] = { 0, 1, -1 };

int minSqaure(int n)
{
	if (minSquares[n] != -1) return minSquares[n];
	minSquares[n] = minSquares[n - 1] + 1;
	for (int i = 0; i * i <= minSquares[n]; i++)
	{
		if (minSquares[n] == i * i)
		{
			minSquares[n] == 1;
		}
	}


}

int main(void)
{
	


}