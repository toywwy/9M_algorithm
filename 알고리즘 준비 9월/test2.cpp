/*
그래프문제를 위한 2차원 Point
*/

#include<iostream>

using namespace std;


class Node {
public:
	int to;
	//int weight;
	Node* prev;
} nodes[10000];


int idx;

Node * newNode()
{
	return &nodes[idx++];
}

Node *ids[10000];


inline void con(int from,int to)
{
	Node *p = newNode();
	p->to = to;
	p->prev = ids[from];
	ids[from] = p;

	/*
		새로생긴 객체 p가 포인팅을해야지
		X->prev = p;
		X = p 이런식으로 하게 되면 X가 가리키는 값이 바뀌어 버리니까 조심해야한다.

	*/

}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0);

	int from, to;

	Node *x = newNode();

	for (int i = 0; i < 20; i++)
	{
		cin >> from >> to;

		con(from, to); //바로 앞뒤를 이를수있는거지.
		con(to, from);
	}

	for (int i = 1; i < 10; i++)
	{
		Node *cur = ids[i];//처음꺼가 대몬이다.
		cout << "[ " << i << " ]";
		while (cur->prev != 0)
		{
			cout <<" > "<< cur->to;
			cur = cur->prev;
		}
		cout << endl<<endl;
	}

	return 0;
}
