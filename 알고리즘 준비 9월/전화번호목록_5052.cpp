/*
���� : ��ȭ��ȣ���
���� ��ȣ: 5052
Ǯ�̹� : Ʈ���� TRIE
��¥ : 18.06.01
��Ÿ : ~Node() �Ҹ��ڸ� ���� �غ��Ҵ�.
** break ������ �Է¹��۰� �����ִµ� ������ ���Ѱ� �־���.

*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

//Trie �����ϸ�Ǵ°���


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
			if (childs[i]) delete childs[i];//�˾Ƽ� �� �Ʒ��� ���� �������ǳ�?
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

			if (ans == false) continue;//�Է� ���۸� �� �Ⱥ���༭ �׷���.

			int len = str.length();//depth�� �ɰ��̴�.
								   //������ ���±����� ����� ����.
			cur = root;
			for (int i = 0; i < len; i++)
			{
				if (cur->childs[str[i] - '0'] && len - 1 == i) //���� Leaf �ε� �̹� ��ü�� �����Ǿ��ֵ�.
				{
					ans = false;
					break;
				}

				if (!cur->childs[str[i] - '0']) cur->childs[str[i] - '0'] = new Node();

				if (len - 1 != i && (cur->childs[str[i] - '0']->isLeaf == true)) //Leaf�� �ִµ� ���� �ƴѰ��
				{
					ans = false;
					break;
				}

				if (len - 1 == i)//Leaf ǥ��
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