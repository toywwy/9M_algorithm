/*
���� : ��������Ʈ
���� ��ȣ: 9466
Ǯ�̹� : DP
��¥ : 161001
��Ÿ : ������ DFS, ����Ŭ ã�� ��������...�̰� DP�� Ǯ������ ������ �� ���� �ɷ���..
���� �� Ž���ؾ� �߰� �׷��� �޸𸮸� ���� �ʿ�� �ߴ�.
������ ��������� DP�� ������ �ذ��ߴٴ°� ....�ٵ� ��¥ ������..
�ڲ� ��� ������ DP�� Ǯ�����ϴ°� ���� �����ֵ��°� ��ݵ� ������.

*/

#include<iostream>

using namespace std;

int n; //n (2 �� n �� 100,000)

int arr[100002];
bool flag[100002];
bool flagTeam[100002];
int dp[100002];

int res = 0;

//k�� �����°��� ����
inline void dfs(int k,int before)
{
	if (!flag[k])
	{
		flag[k] = 1;

		dp[k] += dp[before] +1;//������ ���� �ϳ��� ������.
		//������ üũ�ϴ� �ñ��� ������� �����Ѵ�.
	
		if (k == arr[k])//�̰ſ� ���ؼ� �����غ���.
		{
			flag[k] = 1;
			res += 1;
			return;
		}

		if (flag[arr[k]])//������ �κ����ִ�.
			if (flagTeam[arr[k]])//������ ������ �̹��� ���� ���̾�
			{
				res += (dp[k] - dp[arr[k]] + 1);
				return;
			}

		flagTeam[arr[k]] = 1; //���⼭ �� �κ��� üũ���ǰ� �Ʒ��� �ٽ� ���ƿԵ��� ����.
		dfs(arr[k], k);
		flagTeam[arr[k]] = 0;
	}else if (flagTeam[arr[k]] && arr[k]!=k)//������ ������ �̹��� ���� ���̾�
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
		//������ n�����ΰŴ�.

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
				dfs(arr[i],i);//�ϴ� �ڱ� �ڽ� �ϳ���
				flagTeam[i] = 0;
			}
		}

		cout << n - res<< endl;
	}
	return 0;
}