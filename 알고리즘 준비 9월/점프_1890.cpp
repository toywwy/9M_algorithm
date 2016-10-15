/*
문제 :		점프
문제 번호:	1890
풀이법 :		DP
날짜 :		161015
기타 :		점화식

4
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1

케이스가 존재한다고 생각을한다.

dp[i + arr[i][j]][j] += dp[i][j];//아래쪽
dp[i][j + arr[i][j]] += dp[i][j];//오른쪽

dp[n][n] 이답이다.

*/

#include<iostream>
using namespace std;

int arr[112][112];
unsigned long long int dp[112][112];

int main(void)
{
	int n;
	cin >> n;
	for(int i = 1; i<=n;i++)
		for (int j = 1; j <= n; j++) 
			scanf("%d",&arr[i][j]);

	dp[1 + arr[1][1]][1] = 1;
	dp[1][1 + arr[1][1]] = 1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (dp[i][j] > 0)
			{
				if (i == n&&j == n)
					break;

				dp[i + arr[i][j]][j] += dp[i][j];
				dp[i][j + arr[i][j]] += dp[i][j];
			}
		}
	}

	cout << dp[n][n] << endl;

	return 0;
}


/*

N (4 ≤ N ≤ 100)이 주어진다. 
칸에 적혀있는 수는 0보다 크거나 같고, 
9보다 작거나 같은 정수이며, 가장 오른쪽 아래 칸에는 항상 0이 주어진다.

*/