/*
문제 : 여행
문제 번호: 2157
풀이법 : DP
날짜 : 161002
기타 : DP중에 좀 어려운 문제였다.?? 딱히 어렵다기 보다 다른 유형
원래는 선택하는 값이 하나였어 하지만 여기에선 횟수를 제한뒀기때문에 dp를 이차원으로 썼어야했어
근데 이게 좀 색다르게 좀 복잡해서 어려웠음 
카운트라는 개념이 어려웠어
dp[302][302];
   position, 카운트 ,값 순서로 값을 세팅해서 이용했다.

역방향은 없기 떄문에 배열을 사용했지만 for(int j = 1 ; j<=i;j++)
n까지 탐색안한다 . 어차피 i번쨰이면 갯수가 i를 넘을 수가 없기 때문이다.
i에 오는데 i보다 많이 소요할수없음 무슨 짓을하던
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<int, int> P;

int dp[302][302];
vector<P> eg[302];

//M(2≤M≤N), K(1≤K≤100,000)
int main(void)
{
	int n, m, k;
	cin >> n >> m >> k;

	int a, b, c;
	for (int i = 0; i < k; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		if(a<b)
			eg[a].push_back(P(b, c));
	}

	dp[1][1]=0;//v first == 카운트 ,second 값
	for (int i = 1; i <= n; i++)
	{
		for(int j = 1 ; j<=i;j++)//j는카운트다.
		{
			int value = dp[i][j], countV = j;
			if (i!= 1 && value == 0)
				continue;

			//p.first 카운드 second는 value이다.
			for (P e : eg[i])
			{//e는 first만큼 가고 second만큼의 값어치를 가지고 있다.
				if (countV + 1 != m)
				{	
					if (dp[e.first][countV + 1] < value + e.second)
						dp[e.first][countV + 1] = value + e.second;
				}
				else
				{
					if (n == e.first)//정답이 아닌데 이러면 가치가 없는거다.
					{
						if (dp[e.first][countV + 1] < value + e.second)
							dp[e.first][countV + 1] = value + e.second;
					}
				}
				
			}
		}
	}

	int mMax = 0;
	for (int i = 1; i <= n; i++)
		mMax=max(dp[n][i], mMax);

	cout << mMax << endl;

	return 0;
}