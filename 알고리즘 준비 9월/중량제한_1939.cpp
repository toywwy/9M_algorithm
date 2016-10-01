
/*
결국에 푸는데는 실패했다. BFS로 풀이가 가능하면 DFS도 가능 하리라 생각했는데 불가능 헀나보다.
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define N 10000
#define INF 10000002
typedef pair<int, int> P;

bool flag[N + 2];
int dp[N + 2];
vector<P> vec[N + 2];

int mStart, mEnd;
int minimum = 0;

inline void dfs(int a,int v)
{
	for (P k : vec[a])
	{
		int first = k.first;
		if (!flag[first])
		{
			int mm = min(v,k.second); //내가 새로운길로 갔을때 새로운값을얻음 //갱신될 가치가있음.
			if (dp[first] < mm)
			{
				if (mm < minimum)
					return;

				dp[first] = mm;

				if (first == mEnd)
				{
					minimum = max(minimum, mm);
					return;
				}

				flag[first] = 1;
				dfs(first, mm);
				flag[first] = 0;
			}
		}
	}
}

int main(void)
{

	int n, m;
	cin >> n >> m;

	int a, b, c;

	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		vec[a].push_back(P(b, c));//c는 가중치이다.
		vec[b].push_back(P(a, c));
	}

	cin >> mStart >> mEnd;


	flag[mStart] = 1;
	dp[mStart] = INF;
	dfs(mStart,INF);
	cout << minimum << endl;


	return 0;
}