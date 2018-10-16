/*
���� : 2252
���� ��ȣ: �� �����
Ǯ�̹� : ��������
��¥ : 18.10.11
��Ÿ : �������� ������ �ؾ���Ⱦ���...
ó������ ������ �갡 ���°ɷ� �����ϴ°� �ƴ϶�
�׷����� �׷����� ��� �׷��� queue�� �̿��ؼ� �����ϸ�ȴ�.


% ������ �ִ� ���� ���� �׷����̿����Ѵ�.

���ۿ� �׷����� �׷������� ���� Ǯ��������

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;
int N, M;

vector<int> front[32003];
queue<int> q;

int callCnt[32003];

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		front[a].push_back(b);//a�� b���� ���̴�.
		callCnt[b] += 1;
	}

	bool chk = true;
	while (chk)
	{
		chk = false;
		for (int i = 1; i <= N; i++)
		{
			if (callCnt[i] == 0)
			{
				callCnt[i] -= 1;
				q.push(i);
				chk = true; 
			}
		}

		while (!q.empty())
		{
			int p = q.front();
			cout << p << " ";
			
			for (int c : front[p]) callCnt[c] -= 1;
			q.pop();
		}
	}

	return 0;
}
