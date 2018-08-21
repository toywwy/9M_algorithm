/*
문제 : 게임판 덮기
문제 번호: https://algospot.com/judge/problem/read/BOARDCOVER
풀이법 :
날짜 : 18.08.01
기타 : 

isInsert 필요없는 부분임.

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
int arr[22][22];


//방향은 4가지다.
int C, N, M,res;


int dx[4][3] = { 
	{0,0,1},
	{0,1,1},
	{1,0,0},
	{1,1,0}
};

int dy[4][3] = { 
	{0,1,1},
	{0,0,1},
	{0,0,1},
	{0,1,1}
};

void callRecur(int x, int y,bool isInsert);
void recur(int x, int y, bool isInsert);

void callRecur(int x, int y,bool isInsert)
{
	if (x + 1 > M) {
		recur(1, y + 1,isInsert);
	}
	else {
		recur(x + 1, y, isInsert);
	}
}

void recur(int x,int y,bool isInsert)
{

	if (x == M && y == N) {
		res++;
		return;
	}

	if (arr[y][x] != 1)
	{
		bool chk = true;
		for (int j = 0; j < 3; j++)
		{
			if (arr[y + dy[3][j]][x + dx[3][j]] != 1) {
				chk = false;
				break;
			}
		}

		if (chk == true)
		{

			for (int j = 0; j < 3; j++) arr[y + dy[3][j]][x + dx[3][j]] = 0;
			callRecur(x, y, true);
			for (int j = 0; j < 3; j++) arr[y + dy[3][j]][x + dx[3][j]] = 1;
		}

		callRecur(x, y, true);
	}
	else
	{
		for (int i = 0; i < 3; i++)
		{
			bool chk = true;
			for (int j = 0; j < 3; j++)
			{
				if (arr[y + dy[i][j]][x + dx[i][j]] != 1) {
					chk = false;
					break;
				}
			}

			if (chk == true)
			{

				for (int j = 0; j < 3; j++) arr[y + dy[i][j]][x + dx[i][j]] = 0;
				callRecur(x, y, true);
				for (int j = 0; j < 3; j++) arr[y + dy[i][j]][x + dx[i][j]] = 1;
			}

		}
	}
}



int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0);

	char input;
	cin >> C; // <=30
	for (int itr = 0; itr < C; itr++)
	{
		cin >> N >> M;//세로 가로 <=20
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				cin >> input;
				if (input == '#') arr[i][j] = 0;
				else arr[i][j] = 1;
			}
		}

		res = 0;
		recur(1, 1,false);

		cout << res << endl;

		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++)
				arr[i][j] = 0;

	}

	return 0;
}
