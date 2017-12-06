/*
문제 : 영역 구하기
문제 번호: 2583
풀이법 : BFS
날짜 : 17.12.03
기타 : 라이브러리 안쓰고 문제 풀겠음

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

//위 아래 좌 우
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
	//M, N, K 로 된다.

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
		//점두개씩 좌표를 준다.
		//왼쪽아래 x,y 그 다음에 왼쪽위 x,y가 주어지게된다.	
		
		scanf("%d %d %d %d", &lX, &lY, &rX, &rY);
		//왼쪽 의 x 오른쪽 y

		//오른쪽 x 왼쪽 y로 가면된다.

		int firstX, lastX, firstY, lastY;
		firstX=lastX=firstY=lastY=0;

		bool isFirst=false;
		for (int y = lY; y < rY; y++)// 위로 올라가는 방향으로간다.
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

				areaCnt += 1;//영역 갯수 count 한다.
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

								areaCnt += 1;//영역 갯수 센다.

								qx[rear] = locX + dx[i4];
								qy[rear] = locY + dy[i4];
								rear += 1;

							}
						}
					}
				}

				resultArr[resIdx++] = areaCnt;//값을 저장한다.
				areaCnt = 0;//다시 초기화 해야한다.
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
