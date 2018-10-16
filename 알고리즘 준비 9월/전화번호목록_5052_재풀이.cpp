/*
문제 : 전화번호 목록
문제 번호: 5052
풀이법 : Trie
날짜 : 18.10.17
기타 : 속도가 훨씬 빨랐다.
pool사용해서 했다.
어차피 시험에서는 delete 안쓰니깐..
11364	36
공간 복잡도는 delete 할때 보다는 많이 썼지만 속도가 매우 빨랐다.

여기서도 입력 안받고 break; 해서 timeout나서 고생했다.
그리고 긴거 먼저 짧은게 그 다음에 올때 체크 안해줘서

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;


//0,1,2,3,4,5,6,7,9

class Trie {
public:
	Trie *childs[11]; // 0~9
	bool isLeaf;
}tries[100002];


int idx = 0;

vector<string> inputs;


Trie * newTrie()
{
	for (int i = 0; i < 11; i++) tries[idx].childs[i] = 0;
	tries[idx].isLeaf = false;

	return &tries[idx++];
}

Trie *base;//여기에서 시작한다.

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int TC;
	cin >> TC;
	for (int itr = 0; itr < TC; itr++) {

		idx = 0;

		bool resChk = true;
		base = newTrie();

		int N;
		cin >> N;


		for (int i = 0; i < N; i++)
		{
			string input;
			cin >> input;
			if (resChk == false) continue;

			int len = input.length();

			Trie * cur = base;
			for (int j = 0; j < len; j++)
			{
				if (cur->childs[input[j] - '0'] == 0) { //처음
					Trie *t = newTrie();
					cur->childs[input[j] - '0'] = t;
					cur = t;
				}
				else //객체가 이미 생성되어있다.
				{
					cur = cur->childs[input[j] - '0'];
					if (cur->isLeaf == true || len - 1 == j)
					{
						resChk = false;
						break;
					}
				}

			}
			cur->isLeaf = true;
		}
		if (resChk) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}
