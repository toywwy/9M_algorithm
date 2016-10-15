/*
문제 :		1, 2, 3더하기
문제 번호:	9095
풀이법 :		DP
날짜 :		161015
기타 :		점화식

dp[n] = dp[n-1]+dp[n-2]+dp[n-3]

+1을더해서 표현
+2를 더해서 표현
+3을 더해서 표현 하는 방법들이기때문...

*/

#include<iostream>
#include<algorithm>

using namespace std;

int dp[11] = { 0,1,2,4 };

int main(void)
{

	int itrCnt = 0;
	cin >> itrCnt;
	int min = 4;

	for(int itr = 0 ; itr <itrCnt;itr++)
	{
		int n;
		cin >> n;

		if (dp[n] != 0)
		{
			cout << dp[n] << endl;
			continue;
		}

		for (int i = min; i <= n; i++)
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];

		cout << dp[n] << endl;

		if (min < n)
			min = n;
	}
	return 0;
}