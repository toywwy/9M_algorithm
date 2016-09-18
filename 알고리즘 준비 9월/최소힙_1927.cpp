
/*

문제 : 최소힙
문제 번호: 1927
풀이법 : 힙
날짜 : 160919
기타 : priority를 구현하기 위한 힙 구조 연습하기.

*/

#include<iostream>
#include<queue>
#include<functional>

typedef unsigned int uint;

using namespace std;

int main(void)
{
	priority_queue<uint, vector<uint>, greater<uint>> PQ;

	uint n;
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