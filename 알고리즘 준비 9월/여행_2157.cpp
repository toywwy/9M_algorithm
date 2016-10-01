/*
���� : ����
���� ��ȣ: 2157
Ǯ�̹� : DP
��¥ : 161002
��Ÿ : DP�߿� �� ����� ��������.?? ���� ��ƴٱ� ���� �ٸ� ����
������ �����ϴ� ���� �ϳ����� ������ ���⿡�� Ƚ���� ���ѵױ⶧���� dp�� ���������� �����߾�
�ٵ� �̰� �� ���ٸ��� �� �����ؼ� ������� 
ī��Ʈ��� ������ �������
dp[302][302];
   position, ī��Ʈ ,�� ������ ���� �����ؼ� �̿��ߴ�.

�������� ���� ������ �迭�� ��������� for(int j = 1 ; j<=i;j++)
n���� Ž�����Ѵ� . ������ i�����̸� ������ i�� ���� ���� ���� �����̴�.
i�� ���µ� i���� ���� �ҿ��Ҽ����� ���� �����ϴ�
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<int, int> P;

int dp[302][302];
vector<P> eg[302];

//M(2��M��N), K(1��K��100,000)
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

	dp[1][1]=0;//v first == ī��Ʈ ,second ��
	for (int i = 1; i <= n; i++)
	{
		for(int j = 1 ; j<=i;j++)//j��ī��Ʈ��.
		{
			int value = dp[i][j], countV = j;
			if (i!= 1 && value == 0)
				continue;

			//p.first ī��� second�� value�̴�.
			for (P e : eg[i])
			{//e�� first��ŭ ���� second��ŭ�� ����ġ�� ������ �ִ�.
				if (countV + 1 != m)
				{	
					if (dp[e.first][countV + 1] < value + e.second)
						dp[e.first][countV + 1] = value + e.second;
				}
				else
				{
					if (n == e.first)//������ �ƴѵ� �̷��� ��ġ�� ���°Ŵ�.
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