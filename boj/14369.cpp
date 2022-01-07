#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<string> numStr(10);
	numStr[0] = "ZERO";
	numStr[1] = "ONE";
	numStr[2] = "TWO";
	numStr[3] = "THREE";
	numStr[4] = "FOUR";
	numStr[5] = "FIVE";
	numStr[6] = "SIX";
	numStr[7] = "SEVEN";
	numStr[8] = "EIGHT";
	numStr[9] = "NINE";

	int t; cin >> t;
	for (int i = 1; i <= t; i++)
	{
		string s;
		vector<int> chr(26);
		vector<int> numCnt(10);
		cin >> s;
		for (char elem : s)
		{
			chr[elem - 'A']++;
		}

		numCnt[0] = chr['Z' - 'A'];
		for (char elem : numStr[0])
		{
			chr[elem - 'A'] -= numCnt[0];
		}

		numCnt[2] = chr['W' - 'A'];
		for (char elem : numStr[2])
		{
			chr[elem - 'A'] -= numCnt[2];
		}

		numCnt[4] = chr['U' - 'A'];
		for (char elem : numStr[4])
		{
			chr[elem - 'A'] -= numCnt[4];
		}

		numCnt[6] = chr['X' - 'A'];
		for (char elem : numStr[6])
		{
			chr[elem - 'A'] -= numCnt[6];
		}

		numCnt[5] = chr['F' - 'A'];
		for (char elem : numStr[5])
		{
			chr[elem - 'A'] -= numCnt[5];
		}

		numCnt[7] = chr['V' - 'A'];
		for (char elem : numStr[7])
		{
			chr[elem - 'A'] -= numCnt[7];
		}

		numCnt[8] = chr['G' - 'A'];
		for (char elem : numStr[8])
		{
			chr[elem - 'A'] -= numCnt[8];
		}

		numCnt[3] = chr['T' - 'A'];
		for (char elem : numStr[3])
		{
			chr[elem - 'A'] -= numCnt[3];
		}

		numCnt[1] = chr['O' - 'A'];
		for (char elem : numStr[1])
		{
			chr[elem - 'A'] -= numCnt[1];
		}

		numCnt[9] = chr['I' - 'A'];

		cout << "Case #" << i << ": ";
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k < numCnt[j]; k++)
			{
				cout << j;
			}
		}
		cout << '\n';
	}
	return 0;
}