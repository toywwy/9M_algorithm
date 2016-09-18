
/*
���� : ��Ʈ��ũ����
���� ��ȣ: 1922
Ǯ�̹� : ���ͽ�Ʈ��
��¥ : 160916
��Ÿ : prim�˰��������� ���� �ذ�
������ ��� ã�ư��� ������� 
ũ�罺Į�� �����ϴ¹��� �� �����ٰ��Ѵ�.
*/


#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>

#define N 1000


using namespace std;

class Con {
public:
	int s;
	int e;
	int w;

	Con(int s, int e, int w)
	{
		this->s = s;
		this->e = e;
		this->w = w;
	}
};

struct priority {
	bool operator()(Con a, Con b)
	{
		return a.w > b.w;//�갡 ũ�� ����Ī���ϰڴ�.
	}
};


int arr[N + 2][N + 2];
bool flag[N + 2];

//vector<int> v[N + 2];

int main(void)
{
	int n, line;//��ǻ�ͼ� 1000, ������ ���Ǽ� 100000
	cin >> n >> line;

	//��� ��ǻ�͸� �����ϸ�ȴ�. ������̴�.
	int a, b, w;

	//����� ���� ����ü��
	priority_queue<Con, vector<Con>, priority> PQ;

	for (int i = 0; i < line; i++)
	{
		scanf("%d %d %d", &a, &b, &w);
		arr[a][b] = arr[b][a] = w;
		//�곽 �����̾���.
	}

	for (int i = 2; i <= n; i++)
	{
		if (arr[1][i] != 0)
			PQ.push(Con(1, i, arr[1][i]));
		else if(arr[i][1] != 0)
			PQ.push(Con(1, i, arr[1][i]));
	}
	flag[1] = 1;
	int cnt = 1;
	int value = 0;

	while (!PQ.empty())
	{
		Con s = PQ.top(); 
		PQ.pop();

		//���߿� �ϳ��� 0�ϰž� 
		if (flag[s.s] == 0)
		{
			for (int i = 1; i <= n; i++)
			{
				if (arr[s.s][i] != 0)
					PQ.push(Con(s.s, i, arr[s.s][i]));
				else if (arr[i][s.s] != 0)//�̷����ϸ� ���� �ΰ��� �������ʿ�� ���µ�.. ������ �ι� Ȯ���Ұ�.
					PQ.push(Con(s.s, i, arr[s.s][i]));
			}
			flag[s.s] = 1;
			value += s.w;
			cnt++;
		}
		else if (flag[s.e] == 0)
		{
			for (int i = 1; i <= n; i++)
			{
				if (arr[s.e][i] != 0)
					PQ.push(Con(s.e, i, arr[s.e][i]));
				else if (arr[i][s.e] != 0)
					PQ.push(Con(s.e, i, arr[s.e][i]));
			}
			flag[s.e] = 1;
			value += s.w;
			cnt++;
		}

		if (cnt >= n)
			break;
		                         
	}
	cout << value << endl;

	return 0;
}