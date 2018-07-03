/*
���� : �ִ�����
���� ��ȣ: 6086
Ǯ�̹� : �ִ�����
��¥ : 18.07.02
��Ÿ : �������.
����� ����Ʈ
1) ������ �Ž��� ���� �κп� ���� ����.
2) �ߺ� �Է��� ���Ǵ� �κ�
3) (���� ���Ա� ������ �̹� ���Դ� �κ��� �о�� ������ ��������)
������ �������� B - C - D ��°��ִ�.
C <- D�� �̹� 3 �̾���. �׷��� C -> D�� ���� �������� C�� ���� �����ɱ�?
�����ȴ� B���� �󸶰� ���Ե� �����°� ���� �����̴�. (���� ���Ա� ������ �̹� ���Դ� �κ��� �о�� ������ ��������)

������̶�� ������ flow �� + - mMin�� ���־���Ѵ�.
---------

+=��...
=+�� �Ǽ��� �ع����� ������ ��û���� ���..

��ü�� �������� ����ߴ�.

�׳� ������̶�� �����ϰ� �ۼ��� �߾�����ߴ�.

���ʿ� ������� ����ߴٸ� �̷��� ���� �ʾ�����.

capacity[a][b] = capacity[b][a] += c;//�ݴ�� ���°�

flow[mPrev[k]][k] += mMin;
flow[k][mPrev[k]] -= mMin;

��������� �帣�� ������ ������ ���־�� �Ѵ�.


flow �� ������� ����? �׻� if�� ��� �����ϴ�.
if(capacity[node][next] - flow[node][next] > 0 && mPrev[next] == -1)


�׷��ٸ� ������ ����?? �ϴ� flow�� ���� capacity���� Ŭ������. ���ʿ� �׷� ���� �������⶧����
�� ==0�� �Ǵ°�츸 ������.

if(capacity[node][next] - flow[node][next] != 0 && mPrev[next] == -1)
�̰� ���� �´�.

if( mPrev[next] == -1) ���ϰ� �Ǹ� �ð��ʰ�.

������ �Ž��� �ö󰥶� �� �׻󰥼��ֳĴ°ǵ�..? flow�� 0�̸� ������ �����ϴ°Ը´�.

�׸��� flow�� 0�ε� ������ ���������µ� ���Եȴ�. �� if���� ������..

�� ��������� ���°� �´µ� flow�� ������ �Ǵ°� �ǹ̰� ����.
capacity�� �ִ��� ������ �����̰����ϰ� �� 

-------------------------------
A�� B ���̿� �������� �߰��ϴ� �Ͱ� B�� A ���̿� �������� �߰��ϴ� �� ���� �ɷ� ������ �� �����ϴ�.
���� �ƴ϶��, ������ �������� ù° ���������� ��° ���������� �ܹ������θ� �带 �� �ִٴ� ������ �߰����ּ���.
5
B A 3
C B 3
D C 5
Z D 4
Z B 6

answer: 3
------------------------------
*/

#include<iostream>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;

#define ASC 130

vector<int> adj[ASC];

int flow[ASC][ASC];
int capacity[ASC][ASC];//�뷮�� ���� �޴´�.

int N;

int main(void) {

	cin >> N;

	char a, b;
	int c;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b >> c;
		//��������� ���̵��ǰԵȴ�.
		adj[a].push_back(b);
		adj[b].push_back(a);

		//���� �ߺ��Է� += ���� ��ΰ� �����Ѵ�.
		capacity[a][b] = capacity[b][a] += c;//�ݴ�� ���°� 

	}
	//from 'A' to 'Z'


	int subTotal = 0;

	while (1)
	{
		int mPrev[ASC];
		fill(mPrev, mPrev + ASC, -1);

		queue<int> Q;
		Q.push('A');

		while (!Q.empty())
		{
			int node = Q.front();
			Q.pop();
			for (int next : adj[node])
			{

				//capacity[node][next] - flow[node][next] 0�̶�� ������ ������������.
				if (capacity[node][next] - flow[node][next] > 0 && mPrev[next] == -1)
				{
					Q.push(next);
					mPrev[next] = node;
					if (next == 'Z') break;
				}
			}
		}

		if (mPrev['Z'] == -1) break; //���̻� Ž���Ұ� X

		int mMin = 1987654321;
		

		//���⼭ ���� �ؾ��ϴ°� k!='A' �̴� prev[k]!='A'�� �ϸ� ������ A�� �귯 ���°� �������� ����.
		for (int k = 'Z'; k != 'A'; k = mPrev[k])
			mMin = min(mMin, capacity[mPrev[k]][k] - flow[mPrev[k]][k]);

		for (int k = 'Z'; k != 'A'; k = mPrev[k])
		{			//flow�� �帣�� ������ �����ȴ�.
			flow[mPrev[k]][k] += mMin;
			flow[k][mPrev[k]] -= mMin;
			//��� �������̰� ��� �ݴ� �������� �˱��� ����. 
			//�� ������ ���� �Ѵ��ʿ�
		}
		subTotal += mMin;
	}


	cout << subTotal << endl;


	return 0;
}

