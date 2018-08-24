/*
���� : Ű�ΰ�
���� ��ȣ: 5397
Ǯ�̹� : LinkedList
��¥ : 18.08.24
��Ÿ :
�����Ҵ�����
*/

#include<iostream>
#define LEN 1000002
using namespace std;

char str[LEN];

class Node
{
public:
	char c;
	Node * next;
	Node * prev;
}nodes[LEN];

Node * head;
Node * tail;

int idx = 0;
Node * newNode()
{
	return &nodes[idx++];
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int C;
	cin >> C;

	for (int itr = 0; itr < C; itr++)
	{
		idx = 0;
		head = newNode();
		tail = newNode();
		head->next = tail;
		tail->prev = head;

		Node *cur = head;

		cin >> str;
		for (int i = 0; str[i] != 0; i++)
		{

			if (str[i] == '<') //Ŀ�� �������� ��ĭ �ű�
			{
				if (cur->prev != 0) cur = cur->prev;
			}
			else if (str[i] == '>') //Ŀ�� ���������� ��ĭ �ű�
			{
				if (cur->next != tail) cur = cur->next;
			}
			else if (str[i] == '-') 
			{
				if (cur == head) continue; //������ �Ǿ��̸� �����Ѵ�.

				Node *before = cur->prev;
				Node *after = cur->next;

				before->next = after;
				after->prev = before;

				cur = before;
			}
			else
			{
				Node * n = newNode();
				n->c = str[i];

				Node *after = cur->next;

				cur->next = n;
				n->prev = cur;

				n->next = after;
				after->prev = n;

				cur = n;
			}
		}


		cur = head->next;
		while (cur != tail)
		{
			cout << cur->c;
			cur = cur->next;
		}
		cout << endl;

	}

	return 0;
}
