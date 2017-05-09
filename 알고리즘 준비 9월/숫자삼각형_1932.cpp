/*
문제 : 숫자 삼각형
문제 번호: 1932
풀이법 : DP
날짜 : 170509
기타 : 점화식
i = st 일때 dp[i] = before[i]+input
i = end 일때 dp[i] = befroe[i-1]+input
else 일때 max( before[i]+input,befroe[i-1]+input)
before와 dp 관리에 유의해야함.
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

	for (int i = 2; i <= N; i++)//행
	{
		for (int j = 0; j < i; j++)
		{
			cin >> input;//현재 행= 이전행 + 1 (길이) dp 쓸때

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