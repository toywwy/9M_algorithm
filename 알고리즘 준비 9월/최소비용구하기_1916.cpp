/*
문제 :		최소비용구하기
문제 번호:	1916
풀이법 :		다익스트라
날짜 :		161015
기타 :		priority Queue를 이용해서 구현했다.

값을가져다가 쓸때 pair의 second에다가 dp값을넣어서 처리를할거면 처음부터넣어주고
아니라면 
dp[p.first] 이렇게 비교하는게 수월하다.

pq.push(P(s, 0));//그래서 그냥 이렇게하면 수월함

*/



#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<functional>

#define INF 1000000000

using namespace std;

typedef pair<int, int> P;

vector<P> v[1002];

//n(1≤n≤1,000)개의 도시가 있다. 그리고 한 도시에서 출발하여 다른 도시에 도착하는 m(1≤m≤100,000)
int dp[1002];
int visit[1002];
class priority {

public:
	bool operator()(P a, P b)
	{
		return a.second > b.second;
	}
};


int main(void)
{
	int n, m;
	cin >> n >> m;//정점갯수

	int a, b, c;

	priority_queue < P, vector<P>, priority> pq;

	for (int i = 0; i <= 1000; i++)
		dp[i] = INF;

	while (m--)
	{
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back(P(b, c));
	}

	int s, e;
	cin >> s >> e;
	visit[s] = 1;

	dp[s] = 0;//자기자신부터 출발하기떄문에 값 필요

	pq.push(P(s, 0)); //처음꺼 넣고 해도 되지만... 잘생각해서 
					  //s에서 부터 e로 가는거다.
	while (--n)
	{
		P p = pq.top(); pq.pop();
		visit[p.first] = 1;

		if (p.first == e)
			break;
		for (P a : v[p.first])
		{
			if (!visit[a.first])
			{
				if (dp[a.first] > dp[p.first] + a.second)//이때만 삽입하는게 좋다.
				{
					dp[a.first] = dp[p.first] + a.second;
					pq.push(P(a.first, dp[a.first]));
				}
			}
		}
	}
	cout << dp[e] << endl;
	return 0;
}
