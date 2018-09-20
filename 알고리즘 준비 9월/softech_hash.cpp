#include <stdio.h>
#include <string.h>
#include <memory.h>

#define MAX_KEY 64
#define MAX_DATA 128
#define MAX_TABLE 4096

typedef struct
{
	char key[MAX_KEY + 1];//hash에서 부터 받은 key가 들어가는 곳이고
	char data[MAX_DATA + 1];//실제 data가 들어가는 부분이다.
}Hash;

Hash tb[MAX_TABLE]; //테이블크기 ...얼마로 할가??? 문자열 길이에 따라서..

unsigned long hash(const char *str)
{
	unsigned long hash = 5381;
	int c;

	while (c = *str++)
	{
		hash = (((hash << 5) + hash) + c) % MAX_TABLE;
	}

	return hash % MAX_TABLE; //테이블 크기엄청크네.. 그래도 분배가 잘됐나..?
}

int find(const char *key, char *data)
{
	unsigned long h = hash(key);
	int cnt = MAX_TABLE;

	while (tb[h].key[0] != 0 && cnt--)
	{
		if (strcmp(tb[h].key, key) == 0)
		{
			strcpy(data, tb[h].data);
			return 1;
		}
		h = (h + 1) % MAX_TABLE;
	}
	return 0;
}


//이부분 약간 생각이 필요한 부분이다.
int add(const char *key, char *data)
{
	unsigned long h = hash(key);//이부분에서 알아서 key를 만든다.

	while (tb[h].key[0] != 0)
	{
		if (strcmp(tb[h].key, key) == 0)
		{
			return 0;
		}

		h = (h + 1) % MAX_TABLE;//0을 찾을떄 까지 이동한다.
	}
	strcpy(tb[h].key, key);
	strcpy(tb[h].data, data);

	return 1;//제대로 삽입 OK
}


int main(int argc, char* argv[])
{
	int T, N, Q;

	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; test_case++)
	{
		memset(tb, 0, sizeof(tb));
		scanf("%d", &N);
		char k[MAX_KEY + 1];
		char d[MAX_DATA + 1];

		for (int i = 0; i < N; i++)
		{
			scanf("%s %s\n", &k, &d);
			add(k, d);
		}

		printf("#%d\n", test_case);

		scanf("%d", &Q);
		for (int i = 0; i < Q; i++)
		{
			char k[MAX_KEY + 1];
			char d[MAX_DATA + 1];

			scanf("%s\n", &k);

			if (find(k, d))
			{
				printf("%s\n", d);
			}
			else
			{
				printf("not find\n");
			}
		}
	}
	return 0;
}