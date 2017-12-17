/*
���� : ��������	
���� ��ȣ: 2468
Ǯ�̹� : BFS
��¥ : 17.12.17
��Ÿ :

Ʋ������ !

�����Ѱſ��µ� �Է� ������ �ּ�, �ִ븦 �����ؼ� �޾Ƽ� �׸�ŭ�� BFS�ϸ�ȴ�.
100*100 �̶� �����ϱ�..

���� ū��-> �ڿ� ���� �������� �� ū���� �������̶�� �����ߴ�.
������ �������� ������ �ٽ� ���� �Ҽ� �� �ִ� ��찡 ������ ���� ���̶� �ٽ� ������ �����.

*/

#include<iostream>

using namespace std;


int arr[101][101];
bool visit[101][101];


int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

//�ϴ� ��ã�� �ź��� ���������..

int qx[10002];
int qy[10002];

int front, rear;


int main(void)
{

	int N, px, py, input, nMin, nMax;
	nMin = 1000000;
	nMax = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> input;
			arr[i][j] = input;

			if (input < nMin) nMin = input;
			if (nMax < input) nMax = input;
		}

	}

	int pivot = nMin;//ó���� 50��������.
	int maxRes = 1;
	
	while(pivot<nMax)
	{
		int res = 0;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (arr[i][j] - pivot > 0 && visit[i][j] == 0)//��������
				{
					visit[i][j] = 1;

					qx[rear] = j;
					qy[rear++] = i;
					res++;


					while (front != rear)
					{
						px = qx[front];
						py = qy[front++];

						for (int i4 = 0; i4 < 4; i4++)
						{
							if (py + dy[i4] >= 0 && py + dy[i4] < N && px + dx[i4] >= 0 && px + dx[i4] < N)
							{
								if (arr[py + dy[i4]][px + dx[i4]] - pivot > 0 && visit[py + dy[i4]][px + dx[i4]] == 0)
								{

									visit[py + dy[i4]][px + dx[i4]] = 1;
									qx[rear] = px + dx[i4];
									qy[rear++] = py + dy[i4];

								}
							}

						}

					}
					rear = front = 0;

				}
			}
		}

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				visit[i][j] = 0;

		if (maxRes < res) maxRes = res;

		pivot++;
	}

	cout << maxRes << endl;
	return 0;
}
