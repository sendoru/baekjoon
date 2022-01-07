#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<unsigned int> addresses(n);
	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;
		int dot1Index = 0, dot2Index = 0, dot3Index = 0;
		for (int j = 0; j < temp.length(); j++)
		{
			if (temp[j] == '.')
			{
				if (dot1Index == 0)
				{
					dot1Index = j;
					addresses[i] += stoul(temp.substr(0, dot1Index)) << 24;
				}
				else if (dot2Index == 0)
				{
					dot2Index = j;
					addresses[i] += stoul(temp.substr(dot1Index + 1, dot2Index)) << 16;
				}
				else if (dot3Index == 0)
				{
					dot3Index = j;
					addresses[i] += stoul(temp.substr(dot2Index + 1, dot3Index)) << 8;
					addresses[i] += stoul(temp.substr(dot3Index + 1, temp.length()));
					break;
				}
			}
		}
	}

	unsigned int networkAddress = 0;
	unsigned int subnetMask = 0;
	for (int i = 31; i >= 0; i--)
	{
		unsigned int base = (addresses[0] >> i) & 1;
		bool flag = false;
		for (int j = 1; j < addresses.size(); j++)
		{
			if (((addresses[j] >> i) & 1) != base)
			{
				flag = true;
				break;
			}
		}
		if (flag)
		{
			break;
		}
		networkAddress += base << i;
		subnetMask += 1ull << i;
	}

	for (int i = 3; i >= 0; i--)
	{
		cout << (networkAddress >> (i * 8) & ((1ull << 8) - 1));
		if (i != 0)
		{
			cout << '.';
		}
		else
		{
			cout << '\n';
		}
	}
	
	for (int i = 3; i >= 0; i--)
	{
		cout << (subnetMask >> (i * 8) & ((1ull << 8) - 1));
		if (i != 0)
		{
			cout << '.';
		}
		else
		{
			cout << '\n';
		}
	}

	return 0;
}