#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <queue>
#include <map>
#include <set>
using namespace std;
typedef long long ll;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin >> n;
	// 그냥 1이 n개 연속으로 있는 수를 생각하자
	// 그럼 x를 2가 n개 연속으로 있는 수로 설정하면 아무튼 된다.
	cout << 2 * n << '\n';
	// 1이 n개 연속 -> 4가 floor(n/4)개 연속, 맨 앞의 수는 n mod 4
	if (n % 4 != 0)
		cout << n % 4;
	for (int i = 0; i < n / 4; i++)
		cout << 4;
	cout << '\n';
	return 0;
}