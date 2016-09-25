#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int dpIdx = 1;

vector<int> arr[1000002];//�̺κ��� ������� �Ǿ���ϴ°ǵ� .....
int dp[1000002];
int res[2][1000002];
bool flag[1000002];

int main(void)
{
	int n;
	cin >> n;


	int a, b;

	for (int i = 0; i < n-1; i++)
	{
		scanf("%d %d", &a, &b);
		arr[b].push_back(a);
		arr[a].push_back(b);
	}
	//�̷��� �Ǹ� ������ �θ� �˼��ְԵȴ�.
	//dp�� ������ ä��� �Ǵ°Ŵ�...

	dp[0] = 1;
	queue<int> q;
	flag[1] = 1;
	for (int a : arr[1])//1�׻� ����
	{
		if (!flag[a])
		{
			flag[a] = 1;
			q.push(a);
			dp[dpIdx] += 1;
		}
	}
	dpIdx++;

	while (!q.empty())
	{
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			for (int k : arr[q.front()])
			{
				if (!flag[k])
				{
					flag[k] = 1;
					q.push(k);
					dp[dpIdx] += 1;
				}
			}
				
			q.pop();
		}
		dpIdx++;
	}

	res[0][0] = 0;
	res[1][0] = dp[0];
	for (int i = 1; i < dpIdx - 1; i++)
	{//0 ���� ���þ���
	 //1���� ����
		res[0][i] += res[1][i - 1];//���þ��� //���� �����Ѱſ��� �����´�.
		res[1][i] += res[0][i - 1] + dp[i];//����
	}

	dpIdx -= 2; //for�� ���� �ε����� ��� -2

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


/*


9
1 2
1 3
2 4
3 5
3 6
4 7
4 8
4 9

������ �߸������ߴ� ...

�̿����� �������� 

�̰� �󸮾�ž�ʹ� �ߺ��� �ǰ� ��Ÿ���� �ֱ⶧���� ��͸� Ÿ�鼭 dp�� �ϸ� ������ �ذ� �� �� ���� ���̴�.
�ð� ������ ��� ��¥ �Ʊ��...


*/