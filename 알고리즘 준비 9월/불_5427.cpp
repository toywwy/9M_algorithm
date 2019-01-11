/*
���� : ��
���� ��ȣ: 5427
Ǯ�̹� : BFS
��¥ : 19.01.11
��Ÿ :

1. ���� ������ ������ �ִ���
2. level ������ ó���� �ϴ°� ���� �߿��ߴ�.

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;

class P {
public:
	int x, y, v;
	P(int xx, int yy, int vv = 0) :x(xx), y(yy), v(vv) {}
	P() {}
};

char map[1004][1004];
int visit[1004][1004];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int T;
	cin >> T;

	/*
		'.': �� ����
		'#': ��
		'@': ������� ���� ��ġ
		'*': ��
	*/

	while (T--)
	{
		int C, R;
		char c;
		cin >> C >> R;
		queue<P> sq, fq;//�����Q �� Q
		P E;

		for (int i = 0; i <= R; i++)
		{
			for (int j = 0; j <= C; j++)
			{
				visit[i][j] = 0;
				if (i<1 || i>R || j<1 || j>C)
				{
					map[i][j] = '#';
					visit[i][j] = 3;
				}
				else
				{
					cin >> c;

					if (i == 1 || i == R || j == 1 || j == C)
					{
						if (c == '.')//�ⱸ
						{
							E = P(j, i);
						}
					}

					if (c == '@')
					{
						sq.push(P(j, i));
						visit[i][j] = 1;//����̰����ڸ� 1 
					}
					else if (c == '*')
					{
						fq.push(P(j, i));
						visit[i][j] = 2;//���̰��ڸ� 2
					}
					else if (c == '#')
					{
						visit[i][j] = 3;
					}

					map[i][j] = c;
				}
			}
		}




		int res = 0;
		int level = 0;
		while (!sq.empty())//�ֱ� �ٶ��������� �ⱸ�� �������ٸ� ��..
		{
			while (true)
			{
				if (!fq.empty())
				{
					P f = fq.front();
					if (f.v == level) {
						fq.pop();
						for (int i = 0; i < 4; i++)
						{
							if (visit[dy[i] + f.y][dx[i] + f.x] < 2)
							{
								visit[dy[i] + f.y][dx[i] + f.x] = 2;
								fq.push(P(dx[i] + f.x, dy[i] + f.y, f.v + 1));
							}
						}
					}
					else
						break;
				}
				else break;

			}

			while (true)
			{
				if (!sq.empty())
				{
					P s = sq.front();
					if (s.v == level)
					{
						sq.pop();

						if (s.x == 1 || s.x ==C ||  s.y ==1 || s.y == R )
						{
							res = s.v + 1;
							while (!sq.empty()) sq.pop();

							break;

						}

						for (int i = 0; i < 4; i++)
						{
							if (visit[dy[i] + s.y][dx[i] + s.x] == 0)
							{
								visit[dy[i] + s.y][dx[i] + s.x] = 1;
								sq.push(P(dx[i] + s.x, dy[i] + s.y, s.v + 1));
							}
						}
					}
					else
						break;
				}
				else break;
			}
			level++;
		}
		//IMPOSSIBLE

		if (res > 0)
			cout << res << endl;
		else
			cout << "IMPOSSIBLE" << endl;

	}
	return 0;
}
