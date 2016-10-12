/*
���� : LCA
���� ��ȣ: 11437
Ǯ�̹� : LCA - Lowest Common Ancestor
��¥ : 161008
��Ÿ : 
dp [������] = { ù���� �θ�, �ι�° �θ�, ������ �θ� ,,,,,}
�̷������� ������ 2^k ������ �ϳ����� ���� �� ������ �ô�.

����Ʈ�� �ʹݿ� ������ ���������ν� �׳�尡 ��������� ��ġ�� �ִ��� �˰� �����ν�
Ʈ���� �����ߴٰ� �������ִ�.

depth[k] = depth[x] + 1;//�� ������...��¥��

dp�� �ʱ�ȭ�ϴ� �κ���


k = dp[k][0];
�Ѹ���� dp[dp[dp[k]]]] �̷� �������� �θ� ����Ѵٴ� �� �˼��ִ�.
�װ� �������� dp ���� ������ �� �� �ִ�.
*/


#include <iostream>
#include <vector>
#define N 50000
using namespace std;
typedef pair<int, int> P;

int depth[N+2]; //������ 50000����
vector<int> dp[N+2];//����忡���� �θ�....
vector<int> input[N+2];


void recur(int x)//init �ϴ� �κ���
{
	for (int k : input[x])
	{
		if (depth[k]==0)
		{
			depth[k] = depth[x] + 1;//�� ������...��¥��
			dp[k].push_back(x);//�̰� ù���� �θ𰡵ɰž�.
			recur(k);
		}
	}
}

int main(void)
{
	int n;
	cin >> n;
	int a, b;


	for(int i = 0 ; i < n-1;i++)
	{
		scanf("%d %d", &a, &b);
		input[a].push_back(b);//�����غ��� 
		input[b].push_back(a);//�����غ��� 
	}

	//1�� ��Ʈ�̰�Ʒ��� �������±����̴�.
	depth[1] = 1;
	recur(1);

	//�׳� ������ ������� ���� �ǾƷ������� ä������.
	
	//������ �˾ƾ� ������ �����ϴ�.
	//dp �ʱ�ȭ
	for (int i = 1; i <= n; i++)
	{
		int k = i;
		while(depth[k] != 1)//1�̵Ǹ� ������.
		{
			k = dp[k][0];//�ڱ� ù����..
			dp[i].push_back(k);
		}
	}

	int q,temp,diff,c;
	cin >> q;

	while (q--)
	{
		scanf("%d %d", &a, &b);
		
		if (a == b)
		{
			printf("%d\n",a);
			continue;
		}

		if (depth[a] < depth[b])
		{
			temp = a;
			a = b;
			b = temp;
		}
		
		diff = depth[a] - depth[b];

		c = 1;
		
		if (dp[a][diff] == b)
		{
			cout << b << endl;
		}
		else
		{
			while (dp[a][c + diff] != dp[b][c]) c++;
			cout << dp[b][c] << endl;
		}
	}

	return 0;
}