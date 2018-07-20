/*
문제 : 최소 스패닝 트리
문제 번호: 1197
풀이법 : 스패닝트리
날짜 : 18.07.20
기타 : 입력 받는거 실패

*/

#include<iostream>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;

class P {
public:
	int t, v;
	P(int _a, int _b) : t(_a), v(_b) {}
};


class compare
{
public:
	bool operator()(const P& l, const P& r)
	{
		return l.v > r.v;
	}
};

bool visit[10001];
vector<P> adj[10001];

int N, M;

void prim()
{
	visit[1] = true;
	priority_queue<P, vector<P>, compare> q;

	int res = 0;

	for (P p : adj[1]) q.push(p);

	while (!q.empty())
	{
		P top = q.top();
		q.pop();

		if (visit[top.t] == false)
		{
			visit[top.t] = true;
			res += top.v;
			for (P p : adj[top.t]) q.push(p);
		}
	}
	cout << res << endl;

}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> N >> M;

	for (int j = 0; j < M; j++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		adj[a].push_back(P(b, c));
		adj[b].push_back(P(a, c));
	}

	//최소 가중치로 N을 연결하면된다. 풀이 방식 두가지가 있다. 

	prim();

	return 0;
}
