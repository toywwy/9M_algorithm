/*
문제 : 정점들의 거리
문제 번호: 1761
풀이법 :
날짜 : 18.07.31
기타 : 

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;


int N, M;

class P {
public:
	int to;
	int v;
	P() {  }
	P(int _p, int _v) :to(_p), v(_v)
	{}
};


int dp[40002];//root 에서 부터 거리를 알면 계산해서 구할 수 있다.
int level[40002];
P edge[40002];//간선 //pair로 해서 ..하면 느릴려나??상관없을듯 탐색이아니라.

vector<P> arr[40002];
bool visit[40002];

void recur(int node,int v)
{
	for (P p : arr[node])
	{
		if (visit[p.to] == 0)
		{
			visit[p.to] = 1;
			dp[p.to] = v + p.v;
			recur(p.to, dp[p.to]);
		}
	}
}


int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0);

	//중복 입력이 생길수있나??

	cin >> N;

	int a, b, c,root;
	cin >> a >> b >> c;
	arr[a].push_back(P(b, c));
	arr[b].push_back(P(a, c));

	root = a;
	P p(a, c);
	edge[b] = p;
	visit[a] = visit[b] = true;
	level[b] = 1;
	//자식을 입력했을때 값이 나오게? 하는게 효과적이겠지??/
	//값은 부모에서 

	//tree 구조로 input 받는다.
	for (int i = 1; i < N-1; i++)
	{
		cin >> a >> b >> c;
		arr[a].push_back(P(b, c));
		arr[b].push_back(P(a, c));

		if (visit[a] == 0)//트리라 둘중의 하나는 무조건 연결되어있따.
		{//b는 존재한다.
			P p(b, c);
			edge[a] = p;
			level[a] = level[b] + 1;
		}
		else {//혹은 parent[b]가 0이라면
			//a는 존재한다 a에 붙힌다.
			P p(a, c);
			edge[b] = p;
			level[b] = level[a] + 1;
		}
		visit[a] = visit[b] = true;
	}

	fill(visit, visit + N+1, 0);

	//dp
	visit[root] = 1;
	recur(root,0);

	fill(visit, visit + N+1, 0);
	//계산 레벨이 같은지 up up 하면서 파악

	cin >> M;
	int input1, input2,res;
	for (int i = 0; i < M; i++)
	{
		cin >> input1 >> input2;
		a = input1;
		b = input2;

		while (true)
		{
			if (level[a] > level[b]) //큰쪽이 올라가서 작아져야한다.
			{
				//to == parent
				a = edge[a].to;
				
			}
			else if (level[a] < level[b])
			{
				b = edge[b].to;
			}
			else //같다.
			{
				while(a!= b) //자기 자신 까지 올라간다. 부모가 자신인것과 결과가 다르게 나타난다.
				{
					//같을때까지 증가.
					a = edge[a].to;
					b = edge[b].to;
				}
				//여기 까지 오면 부모가 같아진다. root 에서의 거리가 두번 포함 된다, 루트라면 0
				res = dp[input1] + dp[input2] - dp[a] - dp[a];
				
				break;
			}
		}

		cout << res << endl;

	}

	return 0;
}
