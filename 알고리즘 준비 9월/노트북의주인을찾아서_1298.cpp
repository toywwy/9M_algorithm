/*
���� : ��Ʈ���� ������ ã�Ƽ�
���� ��ȣ: 1298
Ǯ�̹� : �̺и�Ī
��¥ : 18.06.30
��Ÿ :


//���� �������� �ٽô� �ȳ��� ������...

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;


int N, M, a, b,res;//�����= ��Ʈ�ϼ�
//N(1 �� N �� 100)�� ��Ʈ�� ������ ���� M(0 �� M �� 5,000) �־�����.

vector<int> v[103];


bool visit[103];//�̻���� ��Ī�̳�����..

int Man[103];//����� ���� �Ǿ���
int PC[103];//�Ǿ��� ������ ����� ���̴�.


bool recur(int man)
{
	visit[man] = true;

	for (int pc : v[man])
	{
		if (PC[pc] == -1|| ( visit[PC[pc]]==false && recur(PC[pc]) ))
		{//PC[pc] == -1 �� PC�� ��� �������Ե� �Ҵ�����ʾҴ�.
			//visit[PC[pc]]==false �� PC�� ���� recur���� �湮������ ����. �湮�� ��ġ�� �ִ�.
			//recur(PC[pc]) pc���� �Ҵ�� �������� recurcive�� �Ͽ� �� ������ �ٸ� PC�� �����Ҽ� �ִ��� Ȯ���غ���.
			Man[man] = pc;
			PC[pc] = man;
			return true;
		}
	}

	return false;
}

int main(void)
{
	cin >> N >> M;
	fill(Man, Man + N+1, -1);
	fill(PC, PC+N+1, -1);

	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		v[a].push_back(b);//a�� b�� �ڱ� ��Ʈ���̶� �����Ѵ�.
	}

	res = 0;

	
	for (int i = 1; i <= N; i++)
	{
		if (Man[i] == -1)//�ϴ� ����� �������� ������ ��Ű�� ���̴�.
		{
			fill(visit, visit + N +1, false);

			if (recur(i) == true)
			{//i�� ��Ī�� �����ߴٸ�, i������ ���������� ������ ���ο� �����ߴٸ�.
				res++;
			}
		}
	}

	cout << res << endl;

	return 0;
}
