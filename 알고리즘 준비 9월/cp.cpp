#include<iostream>
#include<algorithm>

using namespace std;




int arr[2002];
bool dp[2002][2002];//이게좀 크네.

int depth[2002];
int n;

int recur(int a, int b,int level)
{
	if (level < n)
	{
		if (dp[a][b])
		{
			depth[level] = 1;
			return 1;
		}
		else
		{
			int x=0, y=0,x2=0,y2=0;
			x = recur(a + 1, b, level + 1);
			y = recur(0, a, level + 1);
			int c = x + y;
			x2 = recur(a , b-1, level + 1);
			y2 = recur(b,n, level + 1);
			int d = x2 + y2;
			depth[level] = min(c,d);
			return depth[level];
		}
	}
}


int main(void)
{
	cin >> n;

	for (int i = 0; i < 2001; i++)
	{
		depth[i] = 2001;
	}

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	for (int i = 1; i <= n; i++)
	{
		dp[i][i] = 1;//자기자신이건 되는거지
		if (arr[i] == arr[i + 1])
			dp[i][i + 1] = 1; // 예외처리 해줘야한다. j가 1이였을떄  dp[j+1][j+i-1]이 조건을 패스 못하기 때문
	}

	for (int i = 2; i <= n; i++)//간격 i의 간격으로 진행
	{
		for (int j = 1; j <= n; j++)//횟수
		{
			if (j + i > n)
				break;

			if (arr[j] == arr[j + i] && dp[j + 1][j + i - 1])
			{
				dp[j][j + i] = 1;
			}
		}
	}


	cout << recur(1, n,1) << endl;
	//이미 그건 구해진 상태이고

	int k = 0;
	return 0;
}