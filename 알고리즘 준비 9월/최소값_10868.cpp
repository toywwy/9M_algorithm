/*
���� : �ּҰ�
���� ��ȣ: 10868
Ǯ�̹� : ���׸�ƮƮ��
��¥ : 18.06.11
��Ÿ :

�Ǽ� a-1 b-1
0���� �����ϳ� 1���� �����ϳĸ� �߰������Ѵ�.

*/


#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>

using namespace std;

int N, M;

int arr[100002];
vector<int> tree;
//N(1 �� N �� 100, 000)��
//M(1 �� M �� 100, 000)
//1, 000, 000, 000������ ���� ���´�.

int recur(int start, int end, int node)
{
	if (start == end)
	{
		return tree[node] = arr[start];//leaf���� ������ ����
	}
	else
	{
		int left = recur(start, (start + end) / 2, node * 2);
		int right = recur((start + end) / 2 + 1, end, node * 2 + 1);

		if (left < right)
		{
			return tree[node] = left;
		}
		else
		{
			return tree[node] = right;
		}
	}
}


int findMin(int start, int end, int node, int left, int right)
{
	if (end < left || right<start)
	{
		return 1987654321;
	}
	else if (left <= start && end <= right)
	{
		return tree[node];
	}
	else
	{

		int v1 = findMin(start, (start + end) / 2, node * 2, left, right);
		int v2 = findMin((start + end) / 2 + 1, end, node * 2 + 1, left, right);

		if (v1 < v2) return v1;
		else return v2;

	}

}


int main(void)
{

	scanf("%d %d", &N, &M);

	int h = (int)(ceil(log2(N)) + 1e-9);
	int tree_size = (1 << (h + 1));

	tree.resize(tree_size); //Full ��ŭ ���� �Ѵ�.

	int a, b;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	recur(0, N - 1, 1);


	//init segment tree ����

	//solve problems.
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &a, &b);

		printf("%d\n", findMin(0, N - 1, 1, a - 1, b - 1));

	}

	return 0;
}