/*
문제 : 소트게임
문제 번호:1327
풀이법 : BFS
날짜 : 16
기타 : 라이브러리에 의존해서 풀었다.


어떤식으로 visit, flag 체크를 할까?

완전 탐색이냐? 둘다되지만.
최단경로냐? BFS 해야한다.
최단경로를 DFS하게 되면 완전탐색하게된다.

BFS로 다시 해야한다.

왜 대체 이런 실수를 한거지..
문제가생겼다 visit를 체크하지 못한다 
8 자리 ..비트로표현못해
set말고도 비트로 표현할수 있는 방법이 있을까?? 도저히 생각 X

그래서일단 string 을 SET으로 저장해서 사용을 했다.
실제로 set을 구현하기 위해서는 hash 사용해야 한다. 한번에 찾을수있는..

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<queue>


using namespace std;

typedef pair<string, int> P;

int input[10];//N은 2보다 크거나 같고, 8보다 작거나 같다.
int mQueue[200000];
int front;
int rear;


int N, K, C;


bool resCheck;
//오름차순 체크
inline bool checkASC(int arr[])
{
	int k = arr[0];
	for (int i = 1; i < N; i++)
	{
		if (arr[i - 1] > arr[i]) return false;
	}
	return true;
}


set<string> visit;
queue<P> q;


int main(void)
{
	cin >> N >> K;
	string input;
	input.resize(10);
	for (int i = 0; i < N; i++)
	{
		char c;
		cin >> c;
		input[i] = c;
	}
	int resCnt=0;
	bool resChk = false;
	string res = input;//정렬하여 미리 정답을 안다.
	
	sort(res.begin(), res.begin() + N);

	if (input == res)
	{
		cout << resCnt << endl;
		return 0;
	}

	visit.insert(input);
	q.push(P(input,1));

	C = N - K;
	while (q.size() > 0)
	{
		P top = q.front(); q.pop();
		for (int i = 0; i <= C; i++)
		{
			string str = top.first; //매번 새로운거 해야한다.

			int R = i + K- 1;

			for (int j = 0; j < K/2 ; j++)
			{
				//줄어드는 애랑 증가하는애까잇을거여
				char temp = str[j+i];//증가하는얘
				str[i + j] = str[R-j];
				str[R-j] = temp;
			}


			if (str == res)
			{
				while (!q.empty()) q.pop();
				resCnt = top.second;
				resChk = true;
				break;
			}
				
			if (visit.find(str) == visit.end()) {
				visit.insert(str);
				q.push(P(str,top.second+1));
			}

		}
	}
	if (resChk)
		cout << resCnt << endl;
	else
		cout << -1 << endl;


	return 0;
}
