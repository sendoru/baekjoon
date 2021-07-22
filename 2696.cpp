#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		priority_queue<int, vector<int>, less<int>> lower;
		priority_queue<int, vector<int>, greater<int>> upper;
		lower.push(0x80000000);
		upper.push(0x7fffffff);
		int lowerSize = 1;
		int upperSize = 1;
		int n, input;
		cin >> n;
		cout << n / 2 + n % 2 << '\n';
		for (int i = 0; i < n; i++)
		{
			cin >> input;
			if (input < upper.top())
			{
				lower.push(input);
				lowerSize++;
			}
			else
			{
				upper.push(input);
				upperSize++;
			}
			if (upperSize > lowerSize)
			{
				lower.push(upper.top());
				lowerSize++;
				upper.pop();
				upperSize--;
			}
			else if (lowerSize > upperSize + 1)
			{
				upper.push(lower.top());
				upperSize++;
				lower.pop();
				lowerSize--;
			}
			if (i % 2 == 0)
			{
				cout << lower.top() << ' ';
			}
			if ((i + 1) % 20 == 0)
			{
				cout << '\n';
			}
		}
		cout << '\n';
	}
}