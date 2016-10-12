/*

DFS 메모이제이션 실패

문제 :		역사
문제 번호:	1613
풀이법 :		DFS, 메모이제이션
날짜 :		161011
기타 :		실패함..
DFS에 캐싱을 썼는데 실패했다.
왜냐하면 

1->2->3->4->6 까지 캐싱을했다. 

x->1 ->6 으로되는것이다.

but 
1->2->3->4->6->7
x->7을 찾아갈땐
[1][7] 이 아직 탐색이 안됐기 떄문에 가지를 못했따.
결국 다시 저 경로를 탐색하면서 가는 문제가 발생...

+ 그리고 추가해야하는게 있었다. 

-1 찾았으나 못찾은 경우도 -1로 셋을해놔야한다.

이부분을 해결 하면 ... 진짜 할 수 있는 일도 많을것 같은데 
*/


#include<cstdio>
#include<vector>
#include<queue>

#define N 400
using namespace std;

vector<int> v[N + 2];
vector<int> q;

bool dp[N + 2][N + 2];

bool resFlag;
int target = 0;
void recur(int x)
{
	for (int k : v[x])
	{
		for (int d : q) dp[d][k] |= 1;//정답이던 아닌던 얘는 갈수있음.

		if (k != target)
		{
			if (dp[k][target]) {
				resFlag = 1;
				break;
			}

			q.push_back(k);
			recur(k);
			q.pop_back();
		}
		else {
			resFlag = 1;
			break;
		}
	}
	if (resFlag)
		return;
}


int main(void)
{
	int n, m, a, b, qCnt;
	scanf("%d %d", &n, &m);

	while (m--)
	{
		scanf("%d %d", &a, &b);
		v[a].push_back(b);//아래로 내려가는거다.
	}

	scanf("%d", &qCnt);
	while (qCnt--)
	{
		scanf("%d %d", &a, &b);
		//a->b로 가는걸 찾으면거 dp에 저장을 하자.
		resFlag = 0;

		target = b;
		q.push_back(a);
		recur(a);
		q.pop_back();

		if (resFlag)
		{
			printf("-1\n");
			continue;
		}
		else
		{
			target = a;
			q.push_back(b);
			recur(b);
			q.pop_back();

			if (resFlag)
				printf("1\n");
			else
				printf("0\n");
		}
	}

	return 0;
}
