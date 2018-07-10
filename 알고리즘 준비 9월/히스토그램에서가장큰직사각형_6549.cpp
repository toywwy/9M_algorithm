/*
���� : ������׷����� ���� ū ���簢��
���� ��ȣ: 6549
Ǯ�̹� : ��������
��¥ : 18.07.11
��Ÿ : ���׸�ƮƮ��, ���� �����̿�

�������� ���׸�ƮƮ���� ������ ���� ���� ���� �ε����� �����Ѵ�.

���� Ǯ�� - 

���� �����ָ� ����� �׳��� ������ ���̴� ���ߴ�.
�׷��� �¸� ������ ���¿��� �����Ѵ�.
�ٽ� ���� �����ָ� ����. �׸��� ���̸� ���Ѵ�.

���� �߿��Ѱ� ���� �����ָ� ������� �� ���¿��� ���Ҽ��ִ� ���̴� ���� �Ʊ� ������
���� ���� �ָ� ���� ��Ű�� ���������� ���� ������ �����ϴ�.

������ �ּҰ��� ��α�: ���׸�Ʈ Ʈ�� (Segment Tree)�� �̿��ؼ� ���� �� �ֽ��ϴ�. ����, �ð� ���⵵�� O(NlgN)�� �˴ϴ�. (��� ���뿡 ���ؼ�: O(N), ������ �ּҰ��� ����: O(lgN))

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

//(1 �� n �� 100, 000) �� ���� n���� ���� h1, ..., hn(0 �� hi �� 1000000000)

int arr[100002];
vector<int> tree;
long long mMax;
int N;

//�ε����� ������ �־���Ѵ�.
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
	if (left > end || right < start) { //������ ����� -1
		return -1;
	}
	if (left <= start && end <= right) { //�������� �ִ� �ε��� ����
		return tree[node];
	}
	int m1 = query(2 * node, start, (start + end) / 2, left, right);
	int m2 = query(2 * node + 1, (start + end) / 2 + 1, end, left, right);

	//���ʿ��� �޾ƿ� �ε����� ���Ѵ�.
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

	long long area = (long long)(end - start + 1)*(long long)arr[m];//���̸� ���Ѵ�.

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