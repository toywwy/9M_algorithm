/*
���� : ��Ʈ����
���� ��ȣ:1327
Ǯ�̹� : BFS
��¥ : 16
��Ÿ : ���̺귯���� �����ؼ� Ǯ����.


������� visit, flag üũ�� �ұ�?

���� Ž���̳�? �Ѵٵ�����.
�ִܰ�γ�? BFS �ؾ��Ѵ�.
�ִܰ�θ� DFS�ϰ� �Ǹ� ����Ž���ϰԵȴ�.

BFS�� �ٽ� �ؾ��Ѵ�.

�� ��ü �̷� �Ǽ��� �Ѱ���..
����������� visit�� üũ���� ���Ѵ� 
8 �ڸ� ..��Ʈ��ǥ������
set���� ��Ʈ�� ǥ���Ҽ� �ִ� ����� ������?? ������ ���� X

�׷����ϴ� string �� SET���� �����ؼ� ����� �ߴ�.
������ set�� �����ϱ� ���ؼ��� hash ����ؾ� �Ѵ�. �ѹ��� ã�����ִ�..

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<queue>


using namespace std;

typedef pair<string, int> P;

int input[10];//N�� 2���� ũ�ų� ����, 8���� �۰ų� ����.
int mQueue[200000];
int front;
int rear;


int N, K, C;


bool resCheck;
//�������� üũ
inline bool checkASC(int arr[])
{
	int k = arr[0];
	for (int i = 1; i < N; i++)
	{
		if (arr[i - 1] > arr[i]) return false;
	}
	return true;
}


set<string> visit;
queue<P> q;


int main(void)
{
	cin >> N >> K;
	string input;
	input.resize(10);
	for (int i = 0; i < N; i++)
	{
		char c;
		cin >> c;
		input[i] = c;
	}
	int resCnt=0;
	bool resChk = false;
	string res = input;//�����Ͽ� �̸� ������ �ȴ�.
	
	sort(res.begin(), res.begin() + N);

	if (input == res)
	{
		cout << resCnt << endl;
		return 0;
	}

	visit.insert(input);
	q.push(P(input,1));

	C = N - K;
	while (q.size() > 0)
	{
		P top = q.front(); q.pop();
		for (int i = 0; i <= C; i++)
		{
			string str = top.first; //�Ź� ���ο�� �ؾ��Ѵ�.

			int R = i + K- 1;

			for (int j = 0; j < K/2 ; j++)
			{
				//�پ��� �ֶ� �����ϴ¾ֱ������ſ�
				char temp = str[j+i];//�����ϴ¾�
				str[i + j] = str[R-j];
				str[R-j] = temp;
			}


			if (str == res)
			{
				while (!q.empty()) q.pop();
				resCnt = top.second;
				resChk = true;
				break;
			}
				
			if (visit.find(str) == visit.end()) {
				visit.insert(str);
				q.push(P(str,top.second+1));
			}

		}
	}
	if (resChk)
		cout << resCnt << endl;
	else
		cout << -1 << endl;


	return 0;
}
