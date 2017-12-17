/*
문제 : 안전영역	
문제 번호: 2468
풀이법 : BFS
날짜 : 17.12.17
기타 :

틀린이유 !

간단한거였는데 입력 받을때 최소, 최대를 구분해서 받아서 그만큼만 BFS하면된다.
100*100 이라 작으니깐..

내가 큰값-> 뒤에 답이 떨어지면 그 큰값ㅇ ㅣ정답이라고 생각했다.
하지만 떨어지고 나서도 다시 증가 할수 가 있는 경우가 무수히 많을 것이라 다시 생각이 들었다.

*/

#include<iostream>

using namespace std;


int arr[101][101];
bool visit[101][101];


int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

//일단 답찾는 거부터 마느어놓고..

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

	int pivot = nMin;//처음에 50에서시작.
	int maxRes = 1;
	
	while(pivot<nMax)
	{
		int res = 0;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (arr[i][j] - pivot > 0 && visit[i][j] == 0)//안전공간
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
