/*

DFS �޸������̼� ����

���� :		����
���� ��ȣ:	1613
Ǯ�̹� :		DFS, �޸������̼�
��¥ :		161011
��Ÿ :		������..
DFS�� ĳ���� ��µ� �����ߴ�.
�ֳ��ϸ� 

1->2->3->4->6 ���� ĳ�����ߴ�. 

x->1 ->6 ���εǴ°��̴�.

but 
1->2->3->4->6->7
x->7�� ã�ư���
[1][7] �� ���� Ž���� �ȵƱ� ������ ������ ���ߵ�.
�ᱹ �ٽ� �� ��θ� Ž���ϸ鼭 ���� ������ �߻�...

+ �׸��� �߰��ؾ��ϴ°� �־���. 

-1 ã������ ��ã�� ��쵵 -1�� �����س����Ѵ�.

�̺κ��� �ذ� �ϸ� ... ��¥ �� �� �ִ� �ϵ� ������ ������ 
*/


#include<cstdio>
#include<vector>
#include<queue>

#define N 400
using namespace std;

vector<int> v[N + 2];
vector<int> q;

bool dp[N + 2][N + 2];

bool resFlag;
int target = 0;
void recur(int x)
{
	for (int k : v[x])
	{
		for (int d : q) dp[d][k] |= 1;//�����̴� �ƴѴ� ��� ��������.

		if (k != target)
		{
			if (dp[k][target]) {
				resFlag = 1;
				break;
			}

			q.push_back(k);
			recur(k);
			q.pop_back();
		}
		else {
			resFlag = 1;
			break;
		}
	}
	if (resFlag)
		return;
}


int main(void)
{
	int n, m, a, b, qCnt;
	scanf("%d %d", &n, &m);

	while (m--)
	{
		scanf("%d %d", &a, &b);
		v[a].push_back(b);//�Ʒ��� �������°Ŵ�.
	}

	scanf("%d", &qCnt);
	while (qCnt--)
	{
		scanf("%d %d", &a, &b);
		//a->b�� ���°� ã����� dp�� ������ ����.
		resFlag = 0;

		target = b;
		q.push_back(a);
		recur(a);
		q.pop_back();

		if (resFlag)
		{
			printf("-1\n");
			continue;
		}
		else
		{
			target = a;
			q.push_back(b);
			recur(b);
			q.pop_back();

			if (resFlag)
				printf("1\n");
			else
				printf("0\n");
		}
	}

	return 0;
}
