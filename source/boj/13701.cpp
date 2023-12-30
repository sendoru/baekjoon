#include <iostream>

using namespace std;

unsigned char bits[1 << (25 - 3)];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int temp;
	while (true)
	{
		cin >> temp;
		if (cin.eof())
		{
			return 0;
		}
		if (!(bits[temp >> 3] >> (temp % 8) & 1))
		{
			cout << temp << ' ';
			bits[temp >> 3] += 1 << (temp % 8);
		}
	}

	return 0;
}