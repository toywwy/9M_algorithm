/*
문제 : 플로이드
문제 번호: 11404
풀이법 : 플로이드 와샬
날짜 : 160917
기타 : 플로이드 와샬을 통해서 문제 해결 INF는 어차피 min으로 했을떄 갱신이 안되기 떄문에
한마디로 
dp[i][j] = min( dp[i][j], dp[i][mid],dp[mid][j])
from to 인데  from to + from to 저런시으로 값을 비교해 보면서 하는 것이다.
INF이면 당연히 MIN에서 살아 남을수없지.

모든 경우를 선택해서 판별하는거라 느리긴 하다.
요긴하게 쓰일대가 있을 것이라 판단된다. 

O ( v^3 )

*/


#include<iostream>
#include<algorithm>
#define INF 100000000
#define N 100
using namespace std;


int dp[N + 2][N + 2];

int main(void)
{
	int n;
	cin >> n;

	int a;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> a;
			(a == 1) ? dp[i][j] = 1 : dp[i][j] = INF;
		}
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
	

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (dp[i][j] == INF)
				cout << 0 << " ";
			else
				cout << 1 << " ";
		}
		cout << endl;
	}


	return 0;
}