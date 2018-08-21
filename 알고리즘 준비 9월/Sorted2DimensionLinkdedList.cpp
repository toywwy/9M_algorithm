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
}nodes[10000];

Node *ids[N];// 노드 갯수에 따라 다르다.

int idx, SIZE;
Node* newNode()//무한히 확장시켜나간다.
{
	return &nodes[idx++];
}


void addNode(int from, int to)
{
	Node * p = newNode();
	p->to = to;
	p->prev = ids[from];
	ids[from] = p;
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