/*
���� : �������α׷�
���� ��ȣ: 2623
Ǯ�̹� : ��������, ����Ŭ �Ǵ�
��¥ : 161002
��Ÿ : ����Ŭ�� �Ǵ��Ҽ��� �ִ�. �Ǵ��ϴ� ����� ��带 �ϳ��ϳ��� ���°Ŵ�.
� ��带 ���� �ڱ� �ڽ����� ������ ���� ���� ��带 ����ȴ�.
visit üũ�ϰ� ��� ��尡 ������ ������ ������ ���������� �Ǵ°��̴�.

���������� 
���� ������ �ʿ��� ���� �׷������� �ݵ�� �ڽź��� ����Ǿ�� �� ���� �� �����߸� �۾��� �� �� �ִ�(�湮�� �� �ִ�) ������ �־��� ���Դϴ�.

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