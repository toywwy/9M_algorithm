/*
문제 : 히스토그램에서 가장 큰 직사각형
문제 번호: 6549
풀이법 : 분할정복
날짜 : 18.07.11
기타 : 세그먼트트리, 분할 정복이용

구현에서 세그먼트트리에 구간의 제일 작은 것의 인덱스를 저장한다.

문제 풀이 - 

제일 작은애를 골랐고 그놈을 선택한 넓이는 구했다.
그래서 걔를 제외한 상태에서 진행한다.
다시 제일 작은애를 고른다. 그리고 넓이를 구한다.

가장 중요한건 제일 작은애를 골랐을때 그 상태에서 구할수있는 넓이는 제일 컷기 때문에
제일 작은 애를 제외 시키고 나머지에서 분할 정복이 가능하다.

구간의 최소값은 블로그: 세그먼트 트리 (Segment Tree)를 이용해서 구할 수 있습니다. 따라서, 시간 복잡도는 O(NlgN)이 됩니다. (모든 막대에 대해서: O(N), 구간의 최소값을 구함: O(lgN))

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

//(1 ≤ n ≤ 100, 000) 그 다음 n개의 정수 h1, ..., hn(0 ≤ hi ≤ 1000000000)

int arr[100002];
vector<int> tree;
long long mMax;
int N;

//인덱스를 저장해 주어야한다.
void init(int start,int end, int node)
{
	if (start == end) tree[node] = start;
	else
	{
		init(start, (start + end) / 2, node * 2);
		init((start + end) / 2 + 1,end, node * 2 + 1);
		
		if (arr[tree[node * 2]] <= arr[tree[node * 2 + 1]])
		{
			tree[node] = tree[node * 2];
		}
		else
		{
			tree[node] = tree[node * 2 + 1];
		}

	}
}

int query(int node, int start, int end, int left, int right) {
	if (left > end || right < start) { //범위를 벗어나면 -1
		return -1;
	}
	if (left <= start && end <= right) { //범위내에 있다 인덱스 리턴
		return tree[node];
	}
	int m1 = query(2 * node, start, (start + end) / 2, left, right);
	int m2 = query(2 * node + 1, (start + end) / 2 + 1, end, left, right);

	//양쪽에서 받아온 인덱스를 비교한다.
	if (m1 == -1) {
		return m2;
	}
	else if (m2 == -1) {
		return m1;
	}
	else {
		if (arr[m1] <= arr[m2]) {
			return m1;
		}
		else {
			return m2;
		}
	}
}


long long largest(int start, int end) {
	int m = query(1, 0, N - 1, start, end);

	long long area = (long long)(end - start + 1)*(long long)arr[m];//넓이를 구한다.

	if (start <= m - 1) {
		long long temp = largest(start, m - 1);
		if (area < temp) {
			area = temp;
		}
	}
	if (m + 1 <= end) {
		long long temp = largest(m + 1, end);
		if (area < temp) {
			area = temp;
		}
	}
	return area;
}

int main(void)
{
	while (1)
	{
		cin >> N;
		if (N == 0) break;

		int h = (int)(ceil(log2(N)) + 1e-9);
		int tree_size = (1 << (h + 1));

		for (int i = 0; i < N; i++) cin >> arr[i];

		tree.resize(tree_size);


		init(0,N-1,1);

		cout << largest(0, N - 1) << endl;

	}


	return 0;
}