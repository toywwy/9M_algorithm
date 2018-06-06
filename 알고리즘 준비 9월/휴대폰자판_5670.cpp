/*
���� : �޴��� ����
���� ��ȣ: 5670
Ǯ�̹� : Trie
��¥ : 18.06.02
��Ÿ : 

Ǫ�µ� ��� ��ġ�ٰ�. �ʹ� ������ ���� ���ȴ�...

�ڽ� ������ cnt�ϴ°Ͱ� �� �𸣰� �ڱ� �ڽ� ���� cnt �ع��ȴµ�
ó���� ��Ʈ�� cnt�� �Է��Ҷ� N ��ü�� �Է��ع����� �ȵƴ�.

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;


class Node {

public:
	//�Է¿��� ���� ��ҹ��ڿ� ���鹮��, �׸��� ����, Ư�����ڸ� ���Ե� �� �ִ�.
	Node *childs[26];//�ƽ�Ű�ڵ� 128�� ���� �� �Ҽ��ֵ��� ..
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
				if (cur->childs[i]->cnt == 1)//���� ������ Ž���� �ϸ�ȴ�. 
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
				if (cur->childs[i]->cnt == 1)//���� ������ Ž���� �ϸ�ȴ�. 
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
	//�̰� Ʈ���̷� ������ �ؾߵǳ�?
	//��¥ �� ������ �׳� Trie ����������..
	//��¥ ������ ..�Դٰ� ������� ���� �������µ�..

	int N;

	
	while (cin >> N)
	{
		gCnt = 0;

		Node * root = new Node();
		Node *cur = root;

		int k = 0;
		//1~80������ ���� �ҹ��ڷθ�
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
