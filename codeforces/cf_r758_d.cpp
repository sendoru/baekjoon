#include <iostream>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;
constexpr ll MOD = 998'244'353;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<string> dominos(n);
	for (int i = 0; i < n; i++) cin >> dominos[i];


	
	if (n == 1)
	{
		if (dominos[0] == "WW" || dominos[0] == "BB")
		{
			cout << 0;
			return 0;
		}
		else if (dominos[0] == "??")
		{
			cout << 2;
			return 0;
		}
		else
		{
			cout << 1;
			return 0;
		}
	}

	// 경우의 수
	// case 1: 전부 다 BW인 경우 (단 1가지)
	// case 2: 전부 다 WB인 경우 (역시 단 1가지)
	// case 3: WW, BB가 k개씩 있고 나머지는 BW 또는 WB인 경우 (몰??????루)
	else
	{
		// BB, BW, WB, WW
		vector<vector<bool>> possible(n, vector<bool>(4));
		for (int i = 0; i < n; i++)
		{
			if ((dominos[i][0] == 'B' || dominos[i][0] == '?') && (dominos[i][1] == 'B' || dominos[i][1] == '?'))
				possible[i][0] = true;
			if ((dominos[i][0] == 'B' || dominos[i][0] == '?') && (dominos[i][1] == 'W' || dominos[i][1] == '?'))
				possible[i][1] = true;
			if ((dominos[i][0] == 'W' || dominos[i][0] == '?') && (dominos[i][1] == 'B' || dominos[i][1] == '?'))
				possible[i][2] = true;
			if ((dominos[i][0] == 'W' || dominos[i][0] == '?') && (dominos[i][1] == 'W' || dominos[i][1] == '?'))
				possible[i][3] = true;
		}


	}




	return 0;
}