/*
문제 : 테트로미노
문제 번호: 14500
풀이법 : Brute force
날짜 : 18.6.27
기타 :

*/

#include<iostream>

using namespace std;

//19, 4
int pX[19][4] = {
	{ 0,1,0,1 },
	{ 0,1,2,3 },
	{ 0,0,0,0 },
	{ 1,0,1,2 },
	{ 0,1,2,1 },
	{ 0,1,1,1 },
	{ 0,0,0,1 },
	{ 0,0,1,1 },
	{ 0,0,1,1 },
	{ 0,1,1,2 },
	{ 0,1,1,2 },
	{ 0,0,0,1 },
	{ 0,1,1,1 },
	{ 0,0,1,2 },
	{ 0,0,1,2 },
	{ 0,1,2,2 },
	{ 0,0,0,1 },
	{ 0,1,2,2 },
	{ 0,1,1,1 }
};


int pY[19][4] = {
	{ 0,0,1,1 },
	{ 0,0,0,0 },
	{ 0,1,2,3 },
	{ 0,1,1,1 },
	{ 0,0,0,1 },
	{ 1,0,1,2 },
	{ 0,1,2,1 },
	{ 0,1,1,2 },
	{ 2,1,1,0 },
	{ 1,1,0,0 },
	{ 0,0,1,1 },
	{ 0,1,2,2 },
	{ 2,2,1,0 },
	{ 1,0,0,0 },
	{ 0,1,1,1 },
	{ 1,1,1,0 },
	{ 0,1,2,0 },
	{ 0,0,0,1 },
	{ 0,0,1,2 }
};



int limitX[19] = { 1, 3, 0, 2, 2, 1, 1, 1, 1, 2, 2, 1, 1, 2, 2, 2, 1, 2, 1 };
int limitY[19] = { 1, 0, 3, 1, 1, 2, 2, 2, 2, 1, 1, 2, 2, 1, 1, 1, 2, 1, 2 };



int N, M, mMax;


int arr[503][503];

int main(void)
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}


	int lx, ly, m;
	m = mMax = 0;


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			for (int k = 0; k < 19; k++)
			{

				lx = limitX[k];
				ly = limitY[k];

				//if (px + j <= lx && px + j >= 0 && py + i <= ly && py + i >= 0)
				if (j + lx >= M || i + ly >= N)
				{
					//현재 i,j 에서는 k 방향의 조각은 들어갈 수 없다.
					continue;
				}

				m = 0;
				for (int r = 0; r < 4; r++) m += arr[i + pY[k][r]][j + pX[k][r]];

				if (m > mMax) mMax = m;

			}
		}
	}

	cout << mMax << endl;


	return 0;
}