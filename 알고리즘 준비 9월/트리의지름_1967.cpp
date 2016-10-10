/*
문제 : 트리의지름
문제 번호: 1967
풀이법 : BFS
날짜 : 161010
기타 : 무조건 루트 노트로 올라가는 것만 BFS를 통해서 구현을했다.
그리고 각각의 노드에서는 값들을 모두 저장하게 되는데 이때 자식노드가 어떤 노드인지를 알아야한다.

그래서 나중에 모든 노드를 탐색하면서 답을 구할때 서로다른 자식노드중 가장 큰값이 그 노드를 중심으로한 지름값이다.

*/


#include<iostream>
#include<vector>
#include<queue>

using namespace std;
#define N 10000


typedef pair<int, int> P;

bool flag[N + 2];
vector<P> v[N + 2];
vector<P> res[N + 2];//그곳의 좌표 <값, 어디서 왔는지> 를 넣도록하자.

int main(void)
{
	int n;
	cin >> n;

	int a, b, c;
	for (int i = 0; i < n - 1; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		v[b].push_back(P(a, c));

		flag[a] = 1;
	}

	queue<P> q;

	for (int i = 1; i <= n; i++)
		if (!flag[i])//리프노드이다. 리프노드에서 부터 가장 긴걸 구하면된다.
			q.push(P(i, 0));


	while (!q.empty())
	{
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			P p = q.front(); q.pop();

			for (P next : v[p.first]) {
				res[next.first].push_back(P((p.second + next.second), p.first));

				q.push(P(next.first, (p.second + next.second)));
			}

		}
	}

	int mMax = 0, m1, m2, mP;
	for (int i = 1; i <= n; i++)
	{
		if (flag[i])
		{
			m1 = m2 = mP = 0;
			for (P r : res[i])
				if (m1 < r.first)
				{
					m1 = r.first;
					mP = r.second;
				}

			for (P r : res[i])
				if (r.second != mP)
					m2 = max(m2, r.first);

			mMax = max(mMax, (m1 + m2));
		}
	}

	cout << mMax << endl;

	return 0;
}