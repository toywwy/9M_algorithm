
/*
�ᱹ�� Ǫ�µ��� �����ߴ�. BFS�� Ǯ�̰� �����ϸ� DFS�� ���� �ϸ��� �����ߴµ� �Ұ��� ��������.
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
			int mm = min(v,k.second); //���� ���ο��� ������ ���ο������ //���ŵ� ��ġ������.
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
		vec[a].push_back(P(b, c));//c�� ����ġ�̴�.
		vec[b].push_back(P(a, c));
	}

	cin >> mStart >> mEnd;


	flag[mStart] = 1;
	dp[mStart] = INF;
	dfs(mStart,INF);
	cout << minimum << endl;


	return 0;
}