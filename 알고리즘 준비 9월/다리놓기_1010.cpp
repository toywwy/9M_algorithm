/*
���� : �ٸ�����
���� ��ȣ: 1010
Ǯ�̹� : ���� Combination
��¥ : 20170509
��Ÿ :
������ DP�� nCk

	n!
(n-k)! * k!
*/

#include<iostream>
using namespace std;

int dp[31][31];
unsigned long long fac[30];

unsigned long long mfac(int n,int cnt)
{
	unsigned long long m = 1;
	for (int i = 0; i < cnt; i++)
	{
		m *= n;
		n--;
	}
	return m;
}

int main(void)
{
	int N,M,T,half;
	cin >> T;

	fac[0] = fac[1] = 1;
	for (int i = 2; i <= 15; i++) fac[i] = fac[i - 1] * i;

	for (int tc = 0; tc < T; tc++)
	{
		cin >> N >> M; //mCn �ϸ�ȴ�.
		half = M / 2;

		if (N > half) N = M - N; //���ݺ��� Ŭ��

		cout<< mfac(M, N) / fac[N] <<endl;
	}

	return 0;
}
