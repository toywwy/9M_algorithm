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
}nodes[10000];//갯수로 잘통제하자.

Node *ids[N];// 노드 갯수에 따라 다르다.

int idx, SIZE;
Node* newNode()//무한히 확장시켜나간다.
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

		prevNode = cur;//중간 삽입시 이전노드와 이어주기위함.
		cur = cur->prev;

		chk = true;//노드가 tail에 삽입되는 것이 아니라. 중간에 삽입 된다는 의미이다.
		//cur 포인터가 움직였으니.
	}

	Node * p = newNode();
	p->to = to;

	if (chk == false)//평범한 일반삽입
	{
		p->prev = ids[from];
		ids[from] = p; //새로운 노드가 tail로 변화된다.
	}
	else //중간 삽입
	{
		prevNode->prev = p;
		p->prev = cur;
		//tail이 변하지 않는다 중간에 삽입되기때문, 대신 이전 노드와 이어줘야한다.
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