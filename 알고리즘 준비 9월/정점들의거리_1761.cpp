/*
���� : �������� �Ÿ�
���� ��ȣ: 1761
Ǯ�̹� :
��¥ : 18.07.31
��Ÿ : 

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


int dp[40002];//root ���� ���� �Ÿ��� �˸� ����ؼ� ���� �� �ִ�.
int level[40002];
P edge[40002];//���� //pair�� �ؼ� ..�ϸ� ��������??��������� Ž���̾ƴ϶�.

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

	//�ߺ� �Է��� ������ֳ�??

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
	//�ڽ��� �Է������� ���� ������? �ϴ°� ȿ�����̰���??/
	//���� �θ𿡼� 

	//tree ������ input �޴´�.
	for (int i = 1; i < N-1; i++)
	{
		cin >> a >> b >> c;
		arr[a].push_back(P(b, c));
		arr[b].push_back(P(a, c));

		if (visit[a] == 0)//Ʈ���� ������ �ϳ��� ������ ����Ǿ��ֵ�.
		{//b�� �����Ѵ�.
			P p(b, c);
			edge[a] = p;
			level[a] = level[b] + 1;
		}
		else {//Ȥ�� parent[b]�� 0�̶��
			//a�� �����Ѵ� a�� ������.
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
	//��� ������ ������ up up �ϸ鼭 �ľ�

	cin >> M;
	int input1, input2,res;
	for (int i = 0; i < M; i++)
	{
		cin >> input1 >> input2;
		a = input1;
		b = input2;

		while (true)
		{
			if (level[a] > level[b]) //ū���� �ö󰡼� �۾������Ѵ�.
			{
				//to == parent
				a = edge[a].to;
				
			}
			else if (level[a] < level[b])
			{
				b = edge[b].to;
			}
			else //����.
			{
				while(a!= b) //�ڱ� �ڽ� ���� �ö󰣴�. �θ� �ڽ��ΰͰ� ����� �ٸ��� ��Ÿ����.
				{
					//���������� ����.
					a = edge[a].to;
					b = edge[b].to;
				}
				//���� ���� ���� �θ� ��������. root ������ �Ÿ��� �ι� ���� �ȴ�, ��Ʈ��� 0
				res = dp[input1] + dp[input2] - dp[a] - dp[a];
				
				break;
			}
		}

		cout << res << endl;

	}

	return 0;
}
