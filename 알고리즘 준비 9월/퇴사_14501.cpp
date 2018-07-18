/*
문제 : 퇴사
문제 번호: 14501
풀이법 : DP
날짜 : 18.07.18
기타 : 

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int dp[22],t[22],p[22];
int main(void)
{
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) cin >> t[i] >> p[i];

	//solve
	for (int i = 1; i <= N; i++)
	{
		if (t[i] == 1) dp[i] = max(dp[i], dp[i - 1] + p[i]);
		else
		{
			dp[i] = max(dp[i],dp[i - 1]);//현재 자리의 값
			dp[i + t[i]-1] =max(dp[i + t[i]-1], dp[i - 1] + p[i]);//이때 완성 되는 값.
		}
	}

	cout << dp[N] << endl;

	return 0;
}
