/*
���� : ��ȭ��ȣ ���
���� ��ȣ: 5052
Ǯ�̹� : Hash MAP
��¥ : 18.09.20
��Ÿ :

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
	char data[MAX_LEN + 1];//hash���� ���� ���� key�� ���� ���̰�
}Hash;

Hash tb[MAX_TABLE]; //���̺�ũ�� ...�󸶷� �Ұ�??? ���ڿ� ���̿� ����..
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
	//�� 0���� ������ �����ϸ��
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

	return hash % MAX_TABLE; //���̺� ũ���ûũ��.. �׷��� �й谡 �ߵƳ�..?
}

int find(const char *data)
{
	unsigned long h = myHash(data);
	int cnt = MAX_TABLE;

	while (tb[h].data[0] != 0 && cnt--)
	{
		if (strcmp(tb[h].data, data) == 0)
		{
			return 1;//ã�Ҵ�.
		}
		h = (h + 1) % MAX_TABLE;
	}
	return 0;//��ã�Ҵ�.
}


//�̺κ� �ణ ������ �ʿ��� �κ��̴�.
int add(char *data)
{
	unsigned long h = myHash(data);//�̺κп��� �˾Ƽ� key�� �����.

	while (tb[h].data[0] != 0)
	{
		if (strcmp(tb[h].data, data) == 0)
		{
			return 0;
		}
		h = (h + 1) % MAX_TABLE;//0�� ã���� ���� �̵��Ѵ�.
	}

	strcpy(tb[h].data, data);
	return 1;//����� ���� OK
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

			for (int i = 0; i < len; i++)//���̸�ŭ �ٵ����ʿ�?
			{
				char ret[MAX_LEN + 1];

				strncpy(ret, arr[k], i + 1);//null��?
				ret[i + 1] = '\0';
				if (find(ret) == 1)//main�� ��ü ���ڿ��� ����ִ�.
				{
					//�� ���� ���ڿ��� ���λ簡 �ٸ� ���ڿ��� ���ԵǴ���?
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
