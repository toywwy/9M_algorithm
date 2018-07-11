/*
문제 : 구간 합 구하기
문제 번호: 2042
풀이법 : 세그먼트트리
날짜 : 18.06.10
기타 :
기본적인 세그먼트트리문제

*/

#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<cstdio>

#define S 0
#define E n-1
using namespace std;

//세 개의 정수 a,b,c가 주어지는데, a가 1인 경우 b번째 수를 c로 바꾸고 a가 2인 경우에는 b번째 수부터 c번째 수까지의 합을 구하여 출력하면 된다.

//N(1 <= N <= 1, 000, 000)과 M(1 <= M <= 10, 000), K(1 <= k <= 10, 000)


long long recur(vector<long long> &arr, vector<long long> &tree, int node, int start, int end)
{
	//목적은 tree에 node를 채우는 것이다.
	if (start >= end)
	{
		return tree[node] = arr[start];// 어느 것이 들어가든 무관
	}
	else
	{
		//트리의 리프까지가서 부모노드의 왼쪽자식 (node*2)+오른쪽자식 (node*2+1) 으로 값을 만들어 나가면서 트리는 만들어나간다.
		return tree[node] = recur(arr, tree, node * 2, start, (start + end) / 2) + recur(arr, tree, node * 2 + 1, (start + end) / 2 + 1, end);
	}
}


long long findInterval(vector<long long> &tree, int node, int start, int end, int left, int right)
{
	//해당이 되지 않으면 0을 리턴하게되고, 해당되는 것 이라면 tree[node] 리턴해준 것의 Sum으로 답이 구성될 것이다.

	if (end < left || right < start) // [start,end] - |left right| - [start,end]
	{
		return 0; //해당 X
	}
	else if (left <= start && end <= right)//해당 되는 노드
	{
		return tree[node];
	}
	else
	{//좌우의 합 해당 되지 않으면 0 + tree[node]의 합으로 답이 구성될것이다.
		return findInterval(tree, node * 2, start, (start + end) / 2, left, right) + findInterval(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
	}

}

//update
//diff = val - a[index]
void update(vector<long long> &tree, int node, int start, int end, int index, int diff)
{
	if (index<start || index>end) return;
	else
	{
		tree[node] = tree[node] + diff;
		if (start != end) //반드시 있어야 하는데 잊었다.
		{
			update(tree, node * 2, start, (start + end) / 2, index, diff);
			update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
		}

	}
}

int main(void)
{

	int n, m, k;
	cin >> n >> m >> k;
	vector<long long> a(n);
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));

	vector<long long> tree(tree_size);//배열 처럼 사용하기 위해서 선언

	for (int i = 0; i<n; i++) {
		cin >> a[i];
	}


	int a1, b1, c1;

	//트리구조를 만들자. (구간의합, 잦은변경) 세그먼트 트리
	recur(a, tree, 1, S, E);


	//인덱스 실수하지마라. -1 해줘야한다.
	for (int i = 0; i < m + k; i++) //M,K 만큼 변경과 출력을 해야한다.
	{
		cin >> a1 >> b1 >> c1;

		if (a1 == 1) //b번째 수를 c로 바꾼다.
		{
			long long diff = c1 - a[b1 - 1];
			a[b1 - 1] = c1;
			update(tree, 1, S, E, b1 - 1, diff);
		}
		else// [b,c] 의 합을 구함.
		{
			long long res;
			res = findInterval(tree, 1, S, E, b1 - 1, c1 - 1);
			cout << res << endl;
		}

	}



	return 0;
}