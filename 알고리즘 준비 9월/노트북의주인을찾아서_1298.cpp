/*
문제 : 노트북의 주인을 찾아서
문제 번호: 1298
풀이법 : 이분매칭
날짜 : 18.06.30
기타 :


//프로 문제에는 다시는 안나올 어려운문제...

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;


int N, M, a, b,res;//사람수= 노트북수
//N(1 ≤ N ≤ 100)과 노트북 예상의 개수 M(0 ≤ M ≤ 5,000) 주어진다.

vector<int> v[103];


bool visit[103];//이사람은 매칭이끝났다..

int Man[103];//사람이 지닌 피씨와
int PC[103];//피씨의 주인인 사람이 값이다.


bool recur(int man)
{
	visit[man] = true;

	for (int pc : v[man])
	{
		if (PC[pc] == -1|| ( visit[PC[pc]]==false && recur(PC[pc]) ))
		{//PC[pc] == -1 이 PC는 어느 누구에게도 할당되지않았다.
			//visit[PC[pc]]==false 이 PC는 현재 recur에서 방문된적이 없다. 방문할 가치가 있다.
			//recur(PC[pc]) pc에게 할당된 주인으로 recurcive를 하여 그 주인이 다른 PC를 선택할수 있는지 확인해본다.
			Man[man] = pc;
			PC[pc] = man;
			return true;
		}
	}

	return false;
}

int main(void)
{
	cin >> N >> M;
	fill(Man, Man + N+1, -1);
	fill(PC, PC+N+1, -1);

	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		v[a].push_back(b);//a가 b가 자기 노트북이라 생각한다.
	}

	res = 0;

	
	for (int i = 1; i <= N; i++)
	{
		if (Man[i] == -1)//일단 사람을 기준으로 매핑을 시키는 것이다.
		{
			fill(visit, visit + N +1, false);

			if (recur(i) == true)
			{//i가 매칭에 성공했다면, i로인해 연쇄적으로 갔더라도 매핑에 성공했다면.
				res++;
			}
		}
	}

	cout << res << endl;

	return 0;
}
