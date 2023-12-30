#include <iostream>
#include <vector>
#include <cmath>
typedef long long ll;
constexpr ll MOD = 1e9 + 7;
using namespace std;

int main(void)
{
	ll n, m, k;
	cin >> n >> m >> k;
	// 아
	// ㅅㅂ 이게뭐야
	// 일단 마지막으로 스탬프를 찍으면 찍은 곳에는 k개의 색상이 연속으로 있을 것이다.
	// 즉, 우리가 구할려는 거는 길이 n인 1~m의 수로 이루어진 수열 중, k개의 수가 연속으로 같은 구간이 있는 수열의 갯수이다.
	// 그 반대, 즉 k개의 수가 연속으로 같은 구간이 없는 수열의 갯수를 구하는 게 아이디어이다.
	// 어지럽네
	// 일단 길이 1부터 길이 k-1까지에 대해서는 당연히 m^i이다.
	// 길이 k일때를 먼저 생각해보자. 
	// 전체 m^k개 중 1111..., 2222..., ...., mmmm....의 m개만 제외하면 된다.
	// 즉, m^k - m이다.
	// k+1 이상일 때를 생각해 보면, 결국 "마지막"의 k개만 확인해 보면 된다.
	// dp[i] = 마지막 1개가 연속 + 마지막 2개가 연속 + ... 마지막 k-1개가 연속
	//         = (m * dp[i-1] - 1 * dp[i-1]) + (m * dp[i-2] - 1 * dp[i-2]) ...
	//		   = (m - 1) * sum j = 1 to k - 1 (dp[i-j])
	// 뭔가 누적합을 써야 될 것 같긴 하다.
	// dp[0]부터 dp[i]까지의 합을 s[i]라 하자.
	// 그러면 위 식은
	// s[i] - s[i-1] = (m-1) * (s[i-1] - s[i-k]) 이다.
	// 또 정리하면 s[i] = m*s[i-1] - (m-1)*s[i-k] 이다.
	// 살려줘

	vector<ll> dp(n + 1);
	vector<ll> s(n + 1);
	dp[0] = 1;
	s[0] = 1;
	for (int i = 1; i < k; i++)
	{
		dp[i] = (dp[i - 1] * m) % MOD;
		s[i] = (s[i - 1] + dp[i]) % MOD;
	}
	
	for (int i = k; i <= n; i++)
		s[i] = (m * s[i - 1] - (m - 1) * s[i - k]) % MOD;

	ll allSeq = 1;
	for (int i = 1; i <= n; i++)
	{
		allSeq *= m;
		allSeq %= MOD;
	}
	cout << (allSeq - s[n] + s[n - 1] + MOD) % MOD;
	return 0;
}

