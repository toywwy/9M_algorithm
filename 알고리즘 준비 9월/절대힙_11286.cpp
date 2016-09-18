
/*

문제 : 절대힙
문제 번호: 11286
풀이법 : 우선순위 힙
날짜 : 160919
기타 : 절대값에서 중복이 발생했을시에 처리 방법이 추가되면서 문제가 생겼었다.

*/

#include<iostream>
#include<queue>
#include<functional>
#include<cmath>

using namespace std;
typedef pair<long, long> P;

inline long mAbs(long a)
{
	if (a > 0)
		return a;
	else
		return -a;
}

struct priority
{
	bool operator()(P a, P b) {
		if (a.first == b.first)
			return a.second > b.second;
		else
			return a.first > b.first;
	}
};


int main(void)
{
	priority_queue<P, vector<P>, priority> PQ;

	long n;
	cin >> n;

	int m = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &m);
		if (m == 0)
		{
			if (PQ.empty())
				printf("0\n");
			else
			{
				printf("%d\n", PQ.top().second);
				PQ.pop();
			}
		}
		else
		{
			PQ.push(P(mAbs(m), m));
		}
	}

	return 0;
}