
/*
���� : ���డ��
���� ��ȣ: 1976
��¥ : 160918
��Ÿ : union���ε�, ũ�罺Į�� �̿��ؼ� ���д�Ʈ�� ���ϰ��� ������ ��Ʈ�� ����
*/

#include<iostream>
#include<algorithm>

#define N 200
using namespace std;


class Edge
{
public:
	int u, v;
	Edge() : Edge(-1, -1) {}// default ������
	Edge(int u, int v) :u(u), v(v){}// defalut �Է�
};


int disjoint[N+2];

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


int main(void)
{
	int n, m;//���ü� 200, ���� ��ȹ�� ���� ���õ� M��

	cin >> n >> m;

	Edge *edges = new Edge[n*n+2];

	int input=0;
	int edgeCnt = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &input);

			if (input != 0)
			{
				Edge *e = new Edge(i, j);
				edges[edgeCnt] = *e;
				edgeCnt++;
			}
		}
	}

	fill(disjoint, disjoint+ N+2 , -1);

	int value = 0;
	int cnt = 1;

	//���д� Ʈ���� �����������. �׷��� <edgeCnt������!
	for (int i = 0;i<edgeCnt; i++)
	{
		Edge e = edges[i];

		if (mUnion(e.u, e.v))
		{
			if ((++cnt) >= n)
				break;
		}
	}

	//�̹� ���д� Ʈ���� ������� ����. ���д� Ʈ����� �ϱ� �׷��� ���յ��� ����� ������.
	int q;
	cin >> q;

	int root = mFind(q);
	bool res = true;

	for (int i = 0; i < m-1; i++)
	{
		scanf("%d", &q);
		//�θ� ���� Ȯ���Ѵ�.
		if (root != mFind(q)) {
			res = false;
			break;
		}
	}

	if (res)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}