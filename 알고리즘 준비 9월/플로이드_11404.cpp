/*
���� :		�÷��̵�
���� ��ȣ:	11404
Ǯ�̹� :		�÷��̵� �ͼ�
��¥ :		160918
��Ÿ :		�� �������� ���ܰ� �����߾���. �Է¹����� �� ������ ��찡 ���� ���� ������ ���̽��̴�.
*/

#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

#define INF 100000000
#define N 100
//���� 100, ���� 100000, ��� 100000

using namespace std;


int dp[N + 2][N + 2];

int main(void)
{
	int n, bus; // ���� ����, ���� ����
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


	//dp �迭����� �װ� ����°ų�


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