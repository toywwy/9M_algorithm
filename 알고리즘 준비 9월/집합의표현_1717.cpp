/*
���� : ������ǥ��
���� ��ȣ: 1717
Ǯ�̹� : Disjoint-set, union-find(��ġ�� ã���ϴ°�)
��¥ : 160916
��Ÿ : union-find�� �ذ�
disjoint-set
�Ѹ���� �迭�� �ε��� ó��������Ѵ�. �ᱹ�� ��͸� Ÿ�� ... ��Ʈ�� �ٴٸ����� ����� ���̴�.
�׸��� union�� �� �� ������ �̾��ִ� ���̴�.

���� : http://kks227.blog.me/220791837179?Redirect=Log&from=postView

*/

#include<iostream>
#include<vector>

using namespace std;

int dis[1000002];

int find(int x)
{
	if (dis[x] < 0) return x;
	else return dis[x] = find(dis[x]); //�� �θ� x�� ������ش�.
}

bool merge(int a, int b)
{
	a = find(a), b = find(b);
	if (a == b) return false;
	dis[b] = a; return true;
}

int main(void)
{
	int n, m, a, b, com;;
	cin >> n >> m;

	fill(dis, dis + n + 1, -1);
	while (m--)
	{
		scanf("%d %d %d", &com, &a, &b);

		if (com)// CHECK
		{
			if (find(a) == find(b)) printf("YES\n");
			else printf("NO\n");
		}
		else merge(a, b);// Union
	}

	return 0;
}