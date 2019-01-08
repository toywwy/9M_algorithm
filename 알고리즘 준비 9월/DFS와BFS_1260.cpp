/*
���� : DFS�� BFS
���� ��ȣ: 1260
Ǯ�̹� : DFS, BFS
��¥ : 18.12.08
��Ÿ : DFS���, BFS���
STL �Ⱦ��� ¥����.

*/

#include<iostream>


using namespace std;


class Node
{
public:
	int v;
	Node *prev;//prev�� ���� ���� ó�����̷���

	Node() { v = 0, prev = 0; }
	Node(int _v) {
		v = _v;
		prev = 0;
	}
};


int N, M, V;

//ù° �ٿ� ������ ���� N(1 �� N �� 1,000), ������ ���� M(1 �� M �� 10,000), 

Node *ids[1002];//���ؿ����� �̷��� �����Ҵ��ϴ°� ������ .. �Ҹ��ϱ��ϴ�..


void addNode(int a, int b)
{
	Node * p = new Node(b);
	Node * cur = ids[a];

	while (true)//�ִ��� �������°� ���� ����.
	{
		int bV = cur->v;//����ó���� 0���� �Ǿ��־ ���� X ��Ȳ������ �ʱ�ȭ�� ���Ѱ� �ٲ�� �ҵ�
		Node *bCur = cur;
		cur = cur->prev;

		if (cur == 0 || p->v < cur->v)
		{
			bCur->prev = p;
			p->prev = cur;
			break;
		}
	}
}


void input()
{
	cin >> N >> M >> V;//����,����,����

	for (int i = 1; i <= N; i++)
	{
		ids[i] = new Node(0);//������ ó������ �׳� �������� ������ �ϸ� �Ǵµ� ���⿡���� dummy�� �������� �����ߴ�.
		//���� �۰� �������� �̵ڿ� �׾ư��� ��
	}

	int a, b;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;

		addNode(a, b);
		addNode(b, a);
	}
}

bool visit[1002];

void dfs(int a)
{
	cout << a << ' ';
	Node * cur = ids[a]->prev;

	while (cur != 0)
	{
		if (visit[cur->v] == false)
		{
			visit[cur->v] = true;
			dfs(cur->v);
		}
		cur = cur->prev;
	}
}


int q[10002];
int front;
int rear;

void bfs(int a)
{
	visit[V] = true;
	q[rear++] = V;

	while (front != rear)
	{
		int value = q[front++];//pop
		cout << value << ' ';

		Node *cur = ids[value]->prev;
		while (cur != 0)
		{
			if (visit[cur->v] == false)
			{
				visit[cur->v] = true;
				q[rear++] = cur->v;
			}
			cur = cur->prev;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();

	visit[V] = true;
	dfs(V);
	cout << endl;

	for (int i = 0; i < N + 1; i++) visit[i] = 0;

	bfs(V);
	cout << endl;

	return 0;
}
