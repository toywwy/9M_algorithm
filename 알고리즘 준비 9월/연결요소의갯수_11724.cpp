/*
문제 : 찾기
문제 번호: 1786
풀이법 : KMP
날짜 : 18.04.05
기타 :

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>

using namespace std;

int arr[1004][1004];
int len[1004];

bool visit[1004][1004];
bool nodeVisit[1004];

void dfs(int v)
{
	for (int j = 0; j < len[v]; j++)
	{
		if (visit[v][arr[v][j]] == 0 && arr[v][j] != 0)
		{
			visit[arr[v][j]][v] = visit[v][arr[v][j]] = 1;
			nodeVisit[v] = nodeVisit[arr[v][j]] = 1;
			dfs(arr[v][j]);
		}
	}
}

int main(void)
{
	

	int N, E,u,v;
	scanf("%d %d", &N, &E);

	/*int arr[1004][1004];
int len[1004];

bool visit[1004][1004];
bool nodeVisit[1004];
*/
	for (int i = 0; i < 1004; i++)
	{
		len[i] = 0;
		nodeVisit[i] = 0;
		for (int j = 0; j < 1004; j++)
		{
			arr[i][j] = 0;
			visit[i][j] = 0;
		}
	}

	for (int i = 0; i < E; i++)
	{
		scanf("%d %d", &u, &v);
		arr[u][len[u]++] = v;
		arr[v][len[v]++] = u;
	}
	
	int res = 0;
	for (int i = 1; i <=N; i++)
	{
		for (int  j = 0; j < len[i]; j++)
		{
			if (visit[i][arr[i][j]] == 0 && arr[i][j] !=0)
			{
				visit[arr[i][j]][i] = visit[i][arr[i][j]] = 1;
				nodeVisit[i] = nodeVisit[arr[i][j]] = 1;

				dfs(arr[i][j]);
				res++;
			}
		}
	}

	for (int i = 1; i <= N; i++) if (nodeVisit[i] == 0) res++;

	cout << res << endl;

	return 0;
}
