/*
���� : ���ڿ�����
���� ��ȣ: 14425
Ǯ�̹� : Trie
��¥ : 18.06.02
��Ÿ : Hash �����ε� Ǯ���ִ�.
������ ��ġ�ϴ� �� ã���� �Ǵ°Ŵϱ�.
�ϴ��� Trie �������̴� trie�� ����

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
		//������ ���� �����Ҽ��� ����..��
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
		
		cur->leaf = true;//�������ΰ�. �ܾ� ��ü�� ���ؾ� �ϱ� ������
	}
	
	//tree ���� �Ϸ��ߴ�.

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
				break; //���°Ŵ�.
			}
			else
				cur = cur->childs[str[j] - 'a'];
		}

		if (chk&&cur->leaf) {
			res++;
		}
	}

	cout << res << endl;
	
	//delete root; ���� �ϴ� ���� ..�ð� �ʰ�����.
	//���Ű� ���� �ɱ� �ƴұ�..

	return 0;
}
