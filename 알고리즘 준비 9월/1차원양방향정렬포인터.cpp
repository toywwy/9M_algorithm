#include<iostream>

using namespace std;

class Node {
public:
	int to;
	Node * prev;
	Node * next;
}nodes[1000];


int idx = 0;
Node * newNode()
{
	return &nodes[idx++];
}

Node *head;
Node *tail;
int nodeSize;
int main(void)
{
	head = newNode();
	tail = newNode();

	head->next = tail;
	tail->prev = head;

	int n;
	for (int i = 0; i < 10; i++)
	{
		Node * p = newNode();
		cin >> n;
		p->to = n;


		Node *cur = head->next;
		while (cur->next != 0)
		{
			if (n < cur->to) break; //�۾����¼���.
			cur = cur->next;
		}



		Node *b = cur->prev;//������ �ϳ� �����ؼ� �̾��ָ� ����� �ʴ�.
							//sorted�� �����ϱ� ���ؼ��� ���� ��ġ�� �����ָ�ȴ�.
		b->next = p;
		p->prev = b;
		p->next = cur;
		cur->prev = p;

		nodeSize++;
	}


	Node * cur = head->next;
	while (cur->next != 0)
	{
		cout << cur->to << endl;
		cur = cur->next;
	}
	cout << endl;



	return 0;
}