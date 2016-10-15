/*
���� :		1, 2, 3���ϱ�
���� ��ȣ:	9095
Ǯ�̹� :		DP
��¥ :		161015
��Ÿ :		��ȭ��

dp[n] = dp[n-1]+dp[n-2]+dp[n-3]

+1�����ؼ� ǥ��
+2�� ���ؼ� ǥ��
+3�� ���ؼ� ǥ�� �ϴ� ������̱⶧��...

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