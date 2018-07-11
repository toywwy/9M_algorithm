/*
문제 : 최소값
문제 번호: 10868
풀이법 : 세그먼트트리
날짜 : 18.06.11
기타 :

실수 a-1 b-1
0부터 시작하냐 1부터 시작하냐를 잘가려야한다.

*/


#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>

using namespace std;

int N, M;

int arr[100002];
vector<int> tree;
//N(1 ≤ N ≤ 100, 000)개
//M(1 ≤ M ≤ 100, 000)
//1, 000, 000, 000이하의 값을 갖는다.

int recur(int start, int end, int node)
{
	if (start == end)
	{
		return tree[node] = arr[start];//leaf까지 내려온 상태
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

	tree.resize(tree_size); //Full 만큼 쓰게 한다.

	int a, b;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	recur(0, N - 1, 1);


	//init segment tree 구현

	//solve problems.
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &a, &b);

		printf("%d\n", findMin(0, N - 1, 1, a - 1, b - 1));

	}

	return 0;
}