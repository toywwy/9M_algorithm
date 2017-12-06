/*
���� : ����Ʈ���̵�
���� ��ȣ: 7562
Ǯ�̹� : BFS
��¥ : 17.12.06
��Ÿ : ���̺귯���Ⱦ���


1. ó���� �ִ°� visit üũ ���߾���.
2. ó���� �ִ°� x,y �ݴ�� �־���.
3. ������ ���ǹ��� Ȯ���� �ؾ� �Ѵ� continue�� �ߴٰ� ��� ����.

*/

#include<iostream>

using namespace std;

//Night�� �̵����� 8����
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
		//src -> dest�� ����Ǵ°Ŵ�..

		int locX, locY;
		locY = locX = 0;
		arr[srcY][srcX] = 1;//BFS�� �׻� �ڱ� �ڽ� �ʱ�ȭ �߿�, ������ visit üũ����..
		bool res = false;

		while (rear != front)
		{

			locX = qx[front];
			locY = qy[front];
			front++;

			//������ �ϳ��� �������ؾ���...
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
