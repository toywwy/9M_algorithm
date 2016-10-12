/*
���� : ����
���� ��ȣ: 1613
Ǯ�̹� : �÷��̵�ͼ�
��¥ : 161011
��Ÿ : �÷��̵�ͼ��� ����ؼ� ����θ� �ľ��ؼ� ���� �ٷ� �������ִ�. ���� ����°���
DFS�ε� dp�� ����� ������ �� �Ͱ���.

*/

#include <iostream>

using namespace std;


bool dp[402][402];//��ΰ� �ִ��� �������� �ľ��ϸ�Ǵ¹���

int main(void) {
	int n, m;
	cin >> n >> m;

	int a, b;
	while(m--){
		scanf("%d %d", &a, &b);
		dp[a][b]=1;
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dp[i][j] = dp[i][j] | dp[i][k] & dp[k][j];

	int q;
	cin >> q;

	while (q--)
	{
		scanf("%d %d", &a, &b);
		if (dp[a][b])
			printf("-1\n");
		else if (dp[b][a])
			printf("1\n");
		else
			printf("0\n");

	}
	
	return 0;
}