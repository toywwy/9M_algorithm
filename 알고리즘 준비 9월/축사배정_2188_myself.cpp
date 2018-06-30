/*
���� : ������
���� ��ȣ: 2188
Ǯ�̹� : �̺� ��Ī(Bipartite Matching)
��¥ : 18.06.30
��Ÿ :

������ Ǯ���
Vector�����ϰ� 2���� �迭 �̿��ؼ� Ǭ��.

*/


#include<iostream>
using namespace std;

int N, M;
int adj[202][202];//�迭�� ���ԵǸ� �޸𸮸� �����ϱ� ��ƴ�....�ƹ����� vector�� �Ⱦ� �Ѱ�
int len[202];//������ length�� ���� �����ϸ�ȴ�.

int Cow[202];
int Room[202];

bool visit[202];

int recur(int cow)
{
	//���⼭ ���� visit�� üũ���ص��Ǵ������� ���� �����̾���.
	visit[cow] = true;

	for (int i = 0; i < len[cow]; i++)
	{
		int room = adj[cow][i];

		if (Room[room] == -1 || (visit[Room[room]] == false && recur(Room[room])))
		{
			Room[room] = cow;
			Cow[cow] = room;
			return true;
		}
		
	}
	return false;
}


int main(void)
{
	int input,b,ans=0;
	cin >> N >> M;

	for (int i = 0; i < N + 1; i++) Cow[i] = Room[i] = -1;

	for (int i = 0; i < N; i++)
	{
		cin >> input;
		for (int j = 0; j < input; j++)
		{
			cin >> b;
			len[i] = input;//����
			adj[i][j] = b - 1;// index 0���� ���� �ҰŴ�.
		}
	}

	
	for (int i = 0; i < N; i++)
	{
		if (Cow[i] == -1)
		{
			for (int i = 0; i < N + 1; i++) visit[i] = false;
			if (recur(i)) ans++;
		}
	}

	cout << ans << endl;

	return 0;
}