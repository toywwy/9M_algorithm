
/*
���� : �Ӹ����?
���� ��ȣ: 10942
Ǯ�̹� : DP
��¥ : 160916
��Ÿ : dp�� �̿��Ѵ�. ������ �ް� ����°� �ƴ϶� ó������ dp ����� �������´�.
1�� ¥���� 2�� ¥���� �̿��ؼ� ������ ���鼭 ��� ��쿡 ���� ���̽��� ����� ���̴�.
2000 x 2000�� �̰���� �������� �ְ� �ȴ�.
*/


#include<iostream>

using namespace std;

int arr[2002];
bool dp[2002][2002];//�̰��� ũ��.

int main(void)
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	for (int i = 1; i <= n; i++)
	{
		dp[i][i] = 1;//�ڱ��ڽ��̰� �Ǵ°���
		if (arr[i] == arr[i + 1])
			dp[i][i + 1] = 1; // ����ó�� ������Ѵ�. j�� 1�̿�����  dp[j+1][j+i-1]�� ������ �н� ���ϱ� ����
	}

	for (int i = 2; i <= n; i++)//���� i�� �������� ����
	{
		for (int j = 1; j <= n; j++)//Ƚ��
		{
			if (j + i > n)
				break;

			if (arr[j] == arr[j + i] && dp[j + 1][j + i - 1])
			{
				dp[j][j + i] = 1;
			}
		}
	}

	int q = 0;
	scanf("%d", &q);

	int s, e;

	for (int i = 0; i < q; i++) {

		scanf("%d %d", &s, &e);

		if (dp[s][e])
			printf("1\n");
		else
			printf("0\n");
	}


	return 0;
}