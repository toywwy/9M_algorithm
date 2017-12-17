/*
문제 : 유기농배추
문제 번호: 1012
풀이법 : bfs
날짜 : 17.12.17
기타 : 별다른것 X
큐룰 2500개 전체 쓰는것같았다.근데 2500개 못쓸탠데... 왜큐가터졋찌.
*/

#include<iostream>

using namespace std;

bool arr[52][52];
bool visit[52][52];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

int qx[2555];
int qy[2555];

int front;
int rear;


int main(void)
{

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		//가로 M 세로 N
		int M, N, K, x, y, px, py, res=0;
		cin >> M >> N >> K;

		for (int input = 0; input < K; input++)
		{
			cin >> x >> y;
			arr[y][x] = 1;
		}

		//bfs 짜야함.
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{

				if (arr[i][j] == 1 && visit[i][j] == 0)
				{
					visit[i][j] = 1;

					qx[rear] = j;
					qy[rear++] = i;

					res += 1;

					while (front != rear)
					{
						//popX popY
						px = qx[front];
						py = qy[front++];

						for (int i4 = 0; i4 < 4; i4++)
						{

							if (py + dy[i4] >= 0 && py + dy[i4] < N && px + dx[i4] >= 0 && px + dx[i4] < M)
							{
								if (arr[py + dy[i4]][px + dx[i4]] == 1 && visit[py + dy[i4]][px + dx[i4]] == 0)
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
		{
			for (int j = 0; j < M; j++)
			{
				arr[i][j] = visit[i][j] = 0;
			}
		}

		cout << res << endl;


	}
	return 0;
}
