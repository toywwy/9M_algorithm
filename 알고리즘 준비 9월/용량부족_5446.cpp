/*
���� : �뷮 ����
���� ��ȣ: 5446
Ǯ�̹� : Trie
��¥ : 18.06.03
��Ÿ :

�ڳ����̽��� �����Ұ��� ���ڿ��� 0�� �϶� ���� 1�� �Ǵ°� ó������ ���ߴ�.
�̰͵�.. ù���� ������ ������. ����� ���� �ߵǾ��־�� �Ѵ�.

ù���� �� �ڽ� ���� ���� ��Ʈ�� ó������ ���ϰ� ������ߴ�.
ó���� for 128�� �ϴ°� �ƴ϶� node�� ó���Ұ� ���ϰ� ���� 128�� ��͸� Ÿ�� ��������ߴ�.
ù���̽� �����̽� ��ó�� �ϵ�������.


*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;


class Node {
	
public:
	bool leaf; //�����ؾ��� ���ڿ��� ���� ���
	bool notAllowed; //�ڽ����� ���� �Ұ����� ���ڿ��� �����ϴ� ���.
	Node *childs[128]; //�ƽ�Ű�ڵ�
	int cnt;//��ü������ ���������� üũ

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

		if (cur->childs[i]->cnt > 0)// ��ü�� ������ �Ǿ��־ �ʿ� �������� �ִ�.(�����Ұ����� ���ڿ���)
		{//cnt�� �ִٴ°� ���� ������ ���ڰ� �� Ʈ���� ���� �����Ѵٴ� ���̴�.

			if (cur->childs[i]->notAllowed) //���ϵ�ī������ �Ұ����ϴٸ�.
			{
				if (cur->childs[i]->leaf) //�׷��� �� �ڸ��� ������� ����� �ٽ� ���
				{
					gCnt += 1;
					recur(cur->childs[i]);
				}
				else recur(cur->childs[i]);
			}
			else gCnt += 1; //�ѹ��� ���� ���� (���ϵ�ī�� ��밡��)
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

		//�Ϲ�Ʈ��
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

		//�ϴ��� �ӽù���� Ǯ�̷� 0�϶��� ���� ó�����ش�.
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
					cur->notAllowed = true; //��Ʈ �Ʒ����� �ϸ� �ȴ�.
				}
			}

			recur(root);
		}
		cout << gCnt << endl;
		delete root;

	}
	return 0;
}
