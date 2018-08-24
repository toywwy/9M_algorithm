/*
���� : ������
���� ��ȣ: 1406
Ǯ�̹� : Linked List
��¥ : 18.08.24
��Ÿ : 
����Ʈ����Ʈ�� CRD����.
*/

#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int N,len;
char str[100002];

class Node
{
public:
	char c;
	Node * next;
	Node * prev;
};


inline int getLength()
{
	return 0;
}

Node * head;
Node * tail;

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	head = new Node();
	tail = new Node();
	head->next = tail;
	tail->prev = head;

	Node *cur = head;

	cin >> str;
	for (int i = 0; str[i] != 0;i++)
	{
		Node * p = new Node();
		p->c = str[i];

		cur->next = p;
		p->prev = cur;
		
		p->next = tail;
		tail->prev = p;

		cur = p;
	}

	cin >> N;
	char cmd,c;
	
	//�ʱ������ ��ɾ �ǵڿ� ��ġ�ϰ� �ִ�.
	//Ŀ���� cur�� �����ʿ� �ִٰ� �����ϰ� ������ Ǭ��.
	for (int i = 0; i < N; i++)
	{
		cin >> cmd;


		if (cmd == 'L') //Ŀ�� �������� ��ĭ �ű�
		{
			//��� head���� �ص��ȴ�.
			if(cur->prev != 0)
				cur = cur->prev;
		}
		else if (cmd == 'D') //Ŀ�� ���������� ��ĭ �ű�
		{
			if (cur->next != tail)
				cur = cur->next;
		}
		else if (cmd == 'B') //Ŀ�����ʿ� �ִ� ���� ����
		{//cur�� �����Ǵ°� �����ؾ��Ѵ�.

			if (cur == head) continue; //������ �Ǿ��̸� �����Ѵ�.

			Node *before = cur->prev;
			Node *after = cur->next;

			before->next = after;
			after->prev = before;

			cur = before;
		}
		else if (cmd == 'P')//���ڿ� Ŀ�� ���ʿ� �߰�
		{
			cin >> c;
			Node * n = new Node();
			n->c = c;

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



	return 0;
}
