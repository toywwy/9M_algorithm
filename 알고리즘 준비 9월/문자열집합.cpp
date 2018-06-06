/*
문제 : 문자열집합
문제 번호: 14425
풀이법 : Trie
날짜 : 18.06.02
기타 : Hash 구조로도 풀수있다.
완전히 일치하는 걸 찾으면 되는거니까.
일단은 Trie 공부중이니 trie로 ㄱㄱ

*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Node {
public:
	Node *childs[26];
	bool leaf;
	Node()
	{
		this->leaf = false;
		for (int i = 0; i < 26; i++)
			this->childs[i] = nullptr;
	}
	~Node()
	{
		//완전히 모든걸 제거할수는 없다..ㅠ
		for (int i = 0; i < 26; i++)
			delete this->childs[i];
	}


};


Node * root;

int main(void)
{
	int N, M;
	string str;

	cin >> N >> M;

	root = new Node();
	
	Node * cur = root;

	for (int i = 0; i < N; i++)
	{
		cin >> str;
		cur = root;

		int j = 0;
		for (j = 0; str[j]!='\0'; j++)
		{
			if (cur->childs[str[j]-'a'] == nullptr)
			{
				cur->childs[str[j] - 'a'] = new Node();
			}

			cur = cur->childs[str[j] - 'a'];
		}
		
		cur->leaf = true;//마지막인가. 단어 전체를 비교해야 하기 때문에
	}
	
	//tree 집합 완료했다.

	int res = 0;

	for (int i = 0; i < M; i++)
	{
		cin >> str;
		cur = root;
		bool chk=true;
		for (int j = 0; str[j] != '\0'; j++)
		{
			if (cur->childs[str[j] - 'a'] == nullptr) {
				chk = false;
				break; //없는거다.
			}
			else
				cur = cur->childs[str[j] - 'a'];
		}

		if (chk&&cur->leaf) {
			res++;
		}
	}

	cout << res << endl;
	
	//delete root; 제거 하는 순간 ..시간 초과난다.
	//제거가 좋은 걸까 아닐까..

	return 0;
}
