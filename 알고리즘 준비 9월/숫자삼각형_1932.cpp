/*
���� : ���� �ﰢ��
���� ��ȣ: 1932
Ǯ�̹� : DP
��¥ : 170509
��Ÿ : ��ȭ��
i = st �϶� dp[i] = before[i]+input
i = end �϶� dp[i] = befroe[i-1]+input
else �϶� max( before[i]+input,befroe[i-1]+input)
before�� dp ������ �����ؾ���.
*/

#include<iostream>
#include<algorithm>
using namespace std;

int dp[501];
int beforeDP[501];

int main(void)
{
	int N,mMax,input;
	cin >> N>>dp[0];
	beforeDP[0] = dp[0];

	for (int i = 2; i <= N; i++)//��
	{
		for (int j = 0; j < i; j++)
		{
			cin >> input;//���� ��= ������ + 1 (����) dp ����

			if (j == 0)
				dp[j] = beforeDP[j] + input;
			else if (j - 1 == i)
				dp[j] = beforeDP[j-1] + input;
			else 
				dp[j] = max(beforeDP[j - 1] + input, beforeDP[j] + input);
		}
		for (int j = 0; j < i; j++) beforeDP[j] = dp[j];//
	}

	mMax = dp[0];
	for (int i = 1; i < N; i++)
		if (mMax < dp[i]) mMax = dp[i];

	cout << mMax << endl;

	return 0;
}