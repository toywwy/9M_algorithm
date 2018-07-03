/*
문제 : 최대유량
문제 번호: 6086
풀이법 : 최대유량
날짜 : 18.07.02
기타 : 어려웠다.
어려운 포인트
1) 역으로 거슬러 가는 부분에 대한 이해.
2) 중복 입력이 허용되는 부분
3) (값이 들어왔기 때문에 이미 들어왔던 부분을 밀어내고 기존값 유지가능)
역으로 지나간다 B - C - D 라는게있다.
C <- D는 이미 3 이었다. 그런데 C -> D로 값이 지나가면 C에 값은 보존될까?
보존된다 B에서 얼마가 들어왔든 나가는게 같기 때문이다. (값이 들어왔기 때문에 이미 들어왔던 부분을 밀어내고 기존값 유지가능)

양방향이라는 점에서 flow 는 + - mMin을 해주어야한다.
---------

+=을...
=+로 실수를 해버리는 문제로 엄청나게 고생..

총체적 난국으로 고생했다.

그냥 양방향이라고 생각하고 작성을 했었어야했다.

에초에 양방향을 고려했다면 이렇게 되지 않았을것.

capacity[a][b] = capacity[b][a] += c;//반대로 가는건

flow[mPrev[k]][k] += mMin;
flow[k][mPrev[k]] -= mMin;

양방향으로 흐르기 때문에 음수로 해주어야 한다.


flow 가 음수라는 말은? 항상 if문 통과 가능하다.
if(capacity[node][next] - flow[node][next] > 0 && mPrev[next] == -1)


그렇다면 못들어가는 경우는?? 일단 flow는 절대 capacity보다 클수없다. 에초에 그런 값이 들어갈수없기때문에
즉 ==0이 되는경우만 못들어간다.

if(capacity[node][next] - flow[node][next] != 0 && mPrev[next] == -1)
이게 논리에 맞다.

if( mPrev[next] == -1) 만하게 되면 시간초과.

내말은 거슬러 올라갈땐 왜 항상갈수있냐는건데..? flow가 0이면 못지나 가게하는게맞다.

그리고 flow가 0인데 역으로 갈수가없는데 가게된다. 저 if문의 문제점..

즉 양방향으로 가는거 맞는데 flow가 음수가 되는건 의미가 없다.
capacity가 있는한 역으로 진행이가능하고 또 

-------------------------------
A와 B 사이에 파이프를 추가하는 것과 B와 A 사이에 파이프를 추가하는 건 같은 걸로 봐야할 거 같습니다.
만약 아니라면, 문제에 파이프는 첫째 꼭짓점에서 둘째 꼭짓점까지 단방향으로만 흐를 수 있다는 조건을 추가해주세요.
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
int capacity[ASC][ASC];//용량에 적용 받는다.

int N;

int main(void) {

	cin >> N;

	char a, b;
	int c;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b >> c;
		//양방향으로 다이동되게된다.
		adj[a].push_back(b);
		adj[b].push_back(a);

		//주의 중복입력 += 여러 통로가 존재한다.
		capacity[a][b] = capacity[b][a] += c;//반대로 가는건 

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

				//capacity[node][next] - flow[node][next] 0이라면 꽉차서 지나갈수없다.
				if (capacity[node][next] - flow[node][next] > 0 && mPrev[next] == -1)
				{
					Q.push(next);
					mPrev[next] = node;
					if (next == 'Z') break;
				}
			}
		}

		if (mPrev['Z'] == -1) break; //더이상 탐색할것 X

		int mMin = 1987654321;
		

		//여기서 주의 해야하는게 k!='A' 이다 prev[k]!='A'로 하면 마지막 A로 흘러 들어가는걸 막을수가 없다.
		for (int k = 'Z'; k != 'A'; k = mPrev[k])
			mMin = min(mMin, capacity[mPrev[k]][k] - flow[mPrev[k]][k]);

		for (int k = 'Z'; k != 'A'; k = mPrev[k])
		{			//flow에 흐르는 유량이 축적된다.
			flow[mPrev[k]][k] += mMin;
			flow[k][mPrev[k]] -= mMin;
			//어떤게 정방향이고 어떤게 반대 방향인지 알길이 없다. 
			//값 유지를 위해 둘다필요
		}
		subTotal += mMin;
	}


	cout << subTotal << endl;


	return 0;
}

