/*
문제 : 용량 부족
문제 번호: 5446
풀이법 : Trie
날짜 : 18.06.03
기타 :

코너케이스인 삭제불가능 문자열이 0개 일때 답이 1이 되는걸 처리하지 못했다.
이것도.. 첫시작 가지의 문제다. 꼭대기 부터 잘되어있어야 한다.

첫노드던 그 자식 노드던 같은 루트를 처음부터 지니고 갔어야했다.
처음에 for 128을 하는게 아니라 node가 처리할거 다하고 다음 128로 재귀를 타고 나갔어야했다.
첫케이스 끝케이스 잘처리 하도록하자.


*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;


class Node {
	
public:
	bool leaf; //삭제해야할 문자열의 리프 노드
	bool notAllowed; //자식으로 삭제 불가능한 문자열을 포함하는 노드.
	Node *childs[128]; //아스키코드
	int cnt;//객체생성시 지나갔음을 체크

	Node()
	{
		this->cnt = 0;
		this->leaf = false;
		this->notAllowed = false;

		for (int i = 0; i < 128; i++) this->childs[i] = nullptr;
	}
	
	~Node()
	{
		for (int i = 0; i < 128; i++) if(this->childs[i]) delete this->childs[i];
	}

};


int gCnt;

void recur(Node * cur)
{
	
	for (int i = 0; i < 128; i++)
	{
		if (cur->childs[i] == nullptr) continue;

		if (cur->childs[i]->cnt > 0)// 객체가 생성이 되어있어도 필요 없을수가 있다.(삭제불가능한 문자열들)
		{//cnt가 있다는건 삭제 가능한 문자가 그 트리의 끝에 존재한다는 것이다.

			if (cur->childs[i]->notAllowed) //와일드카드사용이 불가능하다면.
			{
				if (cur->childs[i]->leaf) //그런데 그 자리가 리프라면 지우고 다시 재귀
				{
					gCnt += 1;
					recur(cur->childs[i]);
				}
				else recur(cur->childs[i]);
			}
			else gCnt += 1; //한번에 제거 가능 (와일드카드 사용가능)
		}
	}
}


int main(void)
{
	int N,M;
	cin >> N;

	for (int itr = 0; itr < N; itr++)
	{

		cin >> M;
		gCnt = 0;

		Node * root = new Node();

		//일반트리
		for (int i = 0; i < M; i++)
		{
			string str;
			cin >> str;

			Node * cur = root;
			for (int j = 0; str[j] != '\0'; j++)
			{
				if (cur->childs[str[j]] == nullptr)
					cur->childs[str[j]] = new Node();
				
				cur = cur->childs[str[j]];
				cur->cnt += 1;
			}
			cur->leaf = true;
		}

		cin >> M;

		//일단은 임시방편겸 풀이로 0일때를 따로 처리해준다.
		if (M == 0) gCnt = 1;
		else
		{

			for (int i = 0; i < M; i++)
			{
				string str;
				cin >> str;

				Node * cur = root;
				for (int j = 0; str[j] != '\0'; j++)
				{

					if (cur->childs[str[j]] == nullptr)
						cur->childs[str[j]] = new Node();

					cur = cur->childs[str[j]];
					cur->notAllowed = true; //루트 아래부터 하면 된다.
				}
			}

			recur(root);
		}
		cout << gCnt << endl;
		delete root;

	}
	return 0;
}
