/*
���� : �߷�����
���� ��ȣ: 1939
Ǯ�̹� : ���̳ʸ���ġ, binary search, binary_search
��¥ : 160926
��Ÿ : ������ 10000000�߿� �ϳ�����. ������ �̰� ������ ���� ������ ���Ҿ� �׷��� ���߻�����
���̳ʸ� ��ġ�� ����Ѵ�. �� ������ �����Ѱ�???�� Ȯ���ϸ鼭 ���信 ���缭����.

�׸��� �������� �κ��� flag�� ����ϴ� �κ��̴�. �ٷ� ���� ã�⸦ �ϱ� ���ؼ��� flag ���� �ʱ�ȭ�� �Ǹ������� ���ִ°� ������ ���� ���� �ʿ����.
�����ϴ��� ���ϴ����� �߿��� ��!

*/


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define N 10000
#define INF 10000002
typedef pair<int, int> P;

bool flag[N + 2];
vector<P> vec[N + 2];

int mStart, mEnd, mMax = 0;

inline bool check(int start, int target) //target�� ���� ã���� �ֳ� ����
{// target�� ã�� �� �ֳ� ����!
	bool res = false;

	for (P p : vec[start])
	{
		if (!flag[p.first])
		{
			if (target <= p.second)//�׷��� ��ġ����
			{

				if (p.first == mEnd)
					return true;

				flag[p.first] = 1;
				res = check(p.first, target);
				//flag[p.first] = 0;
				//������ 1���� 7�� ���� 2���� 7�� ���� 7�� ���� ��ǥ�� ���� ���� ���̴�. �׷��� �ι� �� �ʿ䰡 ���� �� �̴�.

				if (res)
					return true;
			}
		}
	}
	return res;

}

int main(void)
{

	int n, m;
	cin >> n >> m;

	int a, b, c;

	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		vec[a].push_back(P(b, c));//c�� ����ġ�̴�.
		vec[b].push_back(P(a, c));
		mMax = max(c, mMax);
	}
	cin >> mStart >> mEnd;

	int s = 1;
	int e = mMax; //�ִ� ��� max ���޾Ƽ� �װɷ��ص���

	//�̷� ���߻��� ��� �����ϴܸ��ΰ�....
	//��� BFS�� Ǯ�����°� �� DFS dp���� ����Ѱɷ� ��Ǯ�� ������??? �ð������̴��� ����ġ��...

	flag[mStart] = 1;
	int mid;
	int result = 0;
	while (s <= e)
	{
		mid = (s + e) / 2;

		if (check(mStart, mid))//ã�� �� �ִ�. ��ū �� ã���� 
		{
			result = mid;//������ �ݵ�� �̷��� �ؾ���
			s = mid + 1;
		}
		else
			e = mid - 1;

		for (int i = 1; i <= n; i++)
			flag[i] = 0;
	}
	cout << result << endl;;

	return 0;
}