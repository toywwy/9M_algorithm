/*
���� : ���
���� ��ȣ: 1799
Ǯ�̹� : ��Ʈ��ŷ
��¥ : 18.07.02
��Ÿ :

�밢���鸦 visit�� üũ�ϴ� ����� ���ο� ����Ʈ�ε�.


������� �밢���� ��쿡�� visit[x+y] �� üũ�������ϴ�.

�»���� �밢���� ��쿡�� x-y�� �ϸ�ȴ�. ������ �׷� ������ ������ �κ��� ����� ������ N-x-y �����ش�.
N�� ���� �̱⶧����
visit[N-1+x-y] �̷������� üũ


������ �ذ�����Ʈ 
�ð� ���⵵�� �ٿ��� �Ѵ�. 
������, ������ ���� �����Ѵ� ����� ��������.
 
2^(10*10)  -> 100��
2^(5*5) + 2^(5*5) -> 50���� ���غ���ȴ� ������ 50���� �ʿ���� �����̶�� ����.

*/


#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int arr[12][12]; //,10]

int N, M,len, mMax;

int dx[4] = { -1, 1, 1, -1 }; //���� �� �밢�� ���� �ð�������� ��
int dy[4] = { -1, -1, 1, 1 };

int visit1[24];
int visit2[24];

void recur(int level, int cnt, bool c)
{
	if (level < len)
	{
		int x, y, value = 0;

		if (c == true) value = 2 * level - 1;
		else value = 2 * level;

		y = value / N;
		x = value % N;


		if (arr[y][x] == 1 && 
			visit1[x + y] == false && 
			visit2[N - 1 - y + x] == false)
		{
				visit1[x + y] = true;
				visit2[N - 1 - y + x] = true;

				recur(level + 1, cnt + 1, c);

				visit1[x + y] = false;
				visit2[N - 1 - y + x] = false;
		}
		
		recur(level + 1, cnt, c);
		
	}
	else {
		mMax = max(mMax, cnt);
		int k = mMax;
	}

}


int main(void)
{
	cin >> N;
	len = N*N;
	bool chk;
	int len1, len2;
	
	if (len % 2 == 0) {//¦��
		chk = false;
	}
	else {//Ȧ�� - ������ Ȧ���϶� ¦������
		len1= (len + 1) / 2;
		chk = true;
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];


	//�ΰ��� ������ �ջ��� �ϸ� �ȴ�.
	int res = 0;
	
	mMax = 0;
	recur(0, 0, true);//Ȧ����
	res += mMax;

	mMax = 0;
	if(chk==true) len--;
	//¦�����ٸ� ���� ���⶧���� �������ȵȴ�.
	//������ Ȧ���϶��� ���� �� �ް� �ȴ�.

	recur(0, 0, false);//¦���϶��� 
	res += mMax;

	cout << res << endl;


	return 0;
}