/*
문제 : 전화번호 목록
문제 번호: 5052
풀이법 : Hash MAP
날짜 : 18.09.20
기타 :

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>

using namespace std;


#define MAX_LEN 10
#define MAX_TABLE 16384

typedef struct
{
	char data[MAX_LEN + 1];//hash에서 부터 받은 key가 들어가는 곳이고
}Hash;

Hash tb[MAX_TABLE]; //테이블크기 ...얼마로 할가??? 문자열 길이에 따라서..
Hash sub[MAX_TABLE];

char arr[10002][MAX_LEN + 1];



int comp(char *str1, char *str2)
{
	int len1 = strlen(str1);
	int len2 = strlen(str2);

	for (int i = 0; i < len1 && i<len2; i++)
	{
		if (str1[i] < str2[i])
		{
			return 1;
		}
		else if (str1[i] > str2[i])
		{
			return -1;
		}
	}

	if (len1 > len2)
	{
		return -1;
	}
	else if (len1<len2)
	{
		return 1;
	}
	else
	{
		return 0;

	}
	//즉 0보다 작을떄 스왑하면댐
}


void quickSort(int first, int last)
{
	int pivot;
	int i;
	int j;
	int temp;

	if (first < last)
	{
		pivot = first;
		i = first;
		j = last;

		while (i < j)
		{
			while (comp(arr[i], arr[pivot]) >= 0 && i < last)
			{
				i++;
			}
			while (comp(arr[j], arr[pivot])<0)
			{
				j--;
			}
			if (i < j)
			{
				swap(arr[i], arr[j]);
			}
		}

		swap(arr[pivot], arr[j]);

		quickSort(first, j - 1);
		quickSort(j + 1, last);
	}
}
unsigned long myHash(const char *str)
{
	unsigned long hash = 5381;
	int c;

	while (c = *str++)
	{
		hash = (((hash << 5) + hash) + c) % MAX_TABLE;
	}

	return hash % MAX_TABLE; //테이블 크기엄청크네.. 그래도 분배가 잘됐나..?
}

int find(const char *data)
{
	unsigned long h = myHash(data);
	int cnt = MAX_TABLE;

	while (tb[h].data[0] != 0 && cnt--)
	{
		if (strcmp(tb[h].data, data) == 0)
		{
			return 1;//찾았다.
		}
		h = (h + 1) % MAX_TABLE;
	}
	return 0;//못찾았다.
}


//이부분 약간 생각이 필요한 부분이다.
int add(char *data)
{
	unsigned long h = myHash(data);//이부분에서 알아서 key를 만든다.

	while (tb[h].data[0] != 0)
	{
		if (strcmp(tb[h].data, data) == 0)
		{
			return 0;
		}
		h = (h + 1) % MAX_TABLE;//0을 찾을떄 까지 이동한다.
	}

	strcpy(tb[h].data, data);
	return 1;//제대로 삽입 OK
}

void initHash()
{
	for (int i = 0; i < MAX_TABLE; i++)
	{
		sub[i].data[0] = tb[i].data[0] = 0;
	}
}
int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N, n;
	cin >> N;

	while (N--)
	{

		initHash();

		cin >> n;
		bool res = false;
		int idx = 0;
		
		for (int i = 0; i < n; i++) cin >> arr[idx++];

		quickSort(0, n - 1);

		for (int k = 0; k < idx; k++)
		{	
			int len = strlen(arr[k]);

			for (int i = 0; i < len; i++)//길이만큼 다돌릴필요?
			{
				char ret[MAX_LEN + 1];

				strncpy(ret, arr[k], i + 1);//null은?
				ret[i + 1] = '\0';
				if (find(ret) == 1)//main은 전체 문자열만 들어있다.
				{
					//즉 지금 문자열의 접두사가 다른 문자열에 포함되느냐?
					res = true;
					break;
				}
			}

			if (res) break;
			else add(arr[k]);
			
		}

		if (res) cout << "NO" << endl;
		else cout << "YES" << endl;
		
	}

	return 0;
}
