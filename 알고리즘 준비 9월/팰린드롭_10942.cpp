

/*
문제 : 팰린드롭
문제 번호: 10942
풀이법 : dp
날짜 : 160914
기타 : dp를 사용하는 ...
*/





#include <iostream>
#include <cstdio>

bool dp[2001][2001];
int arr[2001];
int n;
int q;

int main(void) {
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);

	for (int i = 1; i <= n; i++) {
		dp[i][i] = 1; //자기자신 으로 가는건 1이고
		if (i != n) {

			if (arr[i] == arr[i + 1])
				dp[i][i + 1] = 1;
			else
				dp[i][i + 1] = 0;
		}
	}

	for (int j = 1; j <= n; j++) {
		for (int i = 1; i < j - 1; i++) {

			if (dp[i + 1][j - 1] && (arr[i] == arr[j]))
				dp[i][j] = 1;
			else
				dp[i][j] = 0;
		}
	}

	scanf("%d", &q);

	int s, e;

	for (int i = 0; i < q; i++) {

		scanf("%d %d", &s, &e);

		if (dp[s][e] == 1)
			printf("1\n");
		else
			printf("0\n");
	}


	return 0;
}

