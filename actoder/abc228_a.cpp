#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void)
{
	int s, t, x;
	cin >> s >> t >> x;
	vector<bool> isOn(24);
	if (s < t)
	{
		for (int i = s; i < t; i++)
		{
			isOn[i] = true;
		}
	}
	else
	{
		for (int i = s; i < 24; i++)
		{
			isOn[i] = true;
		}
		for (int i = 0; i < t; i++)
		{
			isOn[i] = true;
		}
	}
	cout << (isOn[x] ? "YES " : "NO");
	return 0;
}