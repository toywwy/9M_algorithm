/*
문제 : 알파벳
문제 번호: 1987
풀이법 : DFS
날짜 : 19.01.11
기타 :
*/

#include<iostream>
#include<queue>

using namespace std;

bool visit[256];

// (1<=R,C<=20)
int map[24][24];
int v[24][24];
//상하 좌우
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int M;
void dfs(int x, int y,int m)
{
	M = max(M, m);

	for (int i = 0; i < 4; i++)
	{
		if (visit[map[dy[i] + y][dx[i] + x]] == false)
		{
			visit[map[dy[i] + y][dx[i] + x]] = true;
			dfs(dx[i] + x, dy[i] + y,m+1);
			visit[map[dy[i] + y][dx[i] + x]] = false;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int R, C;//2행 4열
	cin >> R >> C;
	char c;
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			cin >> c;
			map[i][j] = c;
		}
	}

	visit[map[1][1]] = visit[0] = true; //map에서 값이 0 인거, 1,1 인거 지나온걸로 체크
	v[1][1] = 1;

	dfs(1, 1, 1);

	cout << M << endl;
	return 0;
}
