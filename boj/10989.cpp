#include <iostream>

int main(void)
{
	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int N, temp;
	int cnt[10001] = { 0, };

	std::cin >> N;

	for (int i = 0; i < N; i++)
	{
		std::cin >> temp;
		cnt[temp]++;
	}

	for (int i = 1; i <= 10000; i++)
	{
		for (int j = 1; j <= cnt[i]; j++)
			std::cout << i << '\n';
	}


	
	return 0;
}