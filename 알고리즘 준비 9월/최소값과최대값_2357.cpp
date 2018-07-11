/*
���� : �ּҰ��� �ִ밪
���� ��ȣ: 2357
Ǯ�̹� : ���׸�ƮƮ��
��¥ : 18.06.11
��Ÿ :

return�� �Ⱦ��� ������ ���� �����Ѵ�.
�θ��� = node * 2 , node * 2 +1 �̱� ������ ������ �����ϴ�.

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define MAX 100000
#define INF 1987654321
using namespace std;


int N, M;


int arr[MAX + 4];


vector<int> maxTree;
vector<int> minTree;

void recur(int start, int end, int node)
{
	if (start == end) minTree[node] =  maxTree[node] = arr[start]; //leaf
	else //�ѹ��� �ΰ��� ������ ����� ã�´�.
	{
		recur(start, (start + end) / 2, node * 2);
		recur((start + end) / 2+1,end , node * 2 + 1);
		
		minTree[node] = min(minTree[node * 2], minTree[node * 2 + 1]);
		maxTree[node] = max(maxTree[node * 2], maxTree[node * 2 + 1]);
	}
}

int mMax = -1;
int mMin = 1987654321;

bool chk;
void query(int start,int end,int node, int left,int right)
{
	//�ּҰ��� �ִ밪 query�� �ٸ���.
	if (right < start || end < left)
	{
		chk = false;
		return;
	}
	else if (left <= start && end <= right)
	{
		//� ���̴� ���� ���.
		mMax = max(mMax,maxTree[node]);
		mMin = min(mMin,minTree[node]);
		chk = true;
	}
	else
	{
		query(start, (start + end) / 2, node * 2, left, right);

		if (chk == true) {
			mMax = max(mMax, maxTree[node * 2]);
			mMin = min(mMin, minTree[node * 2]);
			chk = false;
		}

		query((start + end) / 2 + 1 , end , node * 2 + 1, left, right);

		if (chk == true) {
			mMax = max(mMax, maxTree[node * 2 + 1]);
			mMin = min(mMin, minTree[node * 2 + 1]);
			chk = false;
		}

		//��ũ�� �� ���� �ְ� mMax, mMin�� ���� ����ȴ�.

	}

}


int main(void)
{
	
	scanf("%d %d", &N, &M);
	
	maxTree.resize(MAX * 4 + 4);
	minTree.resize(MAX * 4 + 4);

	for (int i = 0; i < N; i++) cin >> arr[i];

	
	recur(0, N - 1, 1);


	/*
	int mMax = -1;
	int mMin = 1987654321;
	*/

	int a, b;
	for (int i = 0; i < M; i++)
	{
		
		mMax = -1;
		mMin = INF;
		chk = false;
		scanf("%d %d", &a, &b);
		query(0, N - 1, 1, a - 1, b - 1);

		printf("%d %d\n", mMin, mMax);
	}


	return 0;
}
