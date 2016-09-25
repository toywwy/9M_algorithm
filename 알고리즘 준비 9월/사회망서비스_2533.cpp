#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int dpIdx = 1;

int arr[1000002];
int dp[1000002];
int res[2][1000002];

int main(void)
{
	int n;
	cin >> n;


	int a, b;

	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &a, &b);
		arr[b] = a;
	}
	//이렇게 되면 각자의 부모를 알수있게된다.
	arr[0] = arr[1] = -1;
	queue<int> q;
	int idx = 0;
	dpIdx = 1;
	dp[0] = 1;
	for (idx = 2; idx < n; idx++)
	{
		if (arr[idx] == 1)
		{
			dp[dpIdx] += 1;
			q.push(idx);
		}
		else
		{
			dpIdx++;
			break;
		}
	}

	while (!q.empty())
	{
		int s = q.size();
		for (int i = 0; i < s; i++)			
		{
			int v = q.front();
			for (;; idx++)
			{
				if (arr[idx] == v)
				{
					dp[dpIdx] += 1;
					q.push(idx);
				}
				else {
					break;
				}
			}
			q.pop();
		}
		dpIdx++;
	}
	

	int k = 0;

	//여기서 부터 dp로 문제를 풀어나가보자...
	
	res[0][0] = 0;
	res[1][0] = dp[0];
	for (int i = 1; i < dpIdx-1; i++)
	{//0 번지 선택안함
	//1번지 선택
		res[0][i] += res[1][i - 1];//선택안함 //이전 선택한거에서 가져온다.
		res[1][i] += res[0][i-1] + dp[i];//선택
	}

	dpIdx -= 2; //for문 증가 인덱스로 사용 -2
	
	if (res[0][dpIdx] < res[1][dpIdx])
	{
		cout << res[0][dpIdx] << endl;
	}
	else
	{
		cout << res[1][dpIdx] << endl;
	}




	return 0;
}