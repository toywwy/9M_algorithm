/*
문제 : 음악프로그램
문제 번호: 2623
풀이법 : 위상정렬, 사이클 판단
날짜 : 161002
기타 : 사이클을 판단할수가 있다. 판단하는 방법은 노드를 하나하나씩 빼는거다.
어떤 노드를 빼나 자기 자신으로 들어오는 값이 없는 노드를 빼면된다.
visit 체크하고 모든 노드가 빠지면 빠지는 순서로 위상정렬이 되는것이다.

위상정렬은 
위상 정렬이 필요한 경우는 그래프에서 반드시 자신보다 선행되어야 할 일을 다 끝내야만 작업에 들어갈 수 있는(방문할 수 있는) 조건이 주어질 때입니다.

*/


#include<iostream>
#include<vector>

using namespace std;

int arr[1002];
bool visit[1002];
vector<int> v[1002];
vector<int> res;

int main(void)
{
	int n, m;

	cin >> n >> m;

	int in, c, be;
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &c);
		for (int j = 0; j < c; j++)
		{
			scanf("%d", &in);

			if (j == 0)
			{
				be = in;
				continue;
			}
			arr[in] += 1;
			v[be].push_back(in);
			be = in;
		}
	}
	
	int cnt = n;
	while (cnt--)
	{
		bool c = false;
		for (int i = 1; i <= n; i++)
		{
			if (!arr[i]&& !visit[i])
			{
				visit[i] = 1;
				res.push_back(i);
				for (int k : v[i])
					arr[k] -= 1;
				break;
			}
		
			if (i == n)
				c = true;
		}

		if (c)
			break;
	}


	if (cnt != -1)
		cout << 0;
	else
		for (int r : res)
			printf("%d ", r);

	cout << endl;

	

	return 0;
}