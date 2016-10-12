/*
문제 : 역사
문제 번호: 1613
풀이법 : 플로이드와샬
날짜 : 161011
기타 : 플로이드와샬을 사용해서 모든경로를 파악해서 답을 바로 얻을수있다. 맵을 만드는거지
DFS로도 dp을 만들어 놓으면 될 것같다.

*/

#include <iostream>

using namespace std;


bool dp[402][402];//경로가 있는지 없는지만 파악하면되는문제

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