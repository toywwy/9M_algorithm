/*
���� : ������ mini DB
���� ��ȣ: https://swexpertacademy.samsung.com/common/swea/solvingPractice/userProblemDetail.do?contestProbId=AWZmkoc_DgoAAAHb&userSortingType=&solveclubId=&solveclubPassword=&attendYn=&rowNum=10&c=&cpp=&java=&py=&c=&cpp=&java=&py=&c=&cpp=&java=&py=&c=&cpp=&java=&py=&c=&cpp=&java=&py=&c=&cpp=&java=&py=&c=&cpp=&java=&py=&c=&cpp=&java=&py=&c=&cpp=&java=&py=&pageIndex=1
Ǯ�̹� : hash 2�� ���
��¥ : 18.10.21
��Ÿ :
SOTECH hash�� delete�� ����.
delete ����ҋ� ���� �ؾ� �Ұ��� �ִ�.

Ž���� tableKey[h].key[0] != 0
�̷������� �Ѵٰ� 
delete�ҋ� = 0 �� ������ ������ �� �ڿ� ����Ǿ��ִ� hash ���� ����� �ȴ�.
�����ؾ���!!!

pool�� ��ü �����ؼ� ����Ҷ� �� isExist ����ؼ� �Ҵ�� ����(flag)�� ó���� �ϵ��� ����.

*/

#define LEN		33

#define KEY			0
#define VALUE		1

#define MAX_TABLE 200010
//�ִ� 10���� ���� ..�浹 �ȳ����Ϸ��� �����ְ� ���� ����.


typedef struct
{
	bool isExist;
	char key[LEN + 1]; //32 null ���� X 
	char data[LEN + 1];
}Hash;

Hash tableKey[MAX_TABLE];
Hash tableValue[MAX_TABLE];

int _strlen(const char *str)
{
	int ret = 0;
	while (str[ret])ret++;
	return ret;
}
int _strcmp(const char *str1, const char *str2)
{
	int pos = 0;
	while (str1[pos] && str2[pos] && str1[pos] == str2[pos])pos++;
	if (!str1[pos] && !str2[pos])return 0;
	if (!str1[pos])return -1;
	if (!str2[pos])return 1;
	return str1[pos] - str2[pos];
}
void _strcpy(char *dst, const char *src)
{
	int pos = 0;
	while (src[pos])
	{
		dst[pos] = src[pos];
		pos++;
	}
	dst[pos] = 0; //�������� ���� �־��ش�.
}
void _strcat(char *dst, const char *src)
{
	_strcpy(dst + _strlen(dst), src);
}



unsigned long myHash(const char *str)
{
	unsigned long hash = 5381;
	int c;

	while (c = *str++)
	{
		hash = (((hash << 5) + hash) + c) % MAX_TABLE;
	}

	return hash % MAX_TABLE;
}


int ModifyHashForKey(const char *key, char *data)
{
	unsigned long h = myHash(key);
	int cnt = MAX_TABLE;

	while (tableKey[h].key[0] != 0 && cnt--)
	{
		if (tableKey[h].isExist == 1 && _strcmp(tableKey[h].key, key) == 0)
		{
			_strcpy(tableKey[h].data, data);

			return 1;
		}
		h = (h + 1) % MAX_TABLE;
	}
	return 0;
}

int ModifyHashForValue(char *key, const char *data)
{
	unsigned long h = myHash(data);
	int cnt = MAX_TABLE;

	while (tableValue[h].data[0] != 0 && cnt--)
	{
		if (tableValue[h].isExist == 1 && _strcmp(tableValue[h].data, data) == 0)
		{
			_strcpy(tableValue[h].key, key);

			return 1;
		}
		h = (h + 1) % MAX_TABLE;
	}
	return 0;
}


int deleteHashForKey(const char *key, char *data)
{
	unsigned long h = myHash(key);
	int cnt = MAX_TABLE;

	while (tableKey[h].key[0] != 0 && cnt--)
	{
		if (tableKey[h].isExist == 1 && _strcmp(tableKey[h].key, key) == 0)
		{
			_strcpy(data, tableKey[h].data);
			tableKey[h].isExist = false;
			return 1;
		}
		h = (h + 1) % MAX_TABLE;
	}
	return 0;
}

int deleteHashForValue(char *key, const char *data)
{
	unsigned long h = myHash(data);
	int cnt = MAX_TABLE;

	while (tableValue[h].data[0] != 0 && cnt--)
	{
		if (tableValue[h].isExist == 1 && _strcmp(tableValue[h].data, data) == 0)
		{
			_strcpy(key, tableValue[h].key);
			tableValue[h].isExist = false;

			return 1;
		}
		h = (h + 1) % MAX_TABLE;
	}
	return 0;
}
int findHashForKey(const char *key, char *data)
{
	unsigned long h = myHash(key);
	int cnt = MAX_TABLE;

	while (tableKey[h].key[0] != 0 && cnt--)
	{
		if (tableKey[h].isExist == 1 && _strcmp(tableKey[h].key, key) == 0)
		{
			_strcpy(data, tableKey[h].data);
			return 1;
		}
		h = (h + 1) % MAX_TABLE;
	}
	return 0;
}
int findHashForValue(char *key, const char *data)
{
	//�ؽ� Ű������ �ΰ��� �Ѽ��ۿ����µ�..
	unsigned long h = myHash(data);
	int cnt = MAX_TABLE;

	while (tableValue[h].data[0] != 0 && cnt--)
	{
		if (tableValue[h].isExist == 1 && _strcmp(tableValue[h].data, data) == 0)
		{
			_strcpy(key, tableValue[h].key);
			return 1;
		}
		h = (h + 1) % MAX_TABLE;
	}
	return 0;
}

int addHashValue(char *key, char *data)
{
	unsigned long h = myHash(data);

	while (tableValue[h].data[0] != 0)
	{
		if (tableValue[h].isExist == 1 && _strcmp(tableValue[h].data, data) == 0)
		{
			return 0;
		}

		h = (h + 1) % MAX_TABLE;
	}

	tableValue[h].isExist = true;
	_strcpy(tableValue[h].key, key);
	_strcpy(tableValue[h].data, data);

	return 1;
}
int addHash(char *key, char *data)
{
	unsigned long h = myHash(key);

	while (tableKey[h].key[0] != 0)
	{
		if (tableKey[h].isExist == 1 && _strcmp(tableKey[h].key, key) == 0)
		{
			return 0;
		}

		h = (h + 1) % MAX_TABLE;
	}
	tableKey[h].isExist = true;
	_strcpy(tableKey[h].key, key);
	_strcpy(tableKey[h].data, data);

	//value���� �߰��� �����ؾ��Ѵ�.
	addHashValue(key, data);



	return 1;
}



void init() {
	for (int i = 0; i < MAX_TABLE; i++)
	{
		tableKey[i].isExist = false;
		tableValue[i].isExist = false;

		tableKey[i].key[0] = 0; //0���� �Ǵ��ϴϱ�.
		tableValue[i].data[0] = 0; //0���� �Ǵ��ϴϱ�.
	}
}

void add(char key[LEN + 1], char value[LEN + 1]) {

	addHash(key, value);
}

void get(int field, char key[LEN + 1], char value[LEN + 1]) {
	if (field == KEY)
	{
		findHashForKey(key, value);
	}
	else
	{
		findHashForValue(key, value);
	}
}

void del(int field, char key[LEN + 1], char value[LEN + 1]) {

	if (field == KEY)
	{
		deleteHashForKey(key, value);//���� value�� ������.	
		deleteHashForValue(key, value);
	}
	else
	{
		deleteHashForValue(key, value);
		deleteHashForKey(key, value);
	}
}

void mod(int field, char key[LEN + 1], char value[LEN + 1]) {

	if (field == KEY)//�ش� Ű�� ���� data�� �����ϸ��.
	{
		char data[LEN + 1];
		del(KEY, key, data);
		add(key, value);
	}
	else//�ش� �����͸� ���� key�� �����ϸ��.
	{
		char keyData[LEN + 1];
		del(VALUE, keyData, value);
		add(key, value);
	}
}