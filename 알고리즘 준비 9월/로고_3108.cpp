/*
문제 :		로고
문제 번호:	3108
풀이법 :		BFS
날짜 :		161014
기타 :

*/

#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

#define N 1000
#define PADDING 501
using namespace std;

typedef pair<int, int> P;


bool map[N + 3][N + 3];
int arr[N + 3][N + 3][4];//맵 받을때 사용한다.
bool visit[N + 3][N + 3];

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

int main(void)
{
	int n, a, b, c, d;
	cin >> n;

	while (n--) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
		a += PADDING;
		b += PADDING;
		c += PADDING;
		d += PADDING;

		//(a,b) 에서 (c,d) 까지 테두리를 그으면된다.

		if (a > c)
			swap(a, c);
		if (b > d)
			swap(b, d);

		int x = a, y = b;//시작지점


		while (a <= c) {
			map[b][a] = 1;

			if (a == y)//처음
			{
				arr[b][a][0] = 1;//위로
				arr[b][a][3] = 1;//우측
			}
			else if (a == c)//끝
			{
				arr[b][a][0] = 1;//위로
				arr[b][a][2] = 1;//좌측
			}
			else {
				arr[b][a][2] = 1;//좌측
				arr[b][a][3] = 1;//우측
			}

			a += 1;
		}
		a -= 1;

		while (b <= d)// b y축이 증가하는거다.
		{
			map[b][a] = 1;
			if (b == y)// 처음꺼는 왼쪽으로 갈수있다. 그리고 위로도 갈수있다. 대신 아래로 못간다.
			{
				arr[b][a][2] = 1;//왼쪽
				arr[b][a][0] = 1;//위쪽
			}
			else if (b == d) // 마지막꺼는 위로 못가기떄문
			{
				arr[b][a][2] = 1;//왼쪽
				arr[b][a][1] = 1;//아래쪽
			}
			else
			{
				arr[b][a][0] = 1;//위쪽
				arr[b][a][1] = 1;//아래쪽
			}
			b += 1;//여기에서 y값을 증가 시킨다는 의미는 
		}

		b -= 1;


		a = x;
		b = y; //초기위치
		while (y <= d)
		{
			map[y][x] = 1;
			if (b == y)//처음꺼는 아래로 못 간다.
			{
				arr[y][x][0] = 1;//위로가고
				arr[y][x][3] = 1;//오른쪽
			}
			else if (b == d) //마지막꺼는 위로 못가기떄문
			{
				arr[y][x][1] = 1;//아래
				arr[y][x][3] = 1;//오른쪽
			}
			else
			{
				arr[y][x][1] = 1;//아래
				arr[y][x][0] = 1;//위
			}
			y += 1;
		}
		y -= 1;

		while (x <= c) {

			map[y][x] = 1;

			if (x == a)
			{
				arr[y][x][3] = 1;//오른쪽
				arr[y][x][1] = 1;//아래
			}
			else if (x == c)//마지막
			{
				arr[y][x][2] = 1;//왼쪽
				arr[y][x][1] = 1;//아래
			}
			else
			{
				arr[y][x][2] = 1;//왼쪽
				arr[y][x][3] = 1;//오른쪽
			}

			x += 1;
		}
		x -= 1;
	}

	queue<P> q;
	int res = 1;

	if (map[PADDING][PADDING])
		res = 0;
	else
		res = 1;//다른 곳으로 한번이동하기위해서 들어야함

	for (int i = 1; i <= N + 1; i++)
	{
		for (int j = 1; j <= N + 1; j++)
		{
			if (map[i][j] && !visit[i][j])
			{
				res++;
				q.push(P(j, i));
				visit[i][j] = 1;// i

				while (!q.empty())
				{
					P p = q.front(); q.pop();
					for (int k = 0; k < 4; k++)
					{
						if (arr[p.second][p.first][k] && !visit[p.second + dy[k]][p.first + dx[k]] && map[p.second + dy[k]][p.first + dx[k]])//지금 나온 값이 어디로 갈수있는지를 체크한다.
						{
							visit[p.second + dy[k]][p.first + dx[k]] = 1;
							q.push(P(p.first + dx[k], p.second + dy[k]));
						}
					}
				}

			}
		}
	}

	cout << res - 1 << endl;//마지막에 한번은 증가하기 떄문

	return 0;
}

