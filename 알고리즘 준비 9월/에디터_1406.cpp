/*
문제 : 에디터
문제 번호: 1406
풀이법 : Linked List
날짜 : 18.08.24
기타 : 
링스트리스트의 CRD느낌.
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
	
	//초기시작은 명령어가 맨뒤에 위치하고 있다.
	//커서는 cur의 오른쪽에 있다고 고정하고 문제를 푼다.
	for (int i = 0; i < N; i++)
	{
		cin >> cmd;


		if (cmd == 'L') //커서 왼쪽으로 한칸 옮김
		{
			//얘는 head까지 해도된다.
			if(cur->prev != 0)
				cur = cur->prev;
		}
		else if (cmd == 'D') //커서 오른쪽으로 한칸 옮김
		{
			if (cur->next != tail)
				cur = cur->next;
		}
		else if (cmd == 'B') //커서왼쪽에 있는 문자 삭제
		{//cur가 삭제되는걸 주의해야한다.

			if (cur == head) continue; //문장의 맨앞이면 무시한다.

			Node *before = cur->prev;
			Node *after = cur->next;

			before->next = after;
			after->prev = before;

			cur = before;
		}
		else if (cmd == 'P')//문자열 커서 왼쪽에 추가
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
