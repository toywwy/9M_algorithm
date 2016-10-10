/*
문제 : 탈출
문제 번호: 3055
풀이법 : BFS
날짜 : 161010
기타 : BFS를 하는데 시작지점이 한군데가 아니였다.
그래서 입력을 받을때 그부분을 큐에다가 다 넣어서 시작을 했다.
나머지는 별다른 사항 없음

*/


#include<iostream>
#include<queue>
#define N 50
using namespace std;
typedef pair<int, int> P;



int arr[N + 2][N + 2];
bool visit[N + 2][N + 2];
queue<P> q;
queue<P> wq;


int main(void)
{
	int y, x;
	cin >> y >> x;

	char c;
	int si,sj, ei,ej,wi,wj;
	for (int i = 1; i <= y; i++)
	{
		for (int j = 1; j <= x; j++)
		{
			scanf(" %1c", &c);
			
			if (c == '.')
			{
				arr[i][j] = 1;
			}
			else if (c == '*')
			{
				arr[i][j] = -1;
				//visit[i][j] = 1;//이부분인가???

				wq.push(P(j, i));
			}
			else if (c == 'X')
			{
				arr[i][j] = 0;
				//visit[i][j] = 1;
			}
			else if (c =='S')
			{
				arr[i][j] = 1;
				si = i;
				sj = j;
			}
			else//D
			{
				arr[i][j] = 0;//못차 여긴
				ei = i;
				ej = j;
			}
		}
	}


	q.push(P(sj, si));//x,y로 들어간다.
	visit[si][sj] = 1;



	int dx[] = {0,0,-1,1};
	int dy[] = {-1,1,0,0};


	//물을 먼저 움직이고 , 그리고 도치를 움직여야한다.


	int res = 0;
	bool resFlag = 0;
	while (true)
	{
		res++;

		int wSize = wq.size();
		for(int kk = 0;  kk<wSize ;kk++)
		{
			P wp = wq.front(); wq.pop();
			for (int i = 0; i < 4; i++)
			{
				if (arr[wp.second + dy[i]][wp.first + dx[i]] == 1)//물도 땅에만 찰쑤있다. + 출발지점만
				{
					wq.push(P(wp.first + dx[i], wp.second + dy[i]));
					arr[wp.second + dy[i]][wp.first + dx[i]] = -1;
				}
			}
		}

		int size = q.size();
		for (int kk = 0; kk < size; kk++)
		{
			P p = q.front(); q.pop();

			for (int i = 0; i < 4; i++)
			{
				if ((p.second + dy[i]) == ei && (p.first + dx[i]) == ej)
				{
					resFlag = 1;
					break;
				}

				if (arr[p.second + dy[i]][p.first + dx[i]] == 1 && !visit[p.second + dy[i]][p.first + dx[i]])
				{
					q.push(P(p.first + dx[i], p.second + dy[i]));
					visit[p.second + dy[i]][p.first + dx[i]] = 1;
				}
			}
			if (resFlag)
				break;
		}

		if (resFlag)
		{
			/*while (!q.empty()) q.pop();
			while (!wq.empty()) wq.pop();*/

			break;
		}

		if (q.empty()) //고슴도치가 갖혀서 못나오게 되면 끝이다.
			break;

	}

	if (resFlag)
		cout << res << endl;
	else
		cout << "KAKTUS" << endl;
	

	return 0;
}
//KAKTUS 이동할 수 없다면

/*

비어있는 곳은 '.'로 표시되어 있고, 
물이 차있는 지역은 '*', 
돌은 'X'로 표시되어 있다. 
비버의 굴은 'D'로, 
고슴도치의 위치는 'S'로 나타내어져 있다.

S -> D

비버 굴엔 물이안찬댔어


*/