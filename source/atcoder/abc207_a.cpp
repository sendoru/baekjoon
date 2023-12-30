#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	vector<int> cards(3);
	for (int i = 0; i < 3; i++)
	{
		cin >> cards[i];
	}
	sort(cards.begin(), cards.end());
	cout << cards[1] + cards[2] << '\n';
	return 0;
}