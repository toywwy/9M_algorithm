#include <stdio.h>
#include <queue>
using namespace std;

int N;

int x1[1111], x2[1111], y_1[1111], y2[1111];
bool visit[1111];

bool connected(int rec, int cmp)
{
	if ((x1[rec] <= x2[cmp] && x2[rec] >= x1[cmp] && y_1[rec] <= y2[cmp] && y2[rec] >= y_1[cmp]) &&    // cmp�簢���� rec�簢���� ��輱 ���� �ȿ� ������
		!(x1[rec] < x1[cmp] && x2[rec] > x2[cmp] && y_1[rec] < y_1[cmp] && y2[rec] > y2[cmp]) &&      // cmp�簢���� rec�簢�� �ȿ� ���� �ʰ�
		!(x1[rec] > x1[cmp] && x2[rec] < x2[cmp] && y_1[rec] > y_1[cmp] && y2[rec] < y2[cmp])         // cmp�簢���� rec�簢�� �ۿ� ���� �������� return true
		) return true;

	return false;
}

void BFS(int rec_num)
{
	queue<int> q;
	q.push(rec_num);
	visit[rec_num] = true;

	while (!q.empty())
	{
		int here = q.front();
		q.pop();
		for (int i = 0; i <= N; i++)
		{
			if (!visit[i] && connected(here, i))
			{
				visit[i] = true;
				q.push(i);
			}
		}
	}
}


int main()
{
	int ans = 0;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) scanf("%d %d %d %d", &x1[i], &y_1[i], &x2[i], &y2[i]);

	for (int i = 0; i <= N; i++)
	{
		if (!visit[i])
		{
			ans++;
			BFS(i);
		}
	}

	// ������ Ž���� ���� ��� ������ ������ �ִ� �����̹Ƿ�, PU�� ����� ����.(-1)
	printf("%d\n", ans - 1);

	return 0;
}