
/*

문제 : 최대힙
문제 번호: 11279
풀이법 : 힙
날짜 : 160919
기타 : priority를 구현하기 위한 힙 구조 연습하기.

*/

#include<iostream>
#include<queue>
#include<functional>

typedef unsigned int long;

using namespace std;

int main(void)
{
	priority_queue<long, vector<long>, less<long>> PQ;

	long n;
	cin >> n;

	int m=0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d",&m);
		if (m == 0)
		{
			if (PQ.empty())
				printf("0\n");
			else
			{
				printf("%d\n", PQ.top());
				PQ.pop();
			}
		}
		else
		{
			PQ.push(m);
		}
	}

	return 0;
}