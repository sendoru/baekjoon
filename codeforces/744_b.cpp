#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		long long n;
		cin >> n;
		if (n % 3 == 2)
		{
			cout << "TAK" << '\n';
		}
		else if (n % 3 == 0)
		{
			cout << (n % 9 == 0 ? "TAK" : "NIE") << '\n';
		}
		else // if (n % 3 == 1)
		{
			cout << "NIE" << '\n';
		}
	}
	return 0;
}