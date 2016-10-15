/*
���� :		2��nŸ�ϸ�
���� ��ȣ:	11726
Ǯ�̹� :		DP
��¥ :		161015
��Ÿ :		��ȭ��

dp[n] = dp[n-1]+dp[n-2]

�ᱹ |�� �߰��ϴ°Ͱ�
= �� �߰��ϴ� ������־����Ŵϱ� �������� �״�� �������ϱ�.

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
		if (dp[i] >= MOD) dp[i] %= MOD;//������ ���� ��δ�...
	}
	
	cout << dp[n] << endl;

	return 0;
}