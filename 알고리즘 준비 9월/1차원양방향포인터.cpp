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
		p->to = i+1;

		Node *b = tail->prev;//이전꺼 하나 생성해서 이어주면 어렵지 않다.
							//sorted로 구현하기 위해서는 삽입 위치만 정해주면된다.
		b->next = p;
		p->prev = b;
		p->next = tail;
		tail->prev = p;

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