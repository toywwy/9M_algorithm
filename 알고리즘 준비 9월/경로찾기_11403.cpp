/*
���� : �÷��̵�
���� ��ȣ: 11404
Ǯ�̹� : �÷��̵� �ͼ�
��¥ : 160917
��Ÿ : �÷��̵� �ͼ��� ���ؼ� ���� �ذ� INF�� ������ min���� ������ ������ �ȵǱ� ������
�Ѹ���� 
dp[i][j] = min( dp[i][j], dp[i][mid],dp[mid][j])
from to �ε�  from to + from to ���������� ���� ���� ���鼭 �ϴ� ���̴�.
INF�̸� �翬�� MIN���� ��� ����������.

��� ��츦 �����ؼ� �Ǻ��ϴ°Ŷ� ������ �ϴ�.
����ϰ� ���ϴ밡 ���� ���̶� �Ǵܵȴ�. 

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