/*
문제 : 해적의 mini DB
문제 번호: https://swexpertacademy.samsung.com/common/swea/solvingPractice/userProblemDetail.do?contestProbId=AWZmkoc_DgoAAAHb&userSortingType=&solveclubId=&solveclubPassword=&attendYn=&rowNum=10&c=&cpp=&java=&py=&c=&cpp=&java=&py=&c=&cpp=&java=&py=&c=&cpp=&java=&py=&c=&cpp=&java=&py=&c=&cpp=&java=&py=&c=&cpp=&java=&py=&c=&cpp=&java=&py=&c=&cpp=&java=&py=&pageIndex=1
풀이법 : hash 2개 사용
날짜 : 18.10.21
기타 :
SOTECH hash에 delete가 없다.
delete 사용할떄 유의 해야 할것이 있다.

탐색을 tableKey[h].key[0] != 0
이런식으로 한다고 
delete할떄 = 0 을 대입해 버리면 그 뒤에 연결되어있던 hash 들이 끊기게 된다.
주의해야함!!!

pool로 객체 생성해서 사용할땐 꼭 isExist 사용해서 할당과 해제(flag)로 처리를 하도록 하자.

*/

#define LEN		33

#define KEY			0
#define VALUE		1

#define MAX_TABLE 200010
//최대 10만개 들어옴 ..충돌 안나게하려면 여유있게 선언 좋다.


typedef struct
{
	bool isExist;
	char key[LEN + 1]; //32 null 포함 X 
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
	dst[pos] = 0; //마지막에 널을 넣어준다.
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
	//해시 키때문에 두개를 둘수밖에없는듯..
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

	//value에도 추가로 삽입해야한다.
	addHashValue(key, data);



	return 1;
}



void init() {
	for (int i = 0; i < MAX_TABLE; i++)
	{
		tableKey[i].isExist = false;
		tableValue[i].isExist = false;

		tableKey[i].key[0] = 0; //0으로 판단하니깐.
		tableValue[i].data[0] = 0; //0으로 판단하니깐.
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
		deleteHashForKey(key, value);//지운 value를 가지고.	
		deleteHashForValue(key, value);
	}
	else
	{
		deleteHashForValue(key, value);
		deleteHashForKey(key, value);
	}
}

void mod(int field, char key[LEN + 1], char value[LEN + 1]) {

	if (field == KEY)//해당 키를 가진 data를 변경하면됨.
	{
		char data[LEN + 1];
		del(KEY, key, data);
		add(key, value);
	}
	else//해당 데이터를 가진 key를 변경하면됨.
	{
		char keyData[LEN + 1];
		del(VALUE, keyData, value);
		add(key, value);
	}
}