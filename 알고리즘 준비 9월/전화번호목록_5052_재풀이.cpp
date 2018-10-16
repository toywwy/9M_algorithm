/*
���� : ��ȭ��ȣ ���
���� ��ȣ: 5052
Ǯ�̹� : Trie
��¥ : 18.10.17
��Ÿ : �ӵ��� �ξ� ������.
pool����ؼ� �ߴ�.
������ ���迡���� delete �Ⱦ��ϱ�..
11364	36
���� ���⵵�� delete �Ҷ� ���ٴ� ���� ������ �ӵ��� �ſ� ������.

���⼭�� �Է� �ȹް� break; �ؼ� timeout���� ����ߴ�.
�׸��� ��� ���� ª���� �� ������ �ö� üũ �����༭

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

Trie *base;//���⿡�� �����Ѵ�.

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
				if (cur->childs[input[j] - '0'] == 0) { //ó��
					Trie *t = newTrie();
					cur->childs[input[j] - '0'] = t;
					cur = t;
				}
				else //��ü�� �̹� �����Ǿ��ִ�.
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
