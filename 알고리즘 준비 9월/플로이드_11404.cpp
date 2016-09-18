/*
문제 :		플로이드
문제 번호:	11404
풀이법 :		플로이드 와샬
날짜 :		160918
기타 :		이 문제에서 예외가 존재했었다. 입력받을때 더 안좋은 경우가 덮어 씌워 버리는 케이스이다.
*/

#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

#define INF 100000000
#define N 100
//도시 100, 간선 100000, 비용 100000

using namespace std;


int dp[N + 2][N + 2];

int main(void)
{
	int n, bus; // 도시 갯수, 버스 갯수
	cin >> n >> bus;

	int s,e,w;
	for (int i = 0; i < bus; i++)
	{
		scanf("%d %d %d", &s, &e, &w);
		if(dp[s][e]!=0)
			dp[s][e] = min(dp[s][e], w);
		else
			dp[s][e] =w;
	}
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
				dp[i][j] = 0;
			else if (dp[i][j] == 0)
				dp[i][j] = INF;
		}
	}


	//dp 배열만들고 그거 쓰라는거네


	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if(dp[i][j] >= INF)
				printf("0 ");
			else
				printf("%d ",dp[i][j]);
		}
		printf("\n");
	}

	return 0;
}