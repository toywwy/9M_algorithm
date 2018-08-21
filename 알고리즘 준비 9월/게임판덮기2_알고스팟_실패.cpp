/*
���� :
���� ��ȣ:
Ǯ�̹� :
��¥ :
��Ÿ :

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

char map[12][12];//������ ũ��
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
	//������ ��ĭ�� ��� �ٴ��Ѵ�.

	bool chk1 = false;
	for (int k : q)//���س��� ������ �־�� �ȴ�. �ߺ� ���ſ�
	{
		bool chk = true;

		for (P p : cList[k])
		{
			if (p.y + i >= 0 && p.y + i < a && p.x + j >= 0 && p.x + j < b) //map ������ ����°� ����
			{
				if (mapVisit[p.y + i][p.x + j] == true || map[p.y + i][p.x + j]=='#')//�湮�߰ų�, ������ ���°�
				{
					chk = false;
					break; //k�� �������� ����.
				}
			}
			else
			{
				chk = false;
				break;
			}
		}

		if (chk == true)//������ �ִٸ�
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

	callRecur(j, i, level);//��� ���� ���ϰ� ���� ���̽��̴�.
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
		
		//�ʱⰪ ����
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



		//���⿡�� �̸� ���س��°Ŵ�. � ȸ���� ����ؼ�����...?
		//�Ѻ����� 4�� ȸ���� �Ҽ��� �ִ�. Ž���ϸ�ȴ�. 
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
							cList[k].push_back(P(j,i)); //���� -�� �ȳ��°Ŷ� ��� x


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
				for (int i = 0; i < x; i++) //�ݴ�� ��������.
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


