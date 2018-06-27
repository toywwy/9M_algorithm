/*
문제 : 토마토
문제 번호: 7576
풀이법 : BFS
날짜 : 18.06.27
기타 : 3차원 BFS이다.
한타임에 도는게 중요한데,
들어있는 값을 가지고 판단했다
= arr[y][x] + 1;

*/

#include<iostream>

using namespace std;



int arr[1002][1002];

class Queue
{
public:
	int x;
	int y;
	int value;
};

int SIZE = 100000;
Queue *list = new Queue[SIZE];
int front = 0;
int rear = 0;

void pushList(int x, int y, int value)
{
	//push할떄 사이즈가 넘어버리는 경
	Queue q;
	q.x = x;
	q.y = y;
	q.value = value;

	list[rear] = q;
	rear = (rear + 1) % SIZE;

}

Queue popList()
{
	int c = front;
	front = (front + 1) % SIZE;
	return list[c];
}

int compX[] = { 0,0,-1,1 };
int compY[] = { -1,1,0,0 };


void bfs(int x, int y, int value)
{//첨에 value 2로들어온다.

	for (int i = 0; i < 4; i++)
	{
		if (arr[y + compY[i]][x + compX[i]] == 0)
		{
			arr[y + compY[i]][x + compX[i]] = value;//2부터 시작한다.
			pushList(x + compX[i], y + compY[i], value + 1);

		}
	}

}


int main(void)
{
	int m; //가로
	int n; //세로


	for (int i = 0; i < 1002; i++)
	{
		for (int j = 0; j < 1002; j++)
		{
			arr[i][j] = -1;
		}
	}

	cin >> m >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	//-1 이 되는경우가있따 ...








	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (arr[i][j] == 1)
			{
				pushList(j, i, 2);
			}
		}
	}

	Queue q;
	while (rear != front)
	{
		q = popList();
		bfs(q.x, q.y, q.value);

	}
	int result = q.value;
	//가장 마지막에팝된거


	//마지막에 0만 체크해보면 

	int check = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (arr[i][j] == 0)
			{
				check = 1;
			}
		}
	}

	if (check == 1)
	{
		cout << "-1" << endl;
	}
	else
	{
		cout << (result - 2) << endl;
	}


	return 0;
}