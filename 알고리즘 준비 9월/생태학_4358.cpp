/*
���� : ������
���� ��ȣ: 4358
Ǯ�̹� : Trie
��¥ : 18.06.02
��Ÿ :

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
//30���ڸ� ���� ������, �Է¿��� �ִ� 10,000���� 

class Node {

public:
	//�Է¿��� ���� ��ҹ��ڿ� ���鹮��, �׸��� ����, Ư�����ڸ� ���Ե� �� �ִ�.
	Node *childs[128];//�ƽ�Ű�ڵ� 128�� ���� �� �Ҽ��ֵ��� ..
	bool leaf;
	int cnt;
	string str;

	Node()
	{
		for (int i = 0; i < 128; i++) this->childs[i] = nullptr;
		this->leaf = false;
		this->cnt = 0;
		this->str = "\0";
	}

};


double cnt = 0;

void recur(Node *cur)
{
	for (int i = 0; i < 128; i++)
	{
		if (cur->childs[i] != nullptr)
		{
			if (cur->childs[i]->leaf == true)
			{
			//	printf("%s %.4f\n", cur->childs[i]->str, ((double)cur->childs[i]->cnt / (double)cnt) * 100);
				cout << cur->childs[i]->str << " " << ((double)cur->childs[i]->cnt / (double)cnt)*100 << endl;
			}

			recur(cur->childs[i]);
		}
	}



}


int main(void)
{

	cout.setf(ios::fixed);
	cout.precision(4);

	Node *root;
	root = new Node();
	while (true)
	{
		string str;

		getline(cin, str);

		//Leaf�� �������� count �Ѵ�.
		Node * cur = root;
		for (int i = 0; str[i] != '\0'; i++)
		{

			if (cur->childs[str[i]] == nullptr)
				cur->childs[str[i]] = new Node();

			cur = cur->childs[str[i]];
		}
		
		if (cur->leaf == true)
			cur->cnt += 1;
		else
		{
			cur->leaf = true;
			cur->cnt += 1; 
			cur->str = str;

		}

		if (str[0] == '\0') break;
		else cnt+=1;
	}

	//���߿� ����Ž�� �ϸ鼭 leaf ���� ī��Ʈ�� ȣ���ϸ�ȴ�.
	//cnt /= (double)100;
	recur(root);

	return 0;
}
