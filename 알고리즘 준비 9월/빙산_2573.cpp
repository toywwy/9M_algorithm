/*
문제 : 빙산
문제 번호: 2573
풀이법 : BFS
날짜 : 18.09.07
기타 : 
백준서버에서는 맞는데 ,, 컴파일러에서 안된다.
[line 120]
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;

int N, M;


class P
{
public:
	int x, y;
};

P q1[10000]; //빙하
P q2[10000]; //물

int front1, front2, rear1, rear2;

int arr[302][302];
bool visit[302][302];


int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};


void pushQ1(int x,int y)
{
	q1[rear1].x = x;
	q1[rear1].y = y;
	rear1++;
}

void pushQ2(int x, int y)
{
	q2[rear2].x = x;
	q2[rear2].y = y;
	rear2++;
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	

	cin >> N >> M;

	int input;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{

			cin >> input;
			if (input != 0)
			{
				q1[rear1].x = j;
				q1[rear1].y = i;
				rear1++;
			}
			arr[i][j] = input;
		}
	}

	int res =1;

	while (1)//2개로 나뉘어질때까지
	{
		
		while (front1 != rear1)
		{
			P p = q1[front1++];
			visit[p.y][p.x] = true;

			for (int i = 0; i < 4; i++)
			{
				if (p.x + dx[i] >= 0 && p.x + dx[i] < M &&
					p.y + dy[i] >= 0 && p.y + dy[i] < N &&
					arr[p.y + dy[i]][p.x + dx[i]] == 0 && 
					visit[p.y + dy[i]][p.x + dx[i]] == false)
				{
					//q2 집어 넣어야한다.
					q2[rear2].x = p.x + dx[i];
					q2[rear2].y = p.y + dy[i];
					rear2++;

					visit[p.y + dy[i]][p.x + dx[i]] = true;
				}
			}	
		}

		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				visit[i][j] = false;




		while (front2 != rear2)
		{
			P p = q2[front2++];
			for (int i = 0; i < 4; i++)
			{
				if (arr[p.y + dy[i]][p.x + dx[i]] > 0)
				{
					arr[p.y + dy[i]][p.x + dx[i]] -= 1; //이거 하는데 왜 rear가 감소??
				}
			}
		}
		
	


		front1 = rear1 = front2 = rear2 = 0;


		bool resChk = false;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (arr[i][j] != 0 && visit[i][j] ==false) {
					
					if (resChk)
					{
						cout << res << endl;
						return 0;
					}

					pushQ2(j, i);
					pushQ1(j, i);
					visit[i][j] = true;
					resChk = true;
				}

				while (front2 != rear2)
				{
					P p = q2[front2++];
					
					for (int k = 0; k < 4; k++)
					{

						if (p.x + dx[k] >= 0 && p.x + dx[k] < M &&
							p.y + dy[k] >= 0 && p.y + dy[k] < N &&
							arr[p.y + dy[k]][p.x + dx[k]] != 0 &&
							visit[p.y + dy[k]][p.x + dx[k]] == false)
						{
							//q2 집어 넣어야한다.
							pushQ1(p.x + dx[k], p.y + dy[k]);//여기에는 계속 축적해야함.
							pushQ2(p.x + dx[k], p.y + dy[k]);//여기에는 계속 축적해야함.

							visit[p.y + dy[k]][p.x + dx[k]] = true;
						}

					}

				}
			}
		}


		if (resChk == false)
		{
			cout << 0 << endl;
			break;
		}

		front2 = rear2 = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				visit[i][j] = false;

		if (front1 == rear1) break;

		res++;
	}

	return 0;
}
