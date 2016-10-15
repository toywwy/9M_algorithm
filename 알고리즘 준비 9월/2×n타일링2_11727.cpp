/*
문제 :		2×n타일링2
문제 번호:	11727
풀이법 :		DP
날짜 :		161015
기타 :		점화식

dp[n] = dp[n-1]+ dp[n-2] *2

2개 짜리를 놓을 방법이 2가지 있으니까 

*/

#include<iostream>
#define MOD 10007
using namespace std;

int dp[1001];

int main(void)
{
	int n;
	cin >> n;
	dp[0] = dp[1] = 1; //없는 것도 1로 쳐야함.

	for (int i = 2; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2]*2;//2개짜리가 들어가는 방법이 2개이니까
		if (dp[i] >= MOD) dp[i] %= MOD;
	}

	cout << dp[n] << endl;

	return 0;
}