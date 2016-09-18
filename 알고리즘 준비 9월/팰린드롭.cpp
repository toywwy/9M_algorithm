#include <stdio.h>
int Dp[2001][2001] = {};
int main(void) {

	int N;
	int room[2001] = {};

	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &room[i]);

	int questNum;
	scanf("%d", &questNum);

	for (int i = 1; i <= N; i++) {
		Dp[1][i] = 1;
		Dp[0][i] = 1;
	}
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= N - i + 1; j++) {
			if (room[j] == room[j + i - 1] && Dp[i - 2][j + 1] == 1)
				Dp[i][j] = 1;
		}
	}
	while (questNum--) {
		int S, E;
		scanf("%d %d", &S, &E);
		printf("%d\n", Dp[E - S + 1][S]);
	}
}

//이거 이해하는것도 DP에 도움이 될 것같은데