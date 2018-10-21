/*
문제 : KSFS: Kenny Soft FileSystem
문제 번호: https://swexpertacademy.samsung.com/common/swea/solvingPractice/userProblemDetail.do?contestProbId=AWOlrV2PbdEAAAGq&userSortingType=&solveclubId=&solveclubPassword=&attendYn=&rowNum=10&c=&cpp=&java=&py=&c=&cpp=&java=&py=&c=&cpp=&java=&py=&c=&cpp=&java=&py=&c=&cpp=&java=&py=&c=&cpp=&java=&py=&c=&cpp=&java=&py=&c=&cpp=&java=&py=&c=&cpp=&java=&py=&c=&cpp=&java=&py=&pageIndex=1
풀이법 : TRIE
날짜 : 18.10.21
기타 : 
이것 또한 제거하는게 문제였다..

객체 pool로 생성했을때 전역변수라 0으로 다 초기화가 되는것이다.
만약 전역변수가 아니였을때 0이 아니라 그냥 쓰레기 값이다.
이걸 명심하고 init, delete 기타 등등 할떄
isExist를 추가해줘야한다.
진짜 중요하다.

*/

extern int _strlen(const char *str);
extern int _strcmp(const char *str1, const char *str2);

#define SIZE 200000

class Trie {
public:
	Trie * parent;//얘가 0이면 Base ( 즉 root 인거고..)
	Trie * childs[26];//알파벳 26개

	bool isStart;
	bool isEnd;//cd할때를 위해..? 음..
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
Trie *pwd;//cd 했을 때만 바뀌게 된다.

void init()
{
	idx = 0;
	base = newTrie();
	pwd = cur = base;
	pwd->parent = 0;
}
int mkdir(char name[])//1
{
	cur = pwd;//현재 위치에서
	int len = _strlen(name);
	for (int i = 0; i < len; i++)
	{
		int strIdx = name[i] - 'a';
		if (cur->childs[strIdx] == 0)
		{
			Trie * p = newTrie();//처음을 체크를 해야할까 안해도 도리까 ..일단 진행.
								 //p->parent = pwd->parent; //0 이면 현재는 base임.
			cur->childs[strIdx] = p;
			cur = cur->childs[strIdx];
		}
		else //객체가 이미 존재한다.
		{
			if (i == len - 1)//마지막인데
			{
				if (cur->childs[strIdx]->isEnd == true)
				{
					return 0;//입력 실패하지 않는 이상.
				}
			}
			else//마지막이 아니라면 문제 X
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
	//cd를 하면 pwd가 바뀌어야한다.
	//  '/' , "..", "(문자열)\t" 가 주어진다.

	if (path[0] == '/')//실패 없다.
	{
		pwd = base;
		return 1;
	}
	else if (path[0] == '.' && path[1] == '.')//".." 이미 루트에 있었다면 실패임.
	{
		if (pwd == base) return 0;
		else//하나 부모로 가야함. 이것 때문에 부모를 가지고 있어야겠다.
		{
			Trie *temp = pwd->parent;
			pwd = pwdParent;
			pwdParent = temp;
			return 1;
		}
	}
	else//나머지는 그냥 '\t' 빈 탭이 올수가 있고 문자열 + \t가 올수있는데.
	{
		//사전순에서 가장 빠른걸로 출력! 
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
				return 0;//실패 입력된 단어가 없다.
			}
		}

		if (cur->isEnd == true)
		{
			Trie * temp = pwd;
			pwd = cur;
			pwd->parent = pwdParent;
			pwdParent = temp;//이전 pwd가 parent가 되는거고..

			return 1;
		}
		else
		{
			//------------------------ 여기서 부터는 tab으로 사전순 접근해야한다.
			//isEnd를 찾을때까지 계속 이동해야한다...
			for (int k = 0; k < 12 - (len - 1); k++) //a부터 접근.
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

							pwdParent = temp;//이전 pwd가 parent가 되는거고..
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
		//TODO 0반환하는것 chk
		for (int i = 0; i < len - 1; i++)
		{
			if (cur->childs[path[i] - 'a'] != 0)
				cur = cur->childs[path[i] - 'a']; //이게 있는지 체크를 해야할수도 있다 하지만 항상 ls 가능한듯. 0을 반환할수도있으니깐??
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
		//TODO 0반환하는것 chk
		for (int i = 0; i < len - 1; i++)
		{
		if((*del)->childs[path[i] - 'a']!=0)
		(*del) = (*del)->childs[path[i] - 'a']; //이게 있는지 체크를 해야할수도 있다 하지만 항상 ls 가능한듯. 0을 반환할수도있으니깐??
		else return 0;
		}
		rmRecur(*del);
		//(*del)->isEnd = 0;
		del = 0;
		rmCnt += 1;//본인것.

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

//좀더 보강이 필요하다.
int ls(char path[]) //4 일것이라 추측..
{
	//문자열로 들어온다.
	int len = _strlen(path);
	lsCnt = 0;

	if (path[0] == '*') {
		lsRecur(pwd);
	}
	else
	{
		cur = pwd;
		//TODO 0반환하는것 chk
		for (int i = 0; i < len - 1; i++)
		{
			if (cur->childs[path[i] - 'a'] != 0)
				cur = cur->childs[path[i] - 'a']; //이게 있는지 체크를 해야할수도 있다 하지만 항상 ls 가능한듯. 0을 반환할수도있으니깐??
			else return 0;
		}
		if (cur->isEnd == true) lsCnt += 1;
		lsRecur(cur);
	}

	return lsCnt;

}