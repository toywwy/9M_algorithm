/*
���� : Ʈ��������
���� ��ȣ: 1967
Ǯ�̹� : BFS
��¥ : 161010
��Ÿ : ������ ��Ʈ ��Ʈ�� �ö󰡴� �͸� BFS�� ���ؼ� �������ߴ�.
�׸��� ������ ��忡���� ������ ��� �����ϰ� �Ǵµ� �̶� �ڽĳ�尡 � ��������� �˾ƾ��Ѵ�.

�׷��� ���߿� ��� ��带 Ž���ϸ鼭 ���� ���Ҷ� ���δٸ� �ڽĳ���� ���� ū���� �� ��带 �߽������� �������̴�.

*/


#include<iostream>
#include<vector>
#include<queue>

using namespace std;
#define N 10000


typedef pair<int, int> P;

bool flag[N + 2];
vector<P> v[N + 2];
vector<P> res[N + 2];//�װ��� ��ǥ <��, ��� �Դ���> �� �ֵ�������.

int main(void)
{
	int n;
	cin >> n;

	int a, b, c;
	for (int i = 0; i < n - 1; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		v[b].push_back(P(a, c));

		flag[a] = 1;
	}

	queue<P> q;

	for (int i = 1; i <= n; i++)
		if (!flag[i])//��������̴�. ������忡�� ���� ���� ��� ���ϸ�ȴ�.
			q.push(P(i, 0));


	while (!q.empty())
	{
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			P p = q.front(); q.pop();

			for (P next : v[p.first]) {
				res[next.first].push_back(P((p.second + next.second), p.first));

				q.push(P(next.first, (p.second + next.second)));
			}

		}
	}

	int mMax = 0, m1, m2, mP;
	for (int i = 1; i <= n; i++)
	{
		if (flag[i])
		{
			m1 = m2 = mP = 0;
			for (P r : res[i])
				if (m1 < r.first)
				{
					m1 = r.first;
					mP = r.second;
				}

			for (P r : res[i])
				if (r.second != mP)
					m2 = max(m2, r.first);

			mMax = max(mMax, (m1 + m2));
		}
	}

	cout << mMax << endl;

	return 0;
}