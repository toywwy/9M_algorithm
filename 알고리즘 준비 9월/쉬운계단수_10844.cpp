/*
문제 :		쉬운계단수
문제 번호:	10844
풀이법 :		DP
날짜 :		161015
기타 :		0과 9는 한번씩 더해지는 것을이용 ...
그래서 0은 계쏙 0과 더해지게 되고
9는 계쏙 0과더해진다.
0 = -1 번째 1번째 꺼랑 더해짐 그러나 -1이 0이다.

1 = 0번쨰 2번쨰 꺼랑 더해짐

3 = 2번째 4번째 꺼랑

9 = 8번쨰 10번쨰 그러나 10번쨰꺼가 0이다.

인덱스는 그냥 감소하는 걸로 짜봤다.
큰의미는 없어서

*/

#include<iostream>

#define MOD 1000000000
using namespace std;

int dp[101][12];

int main(void)
{
	int n;
	cin >> n;

	for (int i = 2; i <= 10; i++) dp[n - 1][i] = 1;

	while (--n)
		for (int i = 1; i <= 10; i++)
			dp[n - 1][i] = (dp[n][i - 1] + dp[n][i + 1]) % MOD;

	int res = 0;
	for (int i = 1; i <= 10; i++)
		res = (res + dp[0][i]) % MOD;

	cout << res << endl;

	return 0;
}