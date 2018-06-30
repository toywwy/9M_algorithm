/*
문제 : 축사배정
문제 번호: 2188
풀이법 : 이분 매칭(Bipartite Matching)
날짜 : 18.06.30
기타 :

스스로 풀어보기
Vector사용안하고 2차원 배열 이용해서 푼다.

*/


#include<iostream>
using namespace std;

int N, M;
int adj[202][202];//배열을 쓰게되면 메모리를 감당하긴 어렵다....아무래도 vector를 안쓴 한계
int len[202];//각각의 length를 따로 저장하면된다.

int Cow[202];
int Room[202];

bool visit[202];

int recur(int cow)
{
	//여기서 굳이 visit를 체크안해도되는이유는 가게 될일이없다.
	visit[cow] = true;

	for (int i = 0; i < len[cow]; i++)
	{
		int room = adj[cow][i];

		if (Room[room] == -1 || (visit[Room[room]] == false && recur(Room[room])))
		{
			Room[room] = cow;
			Cow[cow] = room;
			return true;
		}
		
	}
	return false;
}


int main(void)
{
	int input,b,ans=0;
	cin >> N >> M;

	for (int i = 0; i < N + 1; i++) Cow[i] = Room[i] = -1;

	for (int i = 0; i < N; i++)
	{
		cin >> input;
		for (int j = 0; j < input; j++)
		{
			cin >> b;
			len[i] = input;//길이
			adj[i][j] = b - 1;// index 0부터 시작 할거다.
		}
	}

	
	for (int i = 0; i < N; i++)
	{
		if (Cow[i] == -1)
		{
			for (int i = 0; i < N + 1; i++) visit[i] = false;
			if (recur(i)) ans++;
		}
	}

	cout << ans << endl;

	return 0;
}