#include <iostream>

using namespace std;

int stair[301] = { 0, };
int dp[301][3] = { 0, };

int main() {

	cin.tie(NULL);

	int n;
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> stair[i];
	}

	dp[n][1] = stair[n];
	dp[n][2] = stair[n];
	dp[n][0] = -1 << 31;


	for (int i = n - 1; i >= 1; i--) {
		for (int j = 0; j <= 2; j++) {
			if (j == 2) {
				dp[i][j] = dp[i + 1][1] + stair[i];
			}
			if (j == 1) {
				dp[i][j] = dp[i + 1][0] + stair[i];
			}
			if (j == 0) {
				int max = 0;
				if (max < dp[i + 1][1]) {
					max = dp[i + 1][1];
				}
				if (max < dp[i + 1][2]) {
					max = dp[i + 1][2];
				}
				dp[i][j] = max;
			}
		}
	}


	int ans = 0;
	if (ans < dp[1][1]) {
		ans = dp[1][1];
	}
	if (ans < dp[1][0]) {
		ans = dp[1][0];
	}
	if (ans < dp[1][2]) {
		ans = dp[1][2];
	}
	if (ans < dp[2][1]) {
		ans = dp[2][1];
	}
	if (ans < dp[2][2]) {
		ans = dp[2][2];
	}
	if (ans < dp[2][0]) {
		ans = dp[2][0];
	}

	cout << ans;



	return 0;
}