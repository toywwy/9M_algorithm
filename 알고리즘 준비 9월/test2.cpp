/*
�׷��������� ���� 2���� Point
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
		���λ��� ��ü p�� ���������ؾ���
		X->prev = p;
		X = p �̷������� �ϰ� �Ǹ� X�� ����Ű�� ���� �ٲ�� �����ϱ� �����ؾ��Ѵ�.

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

		con(from, to); //�ٷ� �յڸ� �̸����ִ°���.
		con(to, from);
	}

	for (int i = 1; i < 10; i++)
	{
		Node *cur = ids[i];//ó������ ����̴�.
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
