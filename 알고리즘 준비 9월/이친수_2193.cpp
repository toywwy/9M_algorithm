/*
���� : ��ģ��
���� ��ȣ: 2193
Ǯ�̹� : DP
��¥ : 170509
��Ÿ : DP[i] = DP[i-1]+DP[i-2]
���� ���� ��ŭ 0�� �����ȴ�.
������ 0 ������ŭ 1�� �����ȴ� (������ 0������ ������ ������)
*/

#include<iostream>
using namespace std;
unsigned long long dp[100];//90�ڸ� ��ģ���� ���ϴ� ����
int main(void)
{
	int N;
	dp[1] = dp[2] = 1,dp[3] = 2;
	cin >> N;
	if (N > 3)
		for (int i = 4; i <= N; i++) dp[i] = dp[i - 1] + dp[i - 2];
	cout << dp[N] << endl;
	return 0;
}