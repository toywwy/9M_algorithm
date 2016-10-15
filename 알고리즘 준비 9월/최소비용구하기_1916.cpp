/*
���� :		�ּҺ�뱸�ϱ�
���� ��ȣ:	1916
Ǯ�̹� :		���ͽ�Ʈ��
��¥ :		161015
��Ÿ :		priority Queue�� �̿��ؼ� �����ߴ�.

���������ٰ� ���� pair�� second���ٰ� dp�����־ ó�����ҰŸ� ó�����ͳ־��ְ�
�ƴ϶�� 
dp[p.first] �̷��� ���ϴ°� �����ϴ�.

pq.push(P(s, 0));//�׷��� �׳� �̷����ϸ� ������

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

//n(1��n��1,000)���� ���ð� �ִ�. �׸��� �� ���ÿ��� ����Ͽ� �ٸ� ���ÿ� �����ϴ� m(1��m��100,000)
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
	cin >> n >> m;//��������

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

	dp[s] = 0;//�ڱ��ڽź��� ����ϱ⋚���� �� �ʿ�

	pq.push(P(s, 0)); //ó���� �ְ� �ص� ������... �߻����ؼ� 
					  //s���� ���� e�� ���°Ŵ�.
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
				if (dp[a.first] > dp[p.first] + a.second)//�̶��� �����ϴ°� ����.
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
