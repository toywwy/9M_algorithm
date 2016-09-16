
/*
문제 : 팰린드롭?
문제 번호: 10942
풀이법 : DP
날짜 : 160916
기타 : dp를 이용한다. 문제를 받고 만드는게 아니라 처음부터 dp 결과를 만들어놓는다.
1개 짜리고 2개 짜리를 이용해서 포문을 돌면서 모든 경우에 대한 케이스를 만드는 것이다.
2000 x 2000에 이결과는 담을수가 있게 된다.
*/


#include<iostream>

using namespace std;

int arr[2002];
bool dp[2002][2002];//이게좀 크네.

int main(void)
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	for (int i = 1; i <= n; i++)
	{
		dp[i][i] = 1;//자기자신이건 되는거지
		if (arr[i] == arr[i + 1])
			dp[i][i + 1] = 1; // 예외처리 해줘야한다. j가 1이였을떄  dp[j+1][j+i-1]이 조건을 패스 못하기 때문
	}

	for (int i = 2; i <= n; i++)//간격 i의 간격으로 진행
	{
		for (int j = 1; j <= n; j++)//횟수
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