/*
문제 :
문제 번호:
풀이법 :
날짜 :
기타 :

*/
#include<iostream>
using namespace std;

long long dp[40] = { 0,0,3,2,0,0,6 };

int main(void)
{
	int n;
	cin >> n;
	
	for (int i = 6; i <= n; i++)
	{
		dp[i] += dp[i - 2] * dp[2];
		dp[i] += dp[i - 3] * dp[3];
		dp[i] += dp[i - 6] * dp[4];
	}

	cout << dp[n] << endl;

	return 0;
}