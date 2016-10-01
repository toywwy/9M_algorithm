/*
문제 : 텀프로젝트
문제 번호: 9466
풀이법 : DP
날짜 : 161001
기타 : 문제는 DFS, 사이클 찾기 문제였다...이걸 DP로 풀었더니 오히려 더 오래 걸렸음..
모든걸 다 탐색해야 했고 그래서 메모리를 많이 필요로 했다.
하지만 뜻깊은점은 DP로 문제를 해결했다는거 ....근데 진짜 안좋다..
자꾸 모든 문제를 DP로 풀려고하는게 나쁠 수도있따는걸 방금도 느꼈다.

*/

#include<iostream>

using namespace std;

int n; //n (2 ≤ n ≤ 100,000)

int arr[100002];
bool flag[100002];
bool flagTeam[100002];
int dp[100002];

int res = 0;

//k는 가려는곳의 값임
inline void dfs(int k,int before)
{
	if (!flag[k])
	{
		flag[k] = 1;

		dp[k] += dp[before] +1;//이전의 값에 하나를 더해줌.
		//정답을 체크하는 시기의 문제라고 생각한다.
	
		if (k == arr[k])//이거에 대해서 생각해보자.
		{
			flag[k] = 1;
			res += 1;
			return;
		}

		if (flag[arr[k]])//가려는 부분이있다.
			if (flagTeam[arr[k]])//갈수가 없지만 이번에 갔던 곳이야
			{
				res += (dp[k] - dp[arr[k]] + 1);
				return;
			}

		flagTeam[arr[k]] = 1; //여기서 그 부분이 체크가되고 아래서 다시 돌아왔따고 생각.
		dfs(arr[k], k);
		flagTeam[arr[k]] = 0;
	}else if (flagTeam[arr[k]] && arr[k]!=k)//갈수가 없지만 이번에 갔던 곳이야
	{
		res += (dp[before] - dp[k] + 1);
		return;
	}
	
}

int main(void)
{

	int itr = 0;
	cin >> itr;
	int b = 0;
	for (int i = 0; i < itr; i++)
	{
		res = 0;
		cin >> n;
		b = n;
		for (int i = 1; i <= n; i++)
			cin >> arr[i];
		//범위는 n까지인거다.

		for (int i = 1; i <= b; i++)
		{
			flag[i] = 0;
			dp[i] = 0;
		}

		for (int i = 1; i <= n; i++)
		{
			
			if (!flag[i])
			{
				if (arr[i] == i)
				{
					flag[i] = 1;
					res += 1;
					continue;
				}

				flag[i] = 1;
				dp[i] = 1;
				flagTeam[i] = 1;
				dfs(arr[i],i);//일단 자기 자신 하나임
				flagTeam[i] = 0;
			}
		}

		cout << n - res<< endl;
	}
	return 0;
}