/*

*/

#include<iostream>
#include<cstdio>

#define N 100
using namespace std;

class Node {
public:
	int to;
	Node * prev;
}nodes[10000];//������ ����������.

Node *ids[N];// ��� ������ ���� �ٸ���.

int idx, SIZE;
Node* newNode()//������ Ȯ����ѳ�����.
{
	return &nodes[idx++];
}

void addNode(int from, int to)
{

	Node *prevNode = 0;
	Node *cur = ids[from];
	bool chk = false;
	while (cur != 0)
	{
		if (to < cur->to) break;

		prevNode = cur;//�߰� ���Խ� �������� �̾��ֱ�����.
		cur = cur->prev;

		chk = true;//��尡 tail�� ���ԵǴ� ���� �ƴ϶�. �߰��� ���� �ȴٴ� �ǹ��̴�.
		//cur �����Ͱ� ����������.
	}

	Node * p = newNode();
	p->to = to;

	if (chk == false)//����� �Ϲݻ���
	{
		p->prev = ids[from];
		ids[from] = p; //���ο� ��尡 tail�� ��ȭ�ȴ�.
	}
	else //�߰� ����
	{
		prevNode->prev = p;
		p->prev = cur;
		//tail�� ������ �ʴ´� �߰��� ���ԵǱ⶧��, ��� ���� ���� �̾�����Ѵ�.
	}
}

int main(void)
{

	int from, to;
	for (int i = 0; i < 20; i++)
	{
		cin >> from >> to;
		addNode(from, to);
		addNode(to, from);
	}

	for (int i = 1; i < 10; i++)
	{
		Node * cur = ids[i];
		cout << i << " : ";
		while (cur != 0)
		{
			cout << cur->to << " ";
			cur = cur->prev;
		}
		cout << endl;
	}




	return 0;
}