#include<iostream>
#include<cstdio>

using namespace std;

class Node{
public:
	int n;
	Node *prev;
}nodes[1000];

int idx;


/* //얘는 되는데 .. 아래 에는 안된다. 주소값으로 참조 하려고해도..
Node* newNode()
{
	return &nodes[idx++];
}
*/

Node newNode()
{
	return nodes[idx++];
}

Node *tail;
int main(void)
{
	for (int i = 0; i < 10; i++)
	{

		Node *p = &newNode();
		p->n = i + 1;
		
		p->prev = tail;
		tail = p;
	}

	Node *cur = tail;

	while (cur != 0)
	{
		cout << cur->n << endl;
		cur = cur->prev;
	}


	return 0;
}