/*
문제 : 다리놓기
문제 번호: 1010
풀이법 : 수학 Combination
날짜 : 20170509
기타 :
조합을 DP로 nCk

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
		cin >> N >> M; //mCn 하면된다.
		half = M / 2;

		if (N > half) N = M - N; //절반보다 클떄

		cout<< mfac(M, N) / fac[N] <<endl;
	}

	return 0;
}
