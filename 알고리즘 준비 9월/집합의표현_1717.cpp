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
#include<algorithm>

using namespace std;

int *disjoint;

int mFind(int a)
{
	if (disjoint[a] < 0)//-1 �̶�� ��𿡵� �Ҽ��� �Ȱ� �ƴϴϱ�.
		return a;//�ڱ� �ڽ��� ��Ʈ��.
	else
		return disjoint[a] = mFind(disjoint[a]);
		//�̷� ������ �ϴ� ������ ���߿� �ٷ� ��Ʈ�� ã���� �ְ� �̾� ���°Ŵ�. 
		//���� ��͸� ��� Ÿ�� ���°� �ƴ϶� �ٷ� ã�ư��� �ֵ���
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
	int n, q; //n ���� 1000000, q ���� 100000

	cin >> n >> q;
	disjoint = new int[n + 1];

	fill(disjoint, disjoint + n + 1, -1);// ���� �ε����� ���� ���ϱ� ������ -1�� �ʱ�ȭ

	//���μ����� ����� ����...
	//find�� union�� �������.

	int command,el1,el2;

	for (int i = 0; i < q; i++)
	{
		scanf("%d %d %d", &command, &el1, &el2);

		if (command==1) // ã�ƶ� mFind
		{
			if (mFind(el1) == mFind(el2))
				printf("yes\n");
			else
				printf("no\n");
		}else//���Ķ� mUnion
		{
			mUnion(el1, el2);
		}
	}
	//����� yes no�� ����Ѵ�.

	return 0;
}