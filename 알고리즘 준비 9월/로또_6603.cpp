/*
���� : �ζ�
���� ��ȣ: 6603
Ǯ�̹� : DFS
��¥ : 17.12.17
��Ÿ : 
������ DFS
*/

#include<iostream>

using namespace std;

int arr[51];
int visit[51];

int N;

void dfs(int level,int mem)
{
	if (level < 6)//���� 6�������Ѵ�.
	{
		for (int i = mem; i <= 49; i++)
		{
			if (arr[i] == 1 && visit[i] == 0)
			{
				visit[i] = 1;
				dfs(level + 1,i);
				visit[i] = 0;
			}
		}

	}
	else
	{
		for (int i = 1; i <= 49; i++)
			if(visit[i]==1) cout << i << " ";
		cout << endl;
	}

}

int main(void)
{
	int input;
	cin >> N;

	while (N > 0)
	{

		for (int i = 0; i < N; i++)
		{
			cin >> input;
			arr[input]=1;//������������ �Էµǰ� ���������� ����ؾ���.

		}

		dfs(0,1);

		for (int i = 1; i <= 49; i++) arr[i] = visit[i] = 0;
		cin >> N;
		cout << endl;
	}

	return 0;
}
