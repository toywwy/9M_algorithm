/*
문제 : 최소값과 최대값
문제 번호: 2357
풀이법 : 세그먼트트리
날짜 : 18.06.11
기타 :

return을 안쓰고 하위의 값에 접근한다.
부모노드 = node * 2 , node * 2 +1 이기 때문에 접근이 가능하다.

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
	else //한번에 두개를 구상할 방법을 찾는다.
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
	//최소값과 최대값 query가 다르다.
	if (right < start || end < left)
	{
		chk = false;
		return;
	}
	else if (left <= start && end <= right)
	{
		//어떤 값이던 같다 사실.
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

		//더크고 더 작은 애가 mMax, mMin에 각각 저장된다.

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
