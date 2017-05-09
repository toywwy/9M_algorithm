/*
문제 : 이친수
문제 번호: 2193
풀이법 : DP
날짜 : 170509
기타 : DP[i] = DP[i-1]+DP[i-2]
이전 갯수 만큼 0이 생성된다.
이전의 0 갯수만큼 1이 생성된다 (이전의 0갯수는 전전의 갯수임)
*/

#include<iostream>
using namespace std;
unsigned long long dp[100];//90자리 이친수를 구하는 문제
int main(void)
{
	int N;
	dp[1] = dp[2] = 1,dp[3] = 2;
	cin >> N;
	if (N > 3)
		for (int i = 4; i <= N; i++) dp[i] = dp[i - 1] + dp[i - 2];
	cout << dp[N] << endl;
	return 0;
}