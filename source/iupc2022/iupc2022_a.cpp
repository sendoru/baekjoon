#include<iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;

int main(void)
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	char lastChar = s.back();
	vector<char> aa = { 'q','w','e','r','t','a','s','d','f','g','z','x','c','v'};
	bool ans = find(aa.begin(), aa.end(), lastChar) != aa.end();
	cout << (ans ? 1 : 0);
	return 0;

	
}