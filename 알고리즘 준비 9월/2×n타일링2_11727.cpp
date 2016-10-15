/*
���� :		2��nŸ�ϸ�2
���� ��ȣ:	11727
Ǯ�̹� :		DP
��¥ :		161015
��Ÿ :		��ȭ��

dp[n] = dp[n-1]+ dp[n-2] *2

2�� ¥���� ���� ����� 2���� �����ϱ� 

*/

#include<iostream>
#define MOD 10007
using namespace std;

int dp[1001];

int main(void)
{
	int n;
	cin >> n;
	dp[0] = dp[1] = 1; //���� �͵� 1�� �ľ���.

	for (int i = 2; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2]*2;//2��¥���� ���� ����� 2���̴ϱ�
		if (dp[i] >= MOD) dp[i] %= MOD;
	}

	cout << dp[n] << endl;

	return 0;
}