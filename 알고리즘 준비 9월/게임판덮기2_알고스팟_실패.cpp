/*
문제 :
문제 번호:
풀이법 :
날짜 :
기타 :

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

class P {
public:
	int x, y;
	P(int _x, int _y) :x(_x), y(_y) {

	}
	P() {}
};

char map[12][12];//게임판 크기
char arr[12][12];


int dx[4] = { 1,-1,1,-1 };
int dy[4] = { 1,-1,-1,1 };

int sx[4];
int sy[4];

/*
a = y - 1, b = x - 1;
a = y - 1, b = 0;
a = 0, b = x - 1;
*/

char visit[12][12];
vector<int> q;
vector<P> cList[4];

bool mapVisit[12][12];
int mMax;
int a, b, y, x,black;

void recur(int j, int i, int level);
void callRecur(int x, int y, int level)
{
	if (x + 1 > b) recur(1, y + 1, level);
	else recur(x + 1, y, level);
}

void recur(int j, int i, int level)
{
	mMax = max(level, mMax);

	if (i >= a -1 && j >= b-1) return;

	int rest = 0;
	for (int k = i; k < a; k++)
	{
		for (int l = 0; l < b; l++)
		{
			if (map[k][l] == '.') rest++;
		}
	}

	if (mMax >= rest/black + level) return;
	//나머지 빈칸을 모두 다더한다.

	bool chk1 = false;
	for (int k : q)//구해놓은 도형만 넣어보면 된다. 중복 제거용
	{
		bool chk = true;

		for (P p : cList[k])
		{
			if (p.y + i >= 0 && p.y + i < a && p.x + j >= 0 && p.x + j < b) //map 밖으로 벗어나는거 잡음
			{
				if (mapVisit[p.y + i][p.x + j] == true || map[p.y + i][p.x + j]=='#')//방문했거나, 놓을수 없는곳
				{
					chk = false;
					break; //k는 놓을수가 없다.
				}
			}
			else
			{
				chk = false;
				break;
			}
		}

		if (chk == true)//놓을수 있다면
		{
			for (P p : cList[k]) {
				mapVisit[p.y + i][p.x + j] =true;
				map[p.y + i][p.x + j] = '#';
			}
			callRecur(j, i, level + 1);
			for (P p : cList[k]) {
				mapVisit[p.y + i][p.x + j] =false;
				map[p.y + i][p.x + j] = '.';
			}
		}
		
	}

	callRecur(j, i, level);//얘는 놓지 못하고 들어가는 케이스이다.
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0);

	int N;
	cin >> N;




	for (int itr = 0; itr < N; itr++)
	{
		for (int i = 0; i < 4; i++) while (cList[i].size() > 0) cList[i].pop_back();

		while (!q.empty()) q.pop_back();

		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 12; j++)
			{
				visit[i][j] = mapVisit[i][j] = false;
				map[i][j] = arr[i][j]=0;
			}
		}

		cin >> a >> b >> y >> x;
		
		//초기값 세팅
		sx[0] = 0, sy[0] = 0;
		sx[1] = x - 1, sy[1] = y - 1;
		sx[2] = 0, sy[2] = y - 1;
		sx[3] = x - 1, sy[3] = 0;

		mMax = black = 0;



		//input map
		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < b; j++)
			{
				cin >> map[i][j];
				if(map[i][j]=='#') mapVisit[i][j] = true;
			}
		}

		//input block
		for (int i = 0; i < y; i++)
		{
			for (int j = 0; j < x; j++)
			{
				cin >> arr[i][j];
				if (arr[i][j] == '#') black += 1;
			}
		}



		//여기에서 미리 정해놓는거다. 어떤 회전만 사용해서할지...?
		//한블럭에서 4번 회전을 할수가 있다. 탐색하면된다. 
		for (int k = 0; k < 4; k++)
		{
			bool chk = true;
			if (k < 2)
			{
				for (int i = 0; i < y; i++)
				{
					for (int j = 0; j < x; j++)
					{
						if (arr[sy[k] + dy[k] * i][sx[k] + dx[k] * j] == '#')
							cList[k].push_back(P(j,i)); //굳이 -은 안놓는거라 상관 x


						if (arr[sy[k] + dy[k] * i][sx[k] + dx[k] * j] != visit[i][j])
						{
							visit[i][j] = arr[sy[k] + dy[k] * i][sx[k] + dx[k] * j];
							chk = false;
						}
					}
				}
			}
			else
			{
				for (int i = 0; i < x; i++) //반대로 가져간다.
				{
					for (int j = 0; j < y; j++)
					{
						if (arr[sy[k] + dy[k] * j][sx[k] + dx[k] * i] == '#')
						{
							cList[k].push_back(P(j,i));
						}

						if (arr[sy[k] + dy[k] * j][sx[k] + dx[k] * i] != visit[i][j])
						{
							visit[i][j] = arr[sy[k] + dy[k] * j][sx[k] + dx[k] * i];
							chk = false;
						}
					}
				}
			}

			if (chk == false) q.push_back(k);
		}

		recur(0, 0, 0);

		cout << mMax << endl;


	}


	return 0;
}


