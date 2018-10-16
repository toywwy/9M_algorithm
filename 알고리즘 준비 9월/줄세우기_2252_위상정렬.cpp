/*
문제 : 2252
문제 번호: 줄 세우기
풀이법 : 위상정렬
날짜 : 18.10.11
기타 : 위상정렬 개념을 잊어버렸었다...
처음에만 들어오는 얘가 없는걸로 진행하는게 아니라
그래프를 그려놓고 계속 그렇게 queue를 이용해서 진행하면된다.


% 방향이 있는 루프 없는 그래프이여야한다.

진작에 그래프를 그려봤으면 쉽게 풀었을지도

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
		front[a].push_back(b);//a가 b보다 앞이다.
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
