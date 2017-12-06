/*
���� : ���� ���ϱ�
���� ��ȣ: 2583
Ǯ�̹� : BFS
��¥ : 17.12.03
��Ÿ : ���̺귯�� �Ⱦ��� ���� Ǯ����

*/

#include<iostream>
#include<cstdio>

#define SIZE 100000
using namespace std;

int qx[100000];
int qy[100000];

int front;
int rear;

int arr[102][102];//maps
bool visit[102][102];//maps

//�� �Ʒ� �� ��
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int areaCnt = 0;
int resultArr[10100];
int resIdx;

int getMax(int a, int b)
{
	if (a > b) return a;
	else return b;
}

void QuickSort(int left, int right)
{
	int up = left;
	int down = right;
	int pivot = resultArr[(right+left)/2];
	while (up < down)
	{
		while (resultArr[up] < pivot) up++;
		while (resultArr[down] > pivot) down--;

		if (up <= down) swap(resultArr[up++], resultArr[down--]);
	}

	if (left < down) QuickSort(left, down);
	if (up < right) QuickSort(up, right);
}


int main(void)
{
	//5,7 , 3 
	//M, N, K �� �ȴ�.

	resIdx = 0;

	for (int i = 0; i < 102; i++)
	{
		for (int j = 0; j < 102; j++)
			resultArr[resIdx++]=arr[i][j] = 0;
	}
	resIdx = 0;
	int M, N, K;
	cin >> M >> N >> K;

	int lX, lY, rX, rY,totalArea=0;

	for (int i = 0; i < K; i++)
	{
		//���ΰ��� ��ǥ�� �ش�.
		//���ʾƷ� x,y �� ������ ������ x,y�� �־����Եȴ�.	
		
		scanf("%d %d %d %d", &lX, &lY, &rX, &rY);
		//���� �� x ������ y

		//������ x ���� y�� ����ȴ�.

		int firstX, lastX, firstY, lastY;
		firstX=lastX=firstY=lastY=0;

		bool isFirst=false;
		for (int y = lY; y < rY; y++)// ���� �ö󰡴� �������ΰ���.
		{
			for (int x = lX; x < rX; x++)
			{
				arr[y][x] = 1;
			}
		}

	}

	
	int resCnt = 0,locX,locY;
	areaCnt = 0;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] == 0 && visit[i][j] == 0)
			{
				rear = front = 0;

				areaCnt += 1;//���� ���� count �Ѵ�.
				visit[i][j] = 1;
				arr[i][j] = -1;

				qx[rear] = j;
				qy[rear] = i;
				rear += 1;


				while (front != rear)
				{
					locX = qx[front];
					locY = qy[front];
					front += 1;

					
					for (int i4 = 0; i4 < 4; i4++)
					{
						if (0 <= locY + dy[i4] && locY + dy[i4] < M && 0 <= locX + dx[i4] && locX + dx[i4] < N) {

							if (arr[locY + dy[i4]][locX + dx[i4]] == 0 && visit[locY + dy[i4]][locX + dx[i4]] == 0)
							{
								visit[locY + dy[i4]][locX + dx[i4]] = 1;
								arr[locY + dy[i4]][locX + dx[i4]] = -1;

								areaCnt += 1;//���� ���� ����.

								qx[rear] = locX + dx[i4];
								qy[rear] = locY + dy[i4];
								rear += 1;

							}
						}
					}
				}

				resultArr[resIdx++] = areaCnt;//���� �����Ѵ�.
				areaCnt = 0;//�ٽ� �ʱ�ȭ �ؾ��Ѵ�.
			}
		}
	}

	cout << resIdx<< endl;

	QuickSort(0, resIdx-1);
	for (int i = 0; i <resIdx; i++)
	{
		cout << resultArr[i] << " ";
	}
	cout << endl;



	return 0;
}
