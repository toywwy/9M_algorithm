/*
���� : �Ҽ����
���� ��ȣ: 1964
Ǯ�̹� : BFS
��¥ : 20
��Ÿ : �ִܰŸ��� ���ؾ��ؼ� DFS���� BFS�� �̿��ϵ��� ����.
�� test case�� ���� �� �Ҽ� ������ ��ȯ�� �ʿ��� �ּ� ȸ���� ����Ѵ�. �Ұ����� ��� Impossible�� ����Ѵ�.

BFS�� ������ ��� ���������� �߿��ѰͰ���.
���⼭�� ������ ���ڸ��� �ٲٴ� ��� �Ҽ��� �����̴�.

�������� ������ ��� ������ ..���� ī��Ʈ�� ��� ���� pair�� �̿��ؼ� �������.

*/

#include<iostream>
#include<string>
#include<queue>

using namespace std;

typedef pair<int, int> P;

bool check[10001];//������ 1000���� ~9999 �������Ѵ�.
bool visit[10001];
bool resFlag;
int res;
int to;
queue<P> q;

inline int mergeInt(int a1, int a2, int a3, int a4)
{
	return a1 * 1000 + a2 * 100 + a3 * 10 + a4;
}

inline void pushInt(int c, int cnt)
{
	if (c < 1000)
		return;

	if (!check[c] && !visit[c])
	{
		if (c == to)//end
		{
			res = cnt+1;
			resFlag = 1;
			visit[c] = 1;
			while (!q.empty())
				q.pop();
		}
		else
		{
			visit[c] = 1;
			q.push(P(c, cnt + 1));
		}
	}
}

int main(void)
{
	//�ϴ� �Ҽ��� ���ϰ� ��������.
	check[0] = check[1] = 1;
	check[2] = false;//�Ҽ��� �̰� false�� �����ϴ� ������ �� �����غ���

	for (int i = 2; i <= 10000; i++)
	{
		if (check[i]) continue; //�Ҽ� �ƴϸ� �н�
		for (int j = 2; i*j <= 10000; j++) check[i*j] = 1; //�Ҽ��� �ƴ�.
	}
	//�Ҽ� ���ϱ� �Ϸ�

	int itr;
	cin >> itr;

	for (int i = 0; i < itr; i++)
	{
		int from;//to������
		cin >> from >> to;

		q.push(P(from, 0));
		visit[from] = 1;

		int a[4], c;

		if (from == to)
		{
			cout << 0 << endl;
			continue;
		}
		res = 0;
		resFlag = false;

		fill(visit + 999, visit + 9999, 0);


		while (!q.empty())
		{
			P ps = q.front(); q.pop();
			int p = ps.first;

			a[0] = p / 1000;
			p = p % 1000;

			a[1] = p / 100;
			p = p % 100;

			a[2] = p / 10;
			p = p % 10;

			a[3] = p;

			for (int j = 0; j <= 9; j++) //�� ����
			{
				c = mergeInt(j, a[1], a[2], a[3]);//õ���ڸ�
				pushInt(c, ps.second);

				c = mergeInt(a[0], j, a[2], a[3]);//�����ڸ�
				pushInt(c, ps.second);

				c = mergeInt(a[0], a[1], j, a[3]);//�����ڸ�
				pushInt(c, ps.second);

				c = mergeInt(a[0], a[1], a[2], j);//�����ڸ�
				pushInt(c, ps.second);
			}
		}

		if (visit[to])//���信�湮�ߴ�.
			cout << res << endl;
		else
			cout << "Impossible" << endl;

	}
	return 0;
}