/*
문제 : 조세퍼스 문제
문제 번호: 1158
풀이법 : Linked List 링크드 리스트
날짜 : 18.08.24
기타 :

Dummy를 넣어서 진행하는바람에 예외처리를 해야하는 부분이 생겼다 ...
ini일 경우 pass를 해주어야하는 부분이 생긴다.
Dummy를 만들지 않고 환형 큐를 구성한다면?

*/

#include<iostream>
using namespace std;

int N,M;

class Node {
public:
	int idx;
	Node * next;
	Node * prev;
};

Node *ini;

int nodeCnt;
int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M;

	ini = new Node();
	ini->idx = -1;
	Node *cur = ini;


	for (int i = 0; i < N; i++)
	{
		Node * p = new Node();
		p->idx = i + 1;

		cur->next = p;
		p->prev = cur;

		p->next = ini;
		ini->prev = p;

		cur = p;
	}
	nodeCnt = N;

	cur = ini->prev;//시작
	int C = 0;
	cout << "<";
	while (1)
	{
		if (nodeCnt < 2) break;

		C = M%nodeCnt;

		for (int i = 0; i < C; i++) {
			cur = cur->next;
			if (cur == ini) cur = cur->next;
		}

		cout << cur->idx << ", ";
		Node * before = cur->prev;
		Node * after = cur->next;
		before->next = after;
		after->prev = before;
		
		//before로 지정한거니깐. prev로해야한다.
		if (before == ini) before = before->prev;
		cur = before;

		nodeCnt -= 1;

	}
	cout <<cur->idx<< ">";

	return 0;
}