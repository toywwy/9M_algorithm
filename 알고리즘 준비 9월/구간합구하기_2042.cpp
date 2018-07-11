/*
���� : ���� �� ���ϱ�
���� ��ȣ: 2042
Ǯ�̹� : ���׸�ƮƮ��
��¥ : 18.06.10
��Ÿ :
�⺻���� ���׸�ƮƮ������

*/

#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<cstdio>

#define S 0
#define E n-1
using namespace std;

//�� ���� ���� a,b,c�� �־����µ�, a�� 1�� ��� b��° ���� c�� �ٲٰ� a�� 2�� ��쿡�� b��° ������ c��° �������� ���� ���Ͽ� ����ϸ� �ȴ�.

//N(1 <= N <= 1, 000, 000)�� M(1 <= M <= 10, 000), K(1 <= k <= 10, 000)


long long recur(vector<long long> &arr, vector<long long> &tree, int node, int start, int end)
{
	//������ tree�� node�� ä��� ���̴�.
	if (start >= end)
	{
		return tree[node] = arr[start];// ��� ���� ���� ����
	}
	else
	{
		//Ʈ���� ������������ �θ����� �����ڽ� (node*2)+�������ڽ� (node*2+1) ���� ���� ����� �����鼭 Ʈ���� ��������.
		return tree[node] = recur(arr, tree, node * 2, start, (start + end) / 2) + recur(arr, tree, node * 2 + 1, (start + end) / 2 + 1, end);
	}
}


long long findInterval(vector<long long> &tree, int node, int start, int end, int left, int right)
{
	//�ش��� ���� ������ 0�� �����ϰԵǰ�, �ش�Ǵ� �� �̶�� tree[node] �������� ���� Sum���� ���� ������ ���̴�.

	if (end < left || right < start) // [start,end] - |left right| - [start,end]
	{
		return 0; //�ش� X
	}
	else if (left <= start && end <= right)//�ش� �Ǵ� ���
	{
		return tree[node];
	}
	else
	{//�¿��� �� �ش� ���� ������ 0 + tree[node]�� ������ ���� �����ɰ��̴�.
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
		if (start != end) //�ݵ�� �־�� �ϴµ� �ؾ���.
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

	vector<long long> tree(tree_size);//�迭 ó�� ����ϱ� ���ؼ� ����

	for (int i = 0; i<n; i++) {
		cin >> a[i];
	}


	int a1, b1, c1;

	//Ʈ�������� ������. (��������, ��������) ���׸�Ʈ Ʈ��
	recur(a, tree, 1, S, E);


	//�ε��� �Ǽ���������. -1 ������Ѵ�.
	for (int i = 0; i < m + k; i++) //M,K ��ŭ ����� ����� �ؾ��Ѵ�.
	{
		cin >> a1 >> b1 >> c1;

		if (a1 == 1) //b��° ���� c�� �ٲ۴�.
		{
			long long diff = c1 - a[b1 - 1];
			a[b1 - 1] = c1;
			update(tree, 1, S, E, b1 - 1, diff);
		}
		else// [b,c] �� ���� ����.
		{
			long long res;
			res = findInterval(tree, 1, S, E, b1 - 1, c1 - 1);
			cout << res << endl;
		}

	}



	return 0;
}