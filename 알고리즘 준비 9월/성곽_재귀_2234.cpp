/*
���� : ����
���� ��ȣ: 2234
Ǯ�̹� : ���
��¥ : 161001
��Ÿ : visit�� ��ġ�� �߿��� ������ ��ģ��. �׸���
3���� ���� ����ϴµ� ....�𸣰� ������ ���� �˻縦���ߴ�. �Ѵ� x-1 y
y-1 x �ϋ��� ���縦 �߾�����ߴ�.

���
1. ���ǰ��� - �׷��� ����
2. ���� ���� ���� ���� - �׷��� ������ ���� ���� ���� � ��?

3. �ϳ��� ���� �����Ͽ� ������ �ִ� ���� ������...

*/



#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

typedef unsigned short usint;
typedef unsigned char uchar;

typedef pair<uchar, uchar> P;

uchar arr[52][52];//���⼭ �׷쵵 ���� ������.

usint group[52][52];//���⼭ �׷쵵 ���� ������.
bool v[52][52];
usint cnt[2502];

int gCnt = 1;//1���� �׷��� ���� ��������?
			 //��� �� ����ص� �Ǳ��ϴµ�
int mCnt = 0;
int mV = 0;
bool check[16][4]{
	{ 0,0,0,0 },//ignore
	{ 1,0,0,0 },//1
	{ 0,1,0,0 },//2
	{ 1,1,0,0 },//3
	{ 0,0,1,0 },//4
	{ 1,0,1,0 },//5
	{ 0,1,1,0 },//6
	{ 1,1,1,0 },//7
	{ 0,0,0,1 },//8
	{ 1,0,0,1 },//9
	{ 0,1,0,1 },//10
	{ 1,1,0,1 },//11
	{ 0,0,1,1 },//12
	{ 1,0,1,1 },//13
	{ 0,1,1,1 },//14
	{ 1,1,1,1 }///15
};

int dx[] = { -1,0,1,0 }; //���� �� ������ �Ʒ�
int dy[] = { 0,-1,0,1 }; //�̷������� Ž��


void recur(int x, int y)
{
	for (int k = 0; k < 4; k++)
	{
		if (!check[arr[y][x]][k])//1�� �ƴϸ� 0�̿��� ���� ���ٸ�
			if (!v[y + dy[k]][x + dx[k]])//�湮 ���� ���� ���̶��
			{//p.first + dy[k]>=1 && p.first + dy[k]<=row && p.second + dx[k]>=1 && p.second + dx[k]<= col &&
				group[y + dy[k]][x + dx[k]] = gCnt;
				v[y + dy[k]][x + dx[k]] = 1;
				cnt[gCnt] += 1;
				recur(x + dx[k], y + dy[k]);
			}
	}

}
int main(void)
{
	int row, col;
	cin >> col >> row;//row ��, col ��

					  //�Է�
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= col; j++)
			scanf("%d", &arr[i][j]);



	queue<P> q;

	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			if (!v[i][j])
			{
				v[i][j] = 1;
				group[i][j] = gCnt;
				cnt[gCnt] += 1;

				recur(j, i);

				if (mCnt < cnt[gCnt])
					mCnt = cnt[gCnt];
				gCnt += 1;
			}
		}
	}

	mV = mCnt;
	//TODO arr ������ ������� �׷��� ������ ����������.

	//�迭�� �Ʒ� ���� Ȯ���ϸ鼭 Ž���Ѵ�. �ٸ��� ���ļ� �ִ밪�� ����
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			if (j <col)
				if (group[i][j] != group[i][j + 1])//�ٸ� �׷��϶� ���ĺ�
					if (mV < (cnt[group[i][j]] + cnt[group[i][j + 1]]))
						mV = cnt[group[i][j]] + cnt[group[i][j + 1]];
			if (i <row)
				if (group[i][j] != group[i + 1][j])//�ٸ� �׷��϶� ���ĺ�
					if (mV < (cnt[group[i][j]] + cnt[group[i + 1][j]]))
						mV = cnt[group[i][j]] + cnt[group[i + 1][j]];
		}
	}


	cout << gCnt - 1 << endl;
	cout << mCnt << endl;
	cout << mV << endl;

	return 0;
}


