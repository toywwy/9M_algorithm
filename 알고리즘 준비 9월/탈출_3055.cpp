/*
���� : Ż��
���� ��ȣ: 3055
Ǯ�̹� : BFS
��¥ : 161010
��Ÿ : BFS�� �ϴµ� ���������� �ѱ����� �ƴϿ���.
�׷��� �Է��� ������ �׺κ��� ť���ٰ� �� �־ ������ �ߴ�.
�������� ���ٸ� ���� ����

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
				//visit[i][j] = 1;//�̺κ��ΰ�???

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
				arr[i][j] = 0;//���� ����
				ei = i;
				ej = j;
			}
		}
	}


	q.push(P(sj, si));//x,y�� ����.
	visit[si][sj] = 1;



	int dx[] = {0,0,-1,1};
	int dy[] = {-1,1,0,0};


	//���� ���� �����̰� , �׸��� ��ġ�� ���������Ѵ�.


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
				if (arr[wp.second + dy[i]][wp.first + dx[i]] == 1)//���� ������ �����ִ�. + ���������
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

		if (q.empty()) //����ġ�� ������ �������� �Ǹ� ���̴�.
			break;

	}

	if (resFlag)
		cout << res << endl;
	else
		cout << "KAKTUS" << endl;
	

	return 0;
}
//KAKTUS �̵��� �� ���ٸ�

/*

����ִ� ���� '.'�� ǥ�õǾ� �ְ�, 
���� ���ִ� ������ '*', 
���� 'X'�� ǥ�õǾ� �ִ�. 
����� ���� 'D'��, 
����ġ�� ��ġ�� 'S'�� ��Ÿ������ �ִ�.

S -> D

��� ���� ���̾������


*/