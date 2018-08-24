/*
문제 : 조세퍼스 문제
문제 번호: 1158
풀이법 : Linked List 링크드 리스트
날짜 : 18.08.24
기타 :

Dummy를 만들지 않고 진행을 해보자,
환형 큐의 경우는 Dummy를 skip하는 부분이 생각보다 복잡하다.
Dummy 없이 진행하니 깔끔..
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int N, M;


class Node {
public:
	int idx;
	Node * next;
	Node * prev;
};


int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M;

	Node *ini = new Node();
	ini->idx = 1;
	
	Node * cur = ini;

	for (int i = 1; i < N; i++)
	{
		Node *p = new Node();
		p->idx = i + 1;
		cur->next = p;
		p->prev = cur;
		cur = p;
	}
	
	//Head랑 연결
	ini->prev = cur;
	cur->next = ini;

	//시작부분
	cur = ini->prev;

	int C, nodeCnt = N;

	cout << "<";
	while (1)
	{
		if (nodeCnt < 2) break;
		C = M%nodeCnt;
		for (int i = 0; i < C; i++) cur = cur->next;

		cout << cur->idx << ", ";

		Node * before = cur->prev;
		Node * after = cur->next;
		before->next = after;
		after->prev = before;
		cur = before;

		nodeCnt -= 1;

	}
	cout << cur->idx << ">";

	return 0;
}
