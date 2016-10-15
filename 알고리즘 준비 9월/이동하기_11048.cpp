/*
문제 :		이동하기
문제 번호:	11048
풀이법 :		DP
날짜 :		161015
기타 :		점화식

dp[i][j + 1] = max(dp[i][j + 1],arr[i][j + 1] + dp[i][j]);
dp[i+1][j] = max(dp[i+1][j], arr[i+1][j] + dp[i][j]);

자체가 점화식
*/

#include<iostream>
#include<algorithm>

using namespace std;

int arr[1002][1002];
int dp[1002][1002];
int main(void)
{
	int r, c;
	cin >> r >> c;

	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			scanf("%d",&arr[i][j]);

	for (int i = 1; i <= r; i++)
	{
		for (int j = 0; j <= c; j++)
		{
			dp[i][j + 1] = max(dp[i][j + 1],arr[i][j + 1] + dp[i][j]);
			dp[i+1][j] = max(dp[i+1][j], arr[i+1][j] + dp[i][j]);
		}
	}

	cout << dp[r][c] << endl;

	return 0;
}