#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

int main(void)
{
	int r, c;
	cin >> r >> c;
	r--; c--;
	int a[2][2];
	cin >> a[0][0] >> a[0][1] >> a[1][0] >> a[1][1];
	cout << a[r][c];
	return 0;
}