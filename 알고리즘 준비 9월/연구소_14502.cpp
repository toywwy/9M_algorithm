/*
문제 : 연구소
문제 번호: 14502
풀이법 : BFS
날짜 : 18.06.23
기타 :


*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;


//벽을 3개 세운 뒤, 바이러스가 퍼질 수 없는 곳을 안전 영역이라고 한다.위의 지도에서 안전 영역의 크기는 27이다.
//
//연구소의 지도가 주어졌을 때 얻을 수 있는 안전 영역 크기의 최대값을 구하는 프로그램을 작성하시오.
//벽을 꼭 3개를 새워서 가장 많이 막을수있는 최대값..
//갯수구하는건 마지막에 BFS를 돌려서 구하면되고 일딴 그전에 어디에 벽3개를 새워 막을지 결정해야한다.
//정답이 0개로 나오는 것도있겠다.막을수가 없는 것이지.
//어떻게 찾지.
//맵이 8*8이다 전체 탐색가능하다.
//최대값을 구하는 것이니 <- 최단경로다 BFS로 진행


int arr[10][10];

int main(void)
{
	int N, M;//세로 가로

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}


	int bound = M*N;
	int x1, x2, x3;
	int y1, y2, y3;

	x1 = x2 = x3 = y1 = y2 = y3 = 0;

	//i j k 연속으로 해도되는 이유 조합이기 떄문
	for (int i = 0; i < bound; i++)
	{
		if (i%M == 0) y1++;
		else x1++;//0이 아니라면 x증가.

		if(arr[y1][x1]==0)
			arr[y1][x1]=1;//벽 만듬 어떻게해야하냐?
		else continue;

		for (int j = i; j < bound; j++)
		{
			x2 = x1;
			y2 = y1;
			if (j%M == 0) y2++;
			else x2++;//0이 아니라면 x증가.
			
			if (arr[y2][x2] == 0)
				arr[y2][x2] = 1;//벽 만듬 어떻게해야하냐?
			else continue;

			for (int k = j; k < bound; k++)
			{
				x3 = x2;
				y3 = y2;

				if (k%M == 0) y3++;
				else x3++;//0이 아니라면 x증가.

				if (arr[y3][x3] == 0)
					arr[y3][x3] = 1;//벽 만듬 어떻게해야하냐?
				else continue;
				
				//BFS 돌려서 값을 저장한다.
				//이제 BFS 돌리면될듯



			}
		}
	}



	return 0;
}
