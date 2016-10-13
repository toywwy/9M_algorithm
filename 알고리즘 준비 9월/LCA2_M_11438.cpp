/*
문제 : LCA2
문제 번호: 11438
풀이법 : LCA - Lowest Common Ancestor
날짜 : 161008
기타 :

2^i 스응로 저장한다. 진짜 LCA를 이용하는것이다.

2^0 2^1 2^2 2^3
1	2	4	8 ..........

진짜 엄청 중요한거 바텀업을 만들때 ,,, 배열을 어떤 순서로 돌려야 이전의 값이 잘이용되나...

나는 여기에서 노드들이 왜 순서대로라고 생각하고 노드를 가지고 돌렸을까 ... 문제다 문제.... 심각하다.


정답을 찾는 것도 무지 어려웠다 ....

일단 dp 가 -1이 아닌것 유효하면서
a b의 부모가 서로 다른 것을 찾는다.

그렇게 되면답은 2^k ~2^k+1에 있게 되는것이다. k+1을 찾게되는거지 그래서 나머지 루프를 다시 돌려서
정답을 찾고 부모가 서로 다른 것을 찾았으니까.
정답에서는 부모로 상승을 시켜줘야한다.

마지막에 정답찾는과정....

최초로 유효한 값이나 부모가 다른 것을 찾아서
그리고 남은 인덱스를 가지고 그것를 찾아 나가는것이다.....
어렵다.


*/


#include <iostream>
#include <vector>
#define N 100000
#define MAX 17 // 1 * 2^17 ....이면 10만을 초과 한다.
using namespace std;

int depth[N + 2]; //갯수가 50000만개
				  //vector<int> dp[N + 2];
int dp[N + 2][MAX + 2];//어떤걸로 할지는 생각해보자.

vector<int> input[N + 2];

void recur(int x)//init 하는 부분임
{
	for (int k : input[x])
	{
		if (depth[k] == 0)
		{
			depth[k] = depth[x] + 1;//굳 정보다...진짜로
			dp[k][0] = x;
			recur(k);
		}
	}
}

int main(void)
{
	int n;
	cin >> n;
	int a, b;


	for (int i = 0; i < n + 1; i++)
		for (int j = 0; j < MAX + 1; j++)
			dp[i][j] = -1;//일단 -1로 초기화를했따.


	for (int i = 0; i < n - 1; i++)
	{
		scanf("%d %d", &a, &b);
		input[a].push_back(b);
		input[b].push_back(a);
	}

	depth[0] = depth[1] = 1; // 1이 1이다. 1부터 시작이라고 보면된다.
	recur(1);

	//바텀업으로 구성한다.
	//점화식 새웠어 dp[n][k] = dp[부모(k-1)][k-1] 이게 점화식이다.

	
	//하 .. 완전히 틀린거다 .. 내점화식이 틀려먹은건가... 이런식으로 하면 바텀업이 될탠데
	//왜 idx를 먼져 써야하는건가...>?/
	for (int idx = 1; idx<MAX; idx++) //얘는 순서에 의의가 있다..
	{//내가 그림을 그렇게 그려서 그렇지 .. 얘는 순서의 의미가 없는애였잖아 ..ㅠㅠ
		for (int i = 2; i <= n; i++)
		{
			if (dp[i][idx - 1] == -1) continue;

			dp[i][idx] = dp[dp[i][idx - 1]][idx - 1];
		}
	}
	

	int q, temp, diff, c;
	cin >> q;

	while (q--)
	{
		scanf("%d %d", &a, &b);

		if (a == b)
		{
			printf("%d\n", a);
			continue;
		}

		if (depth[a] < depth[b]) swap(a, b);

		diff = depth[a] - depth[b];
		c = 1;

		//a가 더 긴상태이다.
		if (diff > 0)
		{
			int idx = 0;
			while (idx < MAX)//MAX 17 자리 검사하면된다.17자리로 모두 표현가능
			{
				if (diff&c)	a = dp[a][idx];
				c <<= 1;
				idx++;
			}
		}


		//위에서부터 먼저 찾은후에 계속해서 내려가면서 찾는 방법이다.
		//

		//이걸 바보같이 한칸씩 올라가고 있엇다
		if (a != b) {
			// 높이 2^17, 2^16, ..., 2^2, 2, 1 순으로 시도
			for (int j = MAX - 1; j >= 0; j--) {
			//	2 ^ k, 2 ^ (k + 1) 사이의 어딘가에 있다. 한방이다. 즉
				if (dp[a][j] != -1 && dp[a][j] != dp[b][j]) {
					a = dp[a][j];
					b = dp[b][j];
				}
			}

			// 마지막엔 두 정점 u, v의 부모가 같으므로 한 번 더 올림
			a = dp[a][0]; //그래서 한번더 올린거고
		}
		// 마지막엔 두 정점 u, v의 부모가 같으므로 한 번 더 올림

		printf("%d\n", a);
	}

	return 0;
}