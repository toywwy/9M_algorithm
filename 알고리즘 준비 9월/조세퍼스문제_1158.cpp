/*
���� : �����۽� ����
���� ��ȣ: 1158
Ǯ�̹� : Linked List ��ũ�� ����Ʈ
��¥ : 18.08.24
��Ÿ :

Dummy�� �־ �����ϴ¹ٶ��� ����ó���� �ؾ��ϴ� �κ��� ����� ...
ini�� ��� pass�� ���־���ϴ� �κ��� �����.
Dummy�� ������ �ʰ� ȯ�� ť�� �����Ѵٸ�?

*/

#include<iostream>
using namespace std;

int N,M;

class Node {
public:
	int idx;
	Node * next;
	Node * prev;
};

Node *ini;

int nodeCnt;
int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M;

	ini = new Node();
	ini->idx = -1;
	Node *cur = ini;


	for (int i = 0; i < N; i++)
	{
		Node * p = new Node();
		p->idx = i + 1;

		cur->next = p;
		p->prev = cur;

		p->next = ini;
		ini->prev = p;

		cur = p;
	}
	nodeCnt = N;

	cur = ini->prev;//����
	int C = 0;
	cout << "<";
	while (1)
	{
		if (nodeCnt < 2) break;

		C = M%nodeCnt;

		for (int i = 0; i < C; i++) {
			cur = cur->next;
			if (cur == ini) cur = cur->next;
		}

		cout << cur->idx << ", ";
		Node * before = cur->prev;
		Node * after = cur->next;
		before->next = after;
		after->prev = before;
		
		//before�� �����ѰŴϱ�. prev���ؾ��Ѵ�.
		if (before == ini) before = before->prev;
		cur = before;

		nodeCnt -= 1;

	}
	cout <<cur->idx<< ">";

	return 0;
}