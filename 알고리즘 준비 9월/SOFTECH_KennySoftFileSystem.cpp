/*
���� : KSFS: Kenny Soft FileSystem
���� ��ȣ: https://swexpertacademy.samsung.com/common/swea/solvingPractice/userProblemDetail.do?contestProbId=AWOlrV2PbdEAAAGq&userSortingType=&solveclubId=&solveclubPassword=&attendYn=&rowNum=10&c=&cpp=&java=&py=&c=&cpp=&java=&py=&c=&cpp=&java=&py=&c=&cpp=&java=&py=&c=&cpp=&java=&py=&c=&cpp=&java=&py=&c=&cpp=&java=&py=&c=&cpp=&java=&py=&c=&cpp=&java=&py=&c=&cpp=&java=&py=&pageIndex=1
Ǯ�̹� : TRIE
��¥ : 18.10.21
��Ÿ : 
�̰� ���� �����ϴ°� ��������..

��ü pool�� ���������� ���������� 0���� �� �ʱ�ȭ�� �Ǵ°��̴�.
���� ���������� �ƴϿ����� 0�� �ƴ϶� �׳� ������ ���̴�.
�̰� ����ϰ� init, delete ��Ÿ ��� �ҋ�
isExist�� �߰�������Ѵ�.
��¥ �߿��ϴ�.

*/

extern int _strlen(const char *str);
extern int _strcmp(const char *str1, const char *str2);

#define SIZE 200000

class Trie {
public:
	Trie * parent;//�갡 0�̸� Base ( �� root �ΰŰ�..)
	Trie * childs[26];//���ĺ� 26��

	bool isStart;
	bool isEnd;//cd�Ҷ��� ����..? ��..
	int cnt;
}tries[SIZE];

int idx;
Trie * newTrie()
{
	//init;
	for (int i = 0; i < 26; i++) tries[idx].childs[i] = 0;
	tries[idx].isEnd = tries[idx].isStart = false;
	tries[idx].parent = 0;
	tries[idx].cnt = 0;

	return &tries[idx++];
}

Trie *pwdParent;
Trie *base;
Trie *cur;
Trie *pwd;//cd ���� ���� �ٲ�� �ȴ�.

void init()
{
	idx = 0;
	base = newTrie();
	pwd = cur = base;
	pwd->parent = 0;
}
int mkdir(char name[])//1
{
	cur = pwd;//���� ��ġ����
	int len = _strlen(name);
	for (int i = 0; i < len; i++)
	{
		int strIdx = name[i] - 'a';
		if (cur->childs[strIdx] == 0)
		{
			Trie * p = newTrie();//ó���� üũ�� �ؾ��ұ� ���ص� ������ ..�ϴ� ����.
								 //p->parent = pwd->parent; //0 �̸� ����� base��.
			cur->childs[strIdx] = p;
			cur = cur->childs[strIdx];
		}
		else //��ü�� �̹� �����Ѵ�.
		{
			if (i == len - 1)//�������ε�
			{
				if (cur->childs[strIdx]->isEnd == true)
				{
					return 0;//�Է� �������� �ʴ� �̻�.
				}
			}
			else//�������� �ƴ϶�� ���� X
			{
				cur = cur->childs[strIdx];
			}
		}
	}
	cur->isEnd = true;
	pwd->cnt += 1;
	return 1;
}
int cd(char path[])//2
{
	//cd�� �ϸ� pwd�� �ٲ����Ѵ�.
	//  '/' , "..", "(���ڿ�)\t" �� �־�����.

	if (path[0] == '/')//���� ����.
	{
		pwd = base;
		return 1;
	}
	else if (path[0] == '.' && path[1] == '.')//".." �̹� ��Ʈ�� �־��ٸ� ������.
	{
		if (pwd == base) return 0;
		else//�ϳ� �θ�� ������. �̰� ������ �θ� ������ �־�߰ڴ�.
		{
			Trie *temp = pwd->parent;
			pwd = pwdParent;
			pwdParent = temp;
			return 1;
		}
	}
	else//�������� �׳� '\t' �� ���� �ü��� �ְ� ���ڿ� + \t�� �ü��ִµ�.
	{
		//���������� ���� �����ɷ� ���! 
		int len = _strlen(path);
		if (path[0] == 0 || path[0] == '0')
			len = 0;
		cur = pwd;
		for (int i = 0; i < len - 1; i++)
		{
			int strIdx = path[i] - 'a';
			if (cur->childs[strIdx] != 0)
			{
				cur = cur->childs[strIdx];
			}
			else
			{
				return 0;//���� �Էµ� �ܾ ����.
			}
		}

		if (cur->isEnd == true)
		{
			Trie * temp = pwd;
			pwd = cur;
			pwd->parent = pwdParent;
			pwdParent = temp;//���� pwd�� parent�� �Ǵ°Ű�..

			return 1;
		}
		else
		{
			//------------------------ ���⼭ ���ʹ� tab���� ������ �����ؾ��Ѵ�.
			//isEnd�� ã�������� ��� �̵��ؾ��Ѵ�...
			for (int k = 0; k < 12 - (len - 1); k++) //a���� ����.
			{
				for (int i = 0; i < 26; i++)
				{
					if (cur->childs[i] != 0)
					{
						cur = cur->childs[i];
						if (cur->isEnd == true)
						{
							Trie * temp = pwd;
							pwd = cur;
							pwd->parent = pwdParent;

							pwdParent = temp;//���� pwd�� parent�� �Ǵ°Ű�..
							return 1;
						}
					}
				}
			}
		}
	}

	return false;
}

int rmCnt = 0;
void rmRecur(Trie *t)
{

	for (int i = 0; i < 26; i++)
	{
		if (t->childs[i] != 0)
		{
			rmRecur(t->childs[i]);
			if (t->childs[i]->isEnd == true)
				rmCnt += 1;

			t->childs[i]->isEnd = false;
			t->childs[i] = 0;
		}
	}
}

int rm(char path[])//3
{
	int len = _strlen(path);
	rmCnt = 0;
	if (path[0] == '*') {
		rmRecur(pwd);
	}
	else
	{
		cur = pwd;
		//TODO 0��ȯ�ϴ°� chk
		for (int i = 0; i < len - 1; i++)
		{
			if (cur->childs[path[i] - 'a'] != 0)
				cur = cur->childs[path[i] - 'a']; //�̰� �ִ��� üũ�� �ؾ��Ҽ��� �ִ� ������ �׻� ls �����ѵ�. 0�� ��ȯ�Ҽ��������ϱ�??
			else return 0;
		}
		rmRecur(cur);
		//(*del)->isEnd = 0;

		if (cur->isEnd == true) {
			rmCnt += 1;
			cur->isEnd = false;
			cur = 0;
		}

		/*
		Trie **del = &pwd;
		//TODO 0��ȯ�ϴ°� chk
		for (int i = 0; i < len - 1; i++)
		{
		if((*del)->childs[path[i] - 'a']!=0)
		(*del) = (*del)->childs[path[i] - 'a']; //�̰� �ִ��� üũ�� �ؾ��Ҽ��� �ִ� ������ �׻� ls �����ѵ�. 0�� ��ȯ�Ҽ��������ϱ�??
		else return 0;
		}
		rmRecur(*del);
		//(*del)->isEnd = 0;
		del = 0;
		rmCnt += 1;//���ΰ�.

		*/

	}
	return rmCnt;
}


int lsCnt = 0;
void lsRecur(Trie *t)
{
	for (int i = 0; i < 26; i++)
	{
		if (t->childs[i] != 0)
		{
			lsRecur(t->childs[i]);
			if (t->childs[i]->isEnd == true)
				lsCnt += 1;

		}
	}
}

//���� ������ �ʿ��ϴ�.
int ls(char path[]) //4 �ϰ��̶� ����..
{
	//���ڿ��� ���´�.
	int len = _strlen(path);
	lsCnt = 0;

	if (path[0] == '*') {
		lsRecur(pwd);
	}
	else
	{
		cur = pwd;
		//TODO 0��ȯ�ϴ°� chk
		for (int i = 0; i < len - 1; i++)
		{
			if (cur->childs[path[i] - 'a'] != 0)
				cur = cur->childs[path[i] - 'a']; //�̰� �ִ��� üũ�� �ؾ��Ҽ��� �ִ� ������ �׻� ls �����ѵ�. 0�� ��ȯ�Ҽ��������ϱ�??
			else return 0;
		}
		if (cur->isEnd == true) lsCnt += 1;
		lsRecur(cur);
	}

	return lsCnt;

}