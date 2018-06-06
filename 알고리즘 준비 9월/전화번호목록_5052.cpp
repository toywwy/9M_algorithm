/*
문제 : 전화번호목록
문제 번호: 5052
풀이법 : 트라이 TRIE
날짜 : 18.06.01
기타 : ~Node() 소멸자를 정의 해보았다.
** break 때문에 입력버퍼가 남아있는데 지우지 못한게 있었다.

*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

//Trie 구현하면되는거임


class Node {
public:
	bool isLeaf;
	Node *childs[10];
	Node()
	{
		this->isLeaf = false;
		for (int i = 0; i < 10; i++) childs[i] = nullptr;
	}

	~Node()
	{
		for (int i = 0; i < 10; i++)
		{
			if (childs[i]) delete childs[i];//알아서 그 아래꺼 까지 해제가되나?
		}
	}
};


Node *root;
Node *cur;

int main(void)
{
	int N, M;
	cin >> N;

	for (int itr = 0; itr < N; itr++)
	{
		bool ans = true;
		root = new Node();
		cin >> M;
		for (int c = 0; c < M; c++)
		{

			string str;
			cin >> str;

			if (ans == false) continue;//입력 버퍼를 다 안비워줘서 그랬다.

			int len = str.length();//depth가 될것이다.
								   //삭제가 없는구조야 어렵지 않음.
			cur = root;
			for (int i = 0; i < len; i++)
			{
				if (cur->childs[str[i] - '0'] && len - 1 == i) //지금 Leaf 인데 이미 객체가 생성되어있따.
				{
					ans = false;
					break;
				}

				if (!cur->childs[str[i] - '0']) cur->childs[str[i] - '0'] = new Node();

				if (len - 1 != i && (cur->childs[str[i] - '0']->isLeaf == true)) //Leaf가 있는데 끝이 아닌경우
				{
					ans = false;
					break;
				}

				if (len - 1 == i)//Leaf 표시
					cur->childs[str[i] - '0']->isLeaf = true;

				cur = cur->childs[str[i] - '0'];

			}
		}

		if (ans) cout << "YES" << endl;
		else cout << "NO" << endl;

		delete root;
	}


	return 0;
}