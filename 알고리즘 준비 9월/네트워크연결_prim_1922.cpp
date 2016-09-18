
/*
문제 : 네트워크연결
문제 번호: 1922
풀이법 : 다익스트라
날짜 : 160916
기타 : prim알고리즘방식으로 문제 해결
정점을 모두 찾아가는 방식으로 
크루스칼로 접근하는법이 더 빠르다고한다.
*/


#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>

#define N 1000


using namespace std;

class Con {
public:
	int s;
	int e;
	int w;

	Con(int s, int e, int w)
	{
		this->s = s;
		this->e = e;
		this->w = w;
	}
};

struct priority {
	bool operator()(Con a, Con b)
	{
		return a.w > b.w;//얘가 크면 스위칭을하겠다.
	}
};


int arr[N + 2][N + 2];
bool flag[N + 2];

//vector<int> v[N + 2];

int main(void)
{
	int n, line;//컴퓨터수 1000, 연결할 선의수 100000
	cin >> n >> line;

	//모든 컴퓨터를 연결하면된다. 양방향이다.
	int a, b, w;

	//사용자 정의 구조체로
	priority_queue<Con, vector<Con>, priority> PQ;

	for (int i = 0; i < line; i++)
	{
		scanf("%d %d %d", &a, &b, &w);
		arr[a][b] = arr[b][a] = w;
		//얘낸 방향이없다.
	}

	for (int i = 2; i <= n; i++)
	{
		if (arr[1][i] != 0)
			PQ.push(Con(1, i, arr[1][i]));
		else if(arr[i][1] != 0)
			PQ.push(Con(1, i, arr[1][i]));
	}
	flag[1] = 1;
	int cnt = 1;
	int value = 0;

	while (!PQ.empty())
	{
		Con s = PQ.top(); 
		PQ.pop();

		//둘중에 하나만 0일거야 
		if (flag[s.s] == 0)
		{
			for (int i = 1; i <= n; i++)
			{
				if (arr[s.s][i] != 0)
					PQ.push(Con(s.s, i, arr[s.s][i]));
				else if (arr[i][s.s] != 0)//이렇게하면 굳이 두개다 저장할필요는 없는듯.. 어차피 두번 확인할거.
					PQ.push(Con(s.s, i, arr[s.s][i]));
			}
			flag[s.s] = 1;
			value += s.w;
			cnt++;
		}
		else if (flag[s.e] == 0)
		{
			for (int i = 1; i <= n; i++)
			{
				if (arr[s.e][i] != 0)
					PQ.push(Con(s.e, i, arr[s.e][i]));
				else if (arr[i][s.e] != 0)
					PQ.push(Con(s.e, i, arr[s.e][i]));
			}
			flag[s.e] = 1;
			value += s.w;
			cnt++;
		}

		if (cnt >= n)
			break;
		                         
	}
	cout << value << endl;

	return 0;
}