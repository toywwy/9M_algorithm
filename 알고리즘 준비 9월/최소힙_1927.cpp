
/*

���� : �ּ���
���� ��ȣ: 1927
Ǯ�̹� : ��
��¥ : 160919
��Ÿ : priority�� �����ϱ� ���� �� ���� �����ϱ�.

*/

#include<iostream>
#include<queue>
#include<functional>

typedef unsigned int uint;

using namespace std;

int main(void)
{
	priority_queue<uint, vector<uint>, greater<uint>> PQ;

	uint n;
	cin >> n;

	int m = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &m);
		if (m == 0)
		{
			if (PQ.empty())
				printf("0\n");
			else
			{
				printf("%d\n", PQ.top());
				PQ.pop();
			}
		}
		else
		{
			PQ.push(m);
		}
	}

	return 0;
}