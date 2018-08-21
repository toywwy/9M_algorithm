/*
���� : ǳ���Ͷ߸���
���� ��ȣ: 2346
Ǯ�̹� : LinkedList
��¥ : 20180821
��Ÿ : ȯ�� ��ũ�� ����Ʈ
CircledLinkedList
Mod ������ ���ص��ȴ�.


*/

#include<iostream>
using namespace std;

int N;

class Node {
public :
	int v;
	int idx;
	Node * next;
	Node * prev;
};

Node *ini;

int nodeCnt;
int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N;

	ini = new Node();
	ini->v = -1;
	Node *cur = ini;

	for (int i = 0; i < N; i++)
	{
		Node * p = new Node();
		cin >> p->v;
		p->idx = i + 1;

		cur->next = p;
		p->prev = cur;

		p->next = ini;
		ini->prev = p;

		cur = p;
	}
	nodeCnt = N;

	cur = ini->next;//����

	while (1)
	{
		cout << cur->idx << " ";
		int value = cur->v;
		Node * before = cur->prev;
		Node * after = cur->next;
		before->next = after;
		after->prev = before;

		nodeCnt -= 1;

		if (nodeCnt < 1) break;

		if (value > 0)
		{
			cur = before;//����ĭ���� 1�̴�.
			for (int i = 0; i < value; i++) {
				cur = cur->next;
				if (cur == ini) cur = cur->next;
			}
		}
		else // �����ϰ��
		{
			cur = after;

			for (int i = 0; i < -value; i++) {
				cur = cur->prev;
				if (cur == ini) cur = cur->prev;
			}
		}
	}


	return 0;
}
