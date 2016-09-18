/*
���д�Ʈ�� ũ�罺Į ���Ͽ����ε�
disjoint set ���μ� ����
union find
*/


#include<iostream>
#include<algorithm>

#define N 1000
#define LINE 100000
using namespace std;


class Edge
{
public:
	int u,v,w;
	Edge() : Edge(-1,-1,0) {}// default ������
	Edge(int u, int v, int w) :u(u), v(v), w(w) {}//defalut �Է�
	bool operator<(Edge e) { return w < e.w; }
};


int disjoint[1002];

int mFind(int a)
{
	if (disjoint[a] < 0)
		return a;
	else
		return disjoint[a] = mFind(disjoint[a]);
}

bool mUnion(int a, int b)
{
	int _a = mFind(a);
	int _b = mFind(b);

	if (_a == _b)
		return false;

	disjoint[_b] = _a;
	return true;
}


//���� ���� ���� union find ����Ѵ�.
 
int main(void)
{

	int n,m;//��ǻ�ͼ� 1000 , ������ ���Ǽ� 100000
	cin >> n >> m;

	Edge *edges = new Edge[m];

	int u, v, w;
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &u, &v, &w);
		Edge *e = new Edge(u, v, w);
		edges[i] = *e;
	}

	sort(edges, edges + m); //�̷��� �ϸ� w�� ���ؼ� ������ �ȴ� �ϴ�.
	
	fill(disjoint, (disjoint + N + 2),-1);
	//��� ��ǻ�͸� �ϳ��� �������� �����ȴ�. ũ�罺Į
	
	//���� ���� ���� ���� �Ұ���


	int value = 0;
	int cnt = 1;

	for (int i = 0;; i++)//���⿡�� i<m�� ���ִ°� ���ΰ� ������ �񱳿����� ���ش�.
	{
		//ó���� ���°� ���տ� �ִ´�..
		Edge e = edges[i];
		if (mUnion(e.u, e.v))
		{
			value += e.w;
			cnt++;

			if (cnt >= n)
				break;
		}

	}

	cout << value << endl;

	return 0;
}