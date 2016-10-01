/*
문제 : 성곽
문제 번호: 2234
풀이법 : 재귀
날짜 : 161001
기타 : visit의 위치가 중요한 영향을 끼친다. 그리고
3번쨰 답을 출력하는데 ....모르고 마지막 줄을 검사를안했다. 둘다 x-1 y
y-1 x 일떄는 조사를 했었어야했다.

출력
1. 방의갯수 - 그룹의 갯수
2. 가장 넓은 방의 넓이 - 그룹을 지을때 가장 넓은 방은 어떤 방?

3. 하나의 벽을 제거하여 얻을수 있는 가장 넓은방...

*/



#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

typedef unsigned short usint;
typedef unsigned char uchar;

typedef pair<uchar, uchar> P;

uchar arr[52][52];//여기서 그룹도 같이 만들자.

usint group[52][52];//여기서 그룹도 같이 만들자.
bool v[52][52];
usint cnt[2502];

int gCnt = 1;//1부터 그룹을 짓게 만들지뭐?
			 //사실 재 사용해도 되긴하는데
int mCnt = 0;
int mV = 0;
bool check[16][4]{
	{ 0,0,0,0 },//ignore
	{ 1,0,0,0 },//1
	{ 0,1,0,0 },//2
	{ 1,1,0,0 },//3
	{ 0,0,1,0 },//4
	{ 1,0,1,0 },//5
	{ 0,1,1,0 },//6
	{ 1,1,1,0 },//7
	{ 0,0,0,1 },//8
	{ 1,0,0,1 },//9
	{ 0,1,0,1 },//10
	{ 1,1,0,1 },//11
	{ 0,0,1,1 },//12
	{ 1,0,1,1 },//13
	{ 0,1,1,1 },//14
	{ 1,1,1,1 }///15
};

int dx[] = { -1,0,1,0 }; //왼쪽 위 오른쪽 아래
int dy[] = { 0,-1,0,1 }; //이런식으로 탐색


void recur(int x, int y)
{
	for (int k = 0; k < 4; k++)
	{
		if (!check[arr[y][x]][k])//1이 아니면 0이여서 벽이 없다면
			if (!v[y + dy[k]][x + dx[k]])//방문 하지 않은 곳이라면
			{//p.first + dy[k]>=1 && p.first + dy[k]<=row && p.second + dx[k]>=1 && p.second + dx[k]<= col &&
				group[y + dy[k]][x + dx[k]] = gCnt;
				v[y + dy[k]][x + dx[k]] = 1;
				cnt[gCnt] += 1;
				recur(x + dx[k], y + dy[k]);
			}
	}

}
int main(void)
{
	int row, col;
	cin >> col >> row;//row 줄, col 열

					  //입력
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= col; j++)
			scanf("%d", &arr[i][j]);



	queue<P> q;

	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			if (!v[i][j])
			{
				v[i][j] = 1;
				group[i][j] = gCnt;
				cnt[gCnt] += 1;

				recur(j, i);

				if (mCnt < cnt[gCnt])
					mCnt = cnt[gCnt];
				gCnt += 1;
			}
		}
	}

	mV = mCnt;
	//TODO arr 가지고 만들어진 그룹을 가지고 가공을하자.

	//배열을 아래 우측 확인하면서 탐색한다. 다르면 합쳐서 최대값에 적용
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			if (j <col)
				if (group[i][j] != group[i][j + 1])//다른 그룹일때 합쳐봄
					if (mV < (cnt[group[i][j]] + cnt[group[i][j + 1]]))
						mV = cnt[group[i][j]] + cnt[group[i][j + 1]];
			if (i <row)
				if (group[i][j] != group[i + 1][j])//다른 그룹일때 합쳐봄
					if (mV < (cnt[group[i][j]] + cnt[group[i + 1][j]]))
						mV = cnt[group[i][j]] + cnt[group[i + 1][j]];
		}
	}


	cout << gCnt - 1 << endl;
	cout << mCnt << endl;
	cout << mV << endl;

	return 0;
}


