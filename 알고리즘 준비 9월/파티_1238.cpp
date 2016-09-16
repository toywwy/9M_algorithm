
/*
문제 : 파티
문제 번호: 1238
풀이법 : 다익스트라
날짜 : 160916
기타 : 다익스트라를 이용해 문제를 해결, 배열을 사용하지 않고 우선순위 큐를 이용한다.
우선순위 큐를 이용할시에 정점을 선택하는 부분은 pop 되는 부분이라는걸 잊으면 안된다.
*/



#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>



#define INF 1000000
#define N 1000

using namespace std;

typedef pair<int, int> P;
//N(1 <= N <= 1,000), M(1 <= M <= 10,000),

struct priority {//이걸왜 굳이 struct로 정의를 해야하는가..
	bool operator()(P a, P b)
	{
		return a.second > b.second;
	}
};


vector<P> v[N+2];//N개는 항상존재한다고 보고 나머지는 가변 배열로서 접근하기 위함

bool flag[N + 2];

int dp[N + 2][N+2];

int maxValue;

int main(void)
{
	//n 마을 , e 간선수 , 목표 sp

	int n, e, sp;
	scanf("%d %d %d", &n, &e, &sp);

	int s, d, w;
	s = d = w = 0;

	for (int i = 1; i <=n; i++)
	{
		for(int j = 1;j<=n;j++)
			dp[i][j] = INF;
	}
	
	for (int i = 0; i < e; i++)
	{
		scanf("%d %d %d", &s ,&d ,&w);
		v[s].push_back(P(d, w));
	}


	//목표는 SP로 가는거고 가장 길게가는 거리를 구하여라.
	//n개의 마을에서 열리는데 sp로 갔다오는데 제일 오래 걸리는 애의 소요 시간을 출력하라

	priority_queue<P, vector<P>, priority>PQ;

	
	//sp로 부터 모든 방향으로의 값을 다 저장한다.
	for(int i = 1;i<=n;i++)
	{

		PQ.push(P(i, 0));
		flag[i] = 1; //자기 자신은 찾은거고 이제 자기 자신으로부터..
		dp[i][i] = 0;//자기 자신으로 가는건 0이다.


		while (!PQ.empty())
		{
			auto select = PQ.top();
			PQ.pop();
			flag[select.first] = 1;
			if (i!=sp && select.first == sp)
			{//다익스트라에서 이렇게 원하는 목표를 찾았을때 거기서 break; 해주는게 시간에 엄청난 영향을 끼친다.
				while (!PQ.empty())
					PQ.pop();
				break;
			}

			for (P p : v[select.first])
			{
				if (!flag[p.first])
				{
					if (dp[i][p.first] > dp[i][select.first] + p.second)
					{
						dp[i][p.first] = (dp[i][select.first] + p.second); //갱신
						PQ.push(P(p.first, dp[i][p.first]));
					}
				}
			}
		}

		for (int i = 1; i <= n; i++)
			flag[i] = 0;
	}

	
	maxValue = 0;
	for (int i = 1; i <= n; i++)
	{
		//sp는 목적지이다. 한마디로
		if( maxValue <dp[i][sp] + dp[sp][i])
			maxValue =dp[i][sp] + dp[sp][i];//이걸구하면되는건가??
	}
	


	//이제 제일 큰거 구해야한다.
	cout << maxValue << endl;


	return 0;
}

/*

// 탐색을 따로 두면 메모리를 줄일 수 있다.

#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>



#define INF 1000000
#define N 1000

using namespace std;

typedef pair<int, int> P;
//N(1 <= N <= 1,000), M(1 <= M <= 10,000),

struct priority {//이걸왜 굳이 struct로 정의를 해야하는가..
bool operator()(P a, P b)
{
return a.second > b.second;
}
};


vector<P> v[N+2];//N개는 항상존재한다고 보고 나머지는 가변 배열로서 접근하기 위함

bool flag[N + 2];

int dp[N + 2];
int dp2[N + 2];

int maxValue;


int main(void)
{
//n 마을 , e 간선수 , 목표 sp

int n, e, sp;
scanf("%d %d %d", &n, &e, &sp);

int s, d, w;
s = d = w = 0;

for (int i = 1; i <=n; i++)
{
dp[i] = INF;
dp2[i] = INF;
}

for (int i = 0; i < e; i++)
{
scanf("%d %d %d", &s ,&d ,&w);
v[s].push_back(P(d, w));
}


//목표는 SP로 가는거고 가장 길게가는 거리를 구하여라.
//n개의 마을에서 열리는데 sp로 갔다오는데 제일 오래 걸리는 애의 소요 시간을 출력하라

priority_queue<P, vector<P>, priority>PQ;

PQ.push(P(sp, 0));
flag[sp] = 1; //자기 자신은 찾은거고 이제 자기 자신으로부터..
dp[sp] = 0;//자기 자신으로 가는건 0이다.

//sp로 부터 모든 방향으로의 값을 다 저장한다.
while (!PQ.empty())
{
auto select = PQ.top();
PQ.pop();
flag[select.first] = 1;

for (P p : v[select.first])
{
if (!flag[p.first])
{
if (dp[p.first] > dp[select.first] + p.second)
{
dp[p.first] = (dp[select.first] + p.second); //갱신
PQ.push(P(p.first, dp[p.first]));
}
}
}
}

//이제 집으로 돌아가는 경로는 모두 찾은 것이고

while (!PQ.empty())
PQ.pop();


for (int i = 1; i <= n; i++)
flag[i] = 0;

maxValue = 0;


//i 에서 sp에 대한 최단경로
for (int i = 1; i <= n; i++)
{
if (i == sp)
continue;

PQ.push(P(i, 0));
flag[i] = 1;
dp2[i] = 0;

while (!PQ.empty())
{
auto select = PQ.top();
PQ.pop();
flag[select.first] = 1;

//선택은 이부분에서 하는거다.이떄 결국 방무낳게 되니까.
if (select.first == sp)
{
if (maxValue < dp[i] + dp2[select.first])
maxValue = dp[i] + dp2[select.first];
break;
}

//POP해서 나오는게 선택된것이기 때문에 여기서 flag를 체크를해줘야 한다.


for (P p : v[select.first])
{
if (!flag[p.first])
{
if (dp2[p.first] > dp2[select.first] + p.second)
{
dp2[p.first] = (dp2[select.first] + p.second); //갱신
PQ.push(P(p.first, dp2[p.first]));
}
}
}
}
while (!PQ.empty())
PQ.pop();

for (int i = 1; i <=n; i++)
{
flag[i] = 0;
dp2[i] = INF;
}
}


//이제 제일 큰거 구해야한다.
cout << maxValue << endl;


return 0;
}

*/