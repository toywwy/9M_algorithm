/*
���� :		�ΰ�
���� ��ȣ:	3108
Ǯ�̹� :		BFS
��¥ :		161014
��Ÿ :

*/

#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

#define N 1000
#define PADDING 501
using namespace std;

typedef pair<int, int> P;


bool map[N + 3][N + 3];
int arr[N + 3][N + 3][4];//�� ������ ����Ѵ�.
bool visit[N + 3][N + 3];

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

int main(void)
{
	int n, a, b, c, d;
	cin >> n;

	while (n--) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
		a += PADDING;
		b += PADDING;
		c += PADDING;
		d += PADDING;

		//(a,b) ���� (c,d) ���� �׵θ��� ������ȴ�.

		if (a > c)
			swap(a, c);
		if (b > d)
			swap(b, d);

		int x = a, y = b;//��������


		while (a <= c) {
			map[b][a] = 1;

			if (a == y)//ó��
			{
				arr[b][a][0] = 1;//����
				arr[b][a][3] = 1;//����
			}
			else if (a == c)//��
			{
				arr[b][a][0] = 1;//����
				arr[b][a][2] = 1;//����
			}
			else {
				arr[b][a][2] = 1;//����
				arr[b][a][3] = 1;//����
			}

			a += 1;
		}
		a -= 1;

		while (b <= d)// b y���� �����ϴ°Ŵ�.
		{
			map[b][a] = 1;
			if (b == y)// ó������ �������� �����ִ�. �׸��� ���ε� �����ִ�. ��� �Ʒ��� ������.
			{
				arr[b][a][2] = 1;//����
				arr[b][a][0] = 1;//����
			}
			else if (b == d) // ���������� ���� �����⋚��
			{
				arr[b][a][2] = 1;//����
				arr[b][a][1] = 1;//�Ʒ���
			}
			else
			{
				arr[b][a][0] = 1;//����
				arr[b][a][1] = 1;//�Ʒ���
			}
			b += 1;//���⿡�� y���� ���� ��Ų�ٴ� �ǹ̴� 
		}

		b -= 1;


		a = x;
		b = y; //�ʱ���ġ
		while (y <= d)
		{
			map[y][x] = 1;
			if (b == y)//ó������ �Ʒ��� �� ����.
			{
				arr[y][x][0] = 1;//���ΰ���
				arr[y][x][3] = 1;//������
			}
			else if (b == d) //���������� ���� �����⋚��
			{
				arr[y][x][1] = 1;//�Ʒ�
				arr[y][x][3] = 1;//������
			}
			else
			{
				arr[y][x][1] = 1;//�Ʒ�
				arr[y][x][0] = 1;//��
			}
			y += 1;
		}
		y -= 1;

		while (x <= c) {

			map[y][x] = 1;

			if (x == a)
			{
				arr[y][x][3] = 1;//������
				arr[y][x][1] = 1;//�Ʒ�
			}
			else if (x == c)//������
			{
				arr[y][x][2] = 1;//����
				arr[y][x][1] = 1;//�Ʒ�
			}
			else
			{
				arr[y][x][2] = 1;//����
				arr[y][x][3] = 1;//������
			}

			x += 1;
		}
		x -= 1;
	}

	queue<P> q;
	int res = 1;

	if (map[PADDING][PADDING])
		res = 0;
	else
		res = 1;//�ٸ� ������ �ѹ��̵��ϱ����ؼ� ������

	for (int i = 1; i <= N + 1; i++)
	{
		for (int j = 1; j <= N + 1; j++)
		{
			if (map[i][j] && !visit[i][j])
			{
				res++;
				q.push(P(j, i));
				visit[i][j] = 1;// i

				while (!q.empty())
				{
					P p = q.front(); q.pop();
					for (int k = 0; k < 4; k++)
					{
						if (arr[p.second][p.first][k] && !visit[p.second + dy[k]][p.first + dx[k]] && map[p.second + dy[k]][p.first + dx[k]])//���� ���� ���� ���� �����ִ����� üũ�Ѵ�.
						{
							visit[p.second + dy[k]][p.first + dx[k]] = 1;
							q.push(P(p.first + dx[k], p.second + dy[k]));
						}
					}
				}

			}
		}
	}

	cout << res - 1 << endl;//�������� �ѹ��� �����ϱ� ����

	return 0;
}

