/*
문제 : 소수경로
문제 번호: 1964
풀이법 : BFS
날짜 : 20
기타 : 최단거리를 구해야해서 DFS보단 BFS를 이용하도록 하자.
각 test case에 대해 두 소수 사이의 변환에 필요한 최소 회수를 출력한다. 불가능한 경우 Impossible을 출력한다.

BFS는 뎁스를 어떻게 나누는지가 중요한것같다.
여기서는 뎁스를 한자리를 바꾸는 모든 소수가 뎁스이다.

여러가지 정보를 담고 싶을땐 ..보통 카운트를 담고 싶지 pair를 이용해서 사용하자.

*/

#include<iostream>
#include<string>
#include<queue>

using namespace std;

typedef pair<int, int> P;

bool check[10001];//범위는 1000부터 ~9999 까지로한다.
bool visit[10001];
bool resFlag;
int res;
int to;
queue<P> q;

inline int mergeInt(int a1, int a2, int a3, int a4)
{
	return a1 * 1000 + a2 * 100 + a3 * 10 + a4;
}

inline void pushInt(int c, int cnt)
{
	if (c < 1000)
		return;

	if (!check[c] && !visit[c])
	{
		if (c == to)//end
		{
			res = cnt+1;
			resFlag = 1;
			visit[c] = 1;
			while (!q.empty())
				q.pop();
		}
		else
		{
			visit[c] = 1;
			q.push(P(c, cnt + 1));
		}
	}
}

int main(void)
{
	//일단 소수를 구하고 시작하자.
	check[0] = check[1] = 1;
	check[2] = false;//소수다 이걸 false로 선택하는 이유는 잘 생각해보셈

	for (int i = 2; i <= 10000; i++)
	{
		if (check[i]) continue; //소수 아니면 패스
		for (int j = 2; i*j <= 10000; j++) check[i*j] = 1; //소수가 아님.
	}
	//소수 구하기 완료

	int itr;
	cin >> itr;

	for (int i = 0; i < itr; i++)
	{
		int from;//to는전역
		cin >> from >> to;

		q.push(P(from, 0));
		visit[from] = 1;

		int a[4], c;

		if (from == to)
		{
			cout << 0 << endl;
			continue;
		}
		res = 0;
		resFlag = false;

		fill(visit + 999, visit + 9999, 0);


		while (!q.empty())
		{
			P ps = q.front(); q.pop();
			int p = ps.first;

			a[0] = p / 1000;
			p = p % 1000;

			a[1] = p / 100;
			p = p % 100;

			a[2] = p / 10;
			p = p % 10;

			a[3] = p;

			for (int j = 0; j <= 9; j++) //수 선택
			{
				c = mergeInt(j, a[1], a[2], a[3]);//천의자리
				pushInt(c, ps.second);

				c = mergeInt(a[0], j, a[2], a[3]);//백의자리
				pushInt(c, ps.second);

				c = mergeInt(a[0], a[1], j, a[3]);//십의자리
				pushInt(c, ps.second);

				c = mergeInt(a[0], a[1], a[2], j);//일의자리
				pushInt(c, ps.second);
			}
		}

		if (visit[to])//정답에방문했다.
			cout << res << endl;
		else
			cout << "Impossible" << endl;

	}
	return 0;
}