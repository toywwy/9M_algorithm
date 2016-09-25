/*
문제 : 중량제한
문제 번호: 1939
풀이법 : 바이너리서치, binary search, binary_search
날짜 : 160926
기타 : 정답은 10000000중에 하나였다. 하지만 이걸 가지는 수는 무수히 많았어 그래서 역발상으로
바이너리 서치를 사용한다. 이 정답이 가능한가???를 확인하면서 정답에 맞춰서간다.

그리고 문제였던 부분이 flag를 사용하는 부분이다. 바로 빨리 찾기를 하기 위해서는 flag 조차 초기화를 맨마지막에 해주는것 어차피 정말 값은 필요없다.
도달하는지 안하는지가 중요할 뿐!

*/


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define N 10000
#define INF 10000002
typedef pair<int, int> P;

bool flag[N + 2];
vector<P> vec[N + 2];

int mStart, mEnd, mMax = 0;

inline bool check(int start, int target) //target의 값을 찾을수 있냐 없냐
{// target을 찾을 수 있나 없나!
	bool res = false;

	for (P p : vec[start])
	{
		if (!flag[p.first])
		{
			if (target <= p.second)//그래야 가치있음
			{

				if (p.first == mEnd)
					return true;

				flag[p.first] = 1;
				res = check(p.first, target);
				//flag[p.first] = 0;
				//예를들어서 1에서 7을 가나 2에서 7을 가나 7은 같은 목표에 도달 했을 것이다. 그래서 두번 갈 필요가 없는 것 이다.

				if (res)
					return true;
			}
		}
	}
	return res;

}

int main(void)
{

	int n, m;
	cin >> n >> m;

	int a, b, c;

	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		vec[a].push_back(P(b, c));//c는 가중치이다.
		vec[b].push_back(P(a, c));
		mMax = max(c, mMax);
	}
	cin >> mStart >> mEnd;

	int s = 1;
	int e = mMax; //최대 사실 max 값받아서 그걸로해도됨

	//이런 역발생이 어떻게 가능하단말인가....
	//사실 BFS로 풀어지는게 왜 DFS dp까지 사용한걸로 안풀어 졌을까??? 시간제한이던데 가지치기...

	flag[mStart] = 1;
	int mid;
	int result = 0;
	while (s <= e)
	{
		mid = (s + e) / 2;

		if (check(mStart, mid))//찾을 수 있다. 더큰 값 찾으러 
		{
			result = mid;//정답은 반드시 이렇게 해야함
			s = mid + 1;
		}
		else
			e = mid - 1;

		for (int i = 1; i <= n; i++)
			flag[i] = 0;
	}
	cout << result << endl;;

	return 0;
}