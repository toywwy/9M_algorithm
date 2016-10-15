/*
���� :		��������
���� ��ȣ:	11057
Ǯ�̹� :		DP
��¥ :		161015
��Ÿ :		��ȭ��

dp[n][k] = �ñ׸�k->9 dp[n-1][k]

*/

#include<iostream>
#define MOD 10007
using namespace std;

int dp[1001][10];
int n, res;
int main(void)
{
	cin >> n;
	for (int i = 0; i <= 9; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= n; i++)
		for (int j = 0; j <= 9; j++)
		{
			for (int k = j; k <= 9; k++) dp[i][j] += dp[i - 1][k];
			if (dp[i][j] >= MOD) dp[i][j] %= MOD;
		}

	for (int i = 0; i <= 9; i++)
		res += dp[n][i];

	cout << res%MOD << endl;
	return 0;
}