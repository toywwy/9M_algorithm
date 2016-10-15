/*
문제 :		2×n타일링
문제 번호:	11726
풀이법 :		DP
날짜 :		161015
기타 :		점화식

dp[n] = dp[n-1]+dp[n-2]

결국 |를 추가하는것과
= 를 추가하는 방법만있었던거니까 이전꺼가 그대로 더해지니까.

*/

#include<iostream>
#define MOD 10007
using namespace std;

int dp[1001];

int main(void)
{
	int n;
	cin >> n;
	dp[0] = dp[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]);
		if (dp[i] >= MOD) dp[i] %= MOD;//나머지 연산 비싸다...
	}
	
	cout << dp[n] << endl;

	return 0;
}