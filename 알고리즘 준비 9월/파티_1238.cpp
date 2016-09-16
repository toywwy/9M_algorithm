
/*
���� : ��Ƽ
���� ��ȣ: 1238
Ǯ�̹� : ���ͽ�Ʈ��
��¥ : 160916
��Ÿ : ���ͽ�Ʈ�� �̿��� ������ �ذ�, �迭�� ������� �ʰ� �켱���� ť�� �̿��Ѵ�.
�켱���� ť�� �̿��ҽÿ� ������ �����ϴ� �κ��� pop �Ǵ� �κ��̶�°� ������ �ȵȴ�.
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

struct priority {//�̰ɿ� ���� struct�� ���Ǹ� �ؾ��ϴ°�..
	bool operator()(P a, P b)
	{
		return a.second > b.second;
	}
};


vector<P> v[N+2];//N���� �׻������Ѵٰ� ���� �������� ���� �迭�μ� �����ϱ� ����

bool flag[N + 2];

int dp[N + 2][N+2];

int maxValue;

int main(void)
{
	//n ���� , e ������ , ��ǥ sp

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


	//��ǥ�� SP�� ���°Ű� ���� ��԰��� �Ÿ��� ���Ͽ���.
	//n���� �������� �����µ� sp�� ���ٿ��µ� ���� ���� �ɸ��� ���� �ҿ� �ð��� ����϶�

	priority_queue<P, vector<P>, priority>PQ;

	
	//sp�� ���� ��� ���������� ���� �� �����Ѵ�.
	for(int i = 1;i<=n;i++)
	{

		PQ.push(P(i, 0));
		flag[i] = 1; //�ڱ� �ڽ��� ã���Ű� ���� �ڱ� �ڽ����κ���..
		dp[i][i] = 0;//�ڱ� �ڽ����� ���°� 0�̴�.


		while (!PQ.empty())
		{
			auto select = PQ.top();
			PQ.pop();
			flag[select.first] = 1;
			if (i!=sp && select.first == sp)
			{//���ͽ�Ʈ�󿡼� �̷��� ���ϴ� ��ǥ�� ã������ �ű⼭ break; ���ִ°� �ð��� ��û�� ������ ��ģ��.
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
						dp[i][p.first] = (dp[i][select.first] + p.second); //����
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
		//sp�� �������̴�. �Ѹ����
		if( maxValue <dp[i][sp] + dp[sp][i])
			maxValue =dp[i][sp] + dp[sp][i];//�̰ɱ��ϸ�Ǵ°ǰ�??
	}
	


	//���� ���� ū�� ���ؾ��Ѵ�.
	cout << maxValue << endl;


	return 0;
}

/*

// Ž���� ���� �θ� �޸𸮸� ���� �� �ִ�.

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

struct priority {//�̰ɿ� ���� struct�� ���Ǹ� �ؾ��ϴ°�..
bool operator()(P a, P b)
{
return a.second > b.second;
}
};


vector<P> v[N+2];//N���� �׻������Ѵٰ� ���� �������� ���� �迭�μ� �����ϱ� ����

bool flag[N + 2];

int dp[N + 2];
int dp2[N + 2];

int maxValue;


int main(void)
{
//n ���� , e ������ , ��ǥ sp

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


//��ǥ�� SP�� ���°Ű� ���� ��԰��� �Ÿ��� ���Ͽ���.
//n���� �������� �����µ� sp�� ���ٿ��µ� ���� ���� �ɸ��� ���� �ҿ� �ð��� ����϶�

priority_queue<P, vector<P>, priority>PQ;

PQ.push(P(sp, 0));
flag[sp] = 1; //�ڱ� �ڽ��� ã���Ű� ���� �ڱ� �ڽ����κ���..
dp[sp] = 0;//�ڱ� �ڽ����� ���°� 0�̴�.

//sp�� ���� ��� ���������� ���� �� �����Ѵ�.
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
dp[p.first] = (dp[select.first] + p.second); //����
PQ.push(P(p.first, dp[p.first]));
}
}
}
}

//���� ������ ���ư��� ��δ� ��� ã�� ���̰�

while (!PQ.empty())
PQ.pop();


for (int i = 1; i <= n; i++)
flag[i] = 0;

maxValue = 0;


//i ���� sp�� ���� �ִܰ��
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

//������ �̺κп��� �ϴ°Ŵ�.�̋� �ᱹ �湫���� �Ǵϱ�.
if (select.first == sp)
{
if (maxValue < dp[i] + dp2[select.first])
maxValue = dp[i] + dp2[select.first];
break;
}

//POP�ؼ� �����°� ���õȰ��̱� ������ ���⼭ flag�� üũ������� �Ѵ�.


for (P p : v[select.first])
{
if (!flag[p.first])
{
if (dp2[p.first] > dp2[select.first] + p.second)
{
dp2[p.first] = (dp2[select.first] + p.second); //����
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


//���� ���� ū�� ���ؾ��Ѵ�.
cout << maxValue << endl;


return 0;
}

*/