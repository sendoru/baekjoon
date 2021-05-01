#include <iostream>

int tiling(int n)
{
	int ref[1001];
	ref[0] = 1;
	ref[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		ref[i] = (ref[i - 1] + ref[i - 2]) % 10007;
	}
	return ref[n];
}

int main(void)
{
	int N;
	std::cin >> N;
	std::cout << tiling(N) << std::endl;

	return 0;
}