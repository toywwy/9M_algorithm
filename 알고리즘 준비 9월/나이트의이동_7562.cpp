/*
문제 : 나이트의이동
문제 번호: 7562
풀이법 : BFS
날짜 : 17.12.06
기타 : 라이브러리안쓰고


1. 처음에 넣는거 visit 체크 안했었다.
2. 처음에 넣는거 x,y 반대로 넣었다.
3. 나가는 조건문을 확실히 해야 한다 continue로 했다가 계속 갔다.

*/

#include<iostream>

using namespace std;

//Night의 이동방향 8방향
int dx[8] = { 1,2,2,1,-1,-2,-2,-1 };
int dy[8] = { 2,1,-1,-2,-2,-1,1,2 };

int qx[100002];
int qy[100002];
int front, rear;

int arr[303][303];

int main(void)
{
	int N;
	cin >> N;

	for (int itr = 1; itr <= N; itr++)
	{
		int srcX, srcY, destX, destY, mSize;

		rear = front = srcX = srcY = destX = destY = mSize = 0;
		cin >> mSize >> srcX >> srcY >> destX >> destY;

		qx[rear] = srcX;
		qy[rear] = srcY;
		rear++;

		if (srcX == destX &&srcY == destY) {
			cout << 0 << endl;
			continue;
		}
		//src -> dest로 가면되는거다..

		int locX, locY;
		locY = locX = 0;
		arr[srcY][srcX] = 1;//BFS는 항상 자기 자신 초기화 중요, 값이자 visit 체크까지..
		bool res = false;

		while (rear != front)
		{

			locX = qx[front];
			locY = qy[front];
			front++;

			//무조건 하나씩 다전진해야함...
			for (int i8 = 0; i8 < 8; i8++)
			{
				if (arr[locY + dy[i8]][locX + dx[i8]] == 0
					&& locY + dy[i8] >= 0 && locY + dy[i8] < mSize
					&& locX + dx[i8] >= 0 && locX + dx[i8] < mSize)
				{
					if (locY + dy[i8] == destY && locX + dx[i8] == destX)
					{
						cout << arr[locY][locX] << endl;
						rear = front = 0;
						res = true;
						break;
					}

					arr[locY + dy[i8]][locX + dx[i8]] = arr[locY][locX] + 1;

					qy[rear] = locY + dy[i8];
					qx[rear] = locX + dx[i8];
					rear++;

				}
			}
		}

		if (res == false) cout << -1 << endl;

		for (int i = 0; i < mSize+1; i++)
			for (int j = 0; j < mSize+1; j++)
				arr[i][j] = 0;


	}


	return 0;
}
