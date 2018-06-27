/*
���� :
���� ��ȣ:
Ǯ�̹� :
��¥ :
��Ÿ :

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;



int K, M, N,res;

bool arr[12][12];//12���� �л��� ����
bool visit[12];


int limit;

void recur(int level,int from)
{
	if (level < limit)
	{
		for (int i = 0; i < N; i++)
		{
			if (i == from) continue;

			if (arr[from][i] == true && visit[i] == false)//���⼭¦�� ��ã���Ŵ�.
			{
				visit[i] = true;

				if (level + 1 == limit)
				{
					res++;
					visit[i] = false;

					return;
				}


				for (int j = 0; j < N; j++)
				{

					if (visit[j] == false)
					{
						visit[j] = true;
						recur(level + 1, j);
						visit[j] = false;
					}
				}
				visit[i] = false;
			}
		}

	}

}

int main(void)
{
	cin >> K;
	int a, b;
	a = b = 0;
	for (int itr = 0; itr < K; itr++)
	{
		cin >> N >> M;

		res = 0;


		limit = N / 2;
		for (int i = 0; i < M; i++)
		{
			cin >> a >> b;
			arr[b][a] = arr[a][b] = true;
		}

		
		for (int i = 0; i < N; i++)
		{
			visit[i] = true;
			recur(0, i);
			visit[i] = false;
		}


		//12���� ���;��ϴµ� 24�������´�.

		int m = 1;
		for (int i = 1; i <= limit; i++)
			m *=i;

		for (int i = 0; i < limit; i++)
			res = res / 2;

		cout << res/m << endl;


		for (int i = 0; i < N; i++)
		{
			visit[i] = 0;
			for (int j = 0; j < N; j++) arr[i][j] = 0;
		}

	}

	return 0;
}
