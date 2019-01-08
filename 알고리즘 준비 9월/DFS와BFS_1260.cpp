/*
문제 : DFS와 BFS
문제 번호: 1260
풀이법 : DFS, BFS
날짜 : 18.12.08
기타 : DFS출력, BFS출력
STL 안쓰고 짜보자.

*/

#include<iostream>


using namespace std;


class Node
{
public:
	int v;
	Node *prev;//prev만 쓰는 순간 처음끝이런거

	Node() { v = 0, prev = 0; }
	Node(int _v) {
		v = _v;
		prev = 0;
	}
};


int N, M, V;

//첫째 줄에 정점의 개수 N(1 ≤ N ≤ 1,000), 간선의 개수 M(1 ≤ M ≤ 10,000), 

Node *ids[1002];//백준에서는 이렇게 동적할당하는거 무조건 .. 불리하긴하다..


void addNode(int a, int b)
{
	Node * p = new Node(b);
	Node * cur = ids[a];

	while (true)//최대한 덧붙히는거 없이 가자.
	{
		int bV = cur->v;//제일처음꺼 0으로 되어있어서 문제 X 상황에따라 초기화에 대한거 바꿔야 할듯
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
	cin >> N >> M >> V;//정점,간선,시작

	for (int i = 1; i <= N; i++)
	{
		ids[i] = new Node(0);//원래는 처음꺼는 그냥 껍데기라고 생각을 하면 되는데 여기에서는 dummy로 만들어놓고 진행했다.
		//제일 작게 만들어놓고 이뒤에 쌓아가는 것
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
