#include<iostream>

using namespace std;

class Node {
public:
	int to;
	int v;
	Node * prev;
}nodes[100000];

int idx;

Node* ids[10];

Node * newNode()
{
	return &nodes[idx++];
}


int main(void)
{
	int N, M;
	cin>>N>>M;

	while (M--)
	{
		int from, to, v;
		cin >> from >> to >> v;
		Node * p = newNode();
		p->to = to;
		p->v = v;

		p->prev = ids[from];
		ids[from] = p;
	}


	for (int i = 1; i <= 7; i++)
	{
		cout << i << " : ";
	
		Node *cur = ids[i];

		while (cur != 0)
		{
			cout << cur->to << "(" << cur->v << ")  ";
			cur = cur->prev;
		}

		cout << endl;
	}



	return 0;
}