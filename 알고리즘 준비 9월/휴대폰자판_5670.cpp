/*
문제 : 휴대폰 자판
문제 번호: 5670
풀이법 : Trie
날짜 : 18.06.02
기타 : 

푸는데 계속 고치다가. 너무 문제가 꼬여 버렸다...

자식 갯수를 cnt하는것과 난 모르고 자기 자신 까지 cnt 해버렸는데
처음에 루트의 cnt를 입력할때 N 자체를 입력해버려서 안됐다.

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;


class Node {

public:
	//입력에는 영문 대소문자와 공백문자, 그리고 숫자, 특수문자만 포함될 수 있다.
	Node *childs[26];//아스키코드 128개 까지 다 할수있도록 ..
	bool leaf;
	int cnt;

	Node()
	{
		for (int i = 0; i < 26; i++) this->childs[i] = nullptr;
		this->leaf = false;
		this->cnt = 0;
	}

	~Node()
	{
		for (int i = 0; i < 26; i++) delete this->childs[i];
	}

};

int gCnt;
void recur(Node * cur,int before,int cnt)
{
	for (int i = 0; i < 26; i++)
	{
		if (cur->childs[i] != nullptr)
		{
			if (cur->childs[i]->leaf)
			{
				if (cur->childs[i]->cnt == 1)//여기 까지만 탐색을 하면된다. 
				{
					gCnt += cnt + 1;
				}
				else
				{
					if (before == cur->childs[i]->cnt)
					{
						gCnt += cnt;
						recur(cur->childs[i], cur->childs[i]->cnt, cnt);
					}
					else
					{
						gCnt += (cnt + 1);
						recur(cur->childs[i], cur->childs[i]->cnt, cnt + 1);
					}
				}
			}
			else
			{
				if (cur->childs[i]->cnt == 1)//여기 까지만 탐색을 하면된다. 
				{
					gCnt += cnt + 1;
				}
				else
				{

					if (cur->childs[i]->cnt < before) {
						recur(cur->childs[i], cur->childs[i]->cnt, cnt + 1);
					}
					else
						recur(cur->childs[i], cur->childs[i]->cnt, cnt);
				}
			}


		}
	}

}

int main(void)
{
	//이걸 트라이로 구현을 해야되나?
	//진짜 그 문제는 그냥 Trie 문제였구나..
	//진짜 완전히 ..게다가 어렵지도 않은 문제였는데..

	int N;

	
	while (cin >> N)
	{
		gCnt = 0;

		Node * root = new Node();
		Node *cur = root;

		int k = 0;
		//1~80글자인 영어 소문자로만
		for (int i = 0; i < N; i++)
		{
			string str;
			cin >> str;

			cur = root;
			for (int j = 0; str[j] != '\0'; j++)
			{

				if (cur->childs[str[j] - 'a'] == nullptr)
				{
					cur->childs[str[j] - 'a'] = new Node();

					if (j == 0)
						k++;
				}

				cur = cur->childs[str[j] - 'a'];
				cur->cnt += 1;
			}
			cur->leaf = true;
		}

		
		recur(root,N+1,0);

		//cout << gCnt << endl;
		double res = (double)gCnt / (double)N;
		printf("%.2f\n", res);
		delete root;

	}
	return 0;
}
