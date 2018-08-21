/*
문제 : 풍선터뜨리기
문제 번호: 2346
풀이법 : LinkedList
날짜 : 20180821
기타 : 환형 링크드 리스트
CircledLinkedList
Mod 같은거 안해도된다.


*/

#include<iostream>
using namespace std;

int N;

class Node {
public :
	int v;
	int idx;
	Node * next;
	Node * prev;
};

Node *ini;

int nodeCnt;
int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N;

	ini = new Node();
	ini->v = -1;
	Node *cur = ini;

	for (int i = 0; i < N; i++)
	{
		Node * p = new Node();
		cin >> p->v;
		p->idx = i + 1;

		cur->next = p;
		p->prev = cur;

		p->next = ini;
		ini->prev = p;

		cur = p;
	}
	nodeCnt = N;

	cur = ini->next;//시작

	while (1)
	{
		cout << cur->idx << " ";
		int value = cur->v;
		Node * before = cur->prev;
		Node * after = cur->next;
		before->next = after;
		after->prev = before;

		nodeCnt -= 1;

		if (nodeCnt < 1) break;

		if (value > 0)
		{
			cur = before;//다음칸부터 1이다.
			for (int i = 0; i < value; i++) {
				cur = cur->next;
				if (cur == ini) cur = cur->next;
			}
		}
		else // 음수일경우
		{
			cur = after;

			for (int i = 0; i < -value; i++) {
				cur = cur->prev;
				if (cur == ini) cur = cur->prev;
			}
		}
	}


	return 0;
}
