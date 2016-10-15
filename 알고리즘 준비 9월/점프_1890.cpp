/*
���� :		����
���� ��ȣ:	1890
Ǯ�̹� :		DP
��¥ :		161015
��Ÿ :		��ȭ��

4
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1

���̽��� �����Ѵٰ� �������Ѵ�.

dp[i + arr[i][j]][j] += dp[i][j];//�Ʒ���
dp[i][j + arr[i][j]] += dp[i][j];//������

dp[n][n] �̴��̴�.

*/

#include<iostream>
using namespace std;

int arr[112][112];
unsigned long long int dp[112][112];

int main(void)
{
	int n;
	cin >> n;
	for(int i = 1; i<=n;i++)
		for (int j = 1; j <= n; j++) 
			scanf("%d",&arr[i][j]);

	dp[1 + arr[1][1]][1] = 1;
	dp[1][1 + arr[1][1]] = 1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (dp[i][j] > 0)
			{
				if (i == n&&j == n)
					break;

				dp[i + arr[i][j]][j] += dp[i][j];
				dp[i][j + arr[i][j]] += dp[i][j];
			}
		}
	}

	cout << dp[n][n] << endl;

	return 0;
}


/*

N (4 �� N �� 100)�� �־�����. 
ĭ�� �����ִ� ���� 0���� ũ�ų� ����, 
9���� �۰ų� ���� �����̸�, ���� ������ �Ʒ� ĭ���� �׻� 0�� �־�����.

*/