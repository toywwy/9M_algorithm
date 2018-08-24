/*
���� : �����۽� ����
���� ��ȣ: 1158
Ǯ�̹� : Linked List ��ũ�� ����Ʈ
��¥ : 18.08.24
��Ÿ :

Dummy�� ������ �ʰ� ������ �غ���,
ȯ�� ť�� ���� Dummy�� skip�ϴ� �κ��� �������� �����ϴ�.
Dummy ���� �����ϴ� ���..
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int N, M;


class Node {
public:
	int idx;
	Node * next;
	Node * prev;
};


int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M;

	Node *ini = new Node();
	ini->idx = 1;
	
	Node * cur = ini;

	for (int i = 1; i < N; i++)
	{
		Node *p = new Node();
		p->idx = i + 1;
		cur->next = p;
		p->prev = cur;
		cur = p;
	}
	
	//Head�� ����
	ini->prev = cur;
	cur->next = ini;

	//���ۺκ�
	cur = ini->prev;

	int C, nodeCnt = N;

	cout << "<";
	while (1)
	{
		if (nodeCnt < 2) break;
		C = M%nodeCnt;
		for (int i = 0; i < C; i++) cur = cur->next;

		cout << cur->idx << ", ";

		Node * before = cur->prev;
		Node * after = cur->next;
		before->next = after;
		after->prev = before;
		cur = before;

		nodeCnt -= 1;

	}
	cout << cur->idx << ">";

	return 0;
}
