/*
���� : �Ҽ����ϱ�
���� ��ȣ: 1929
Ǯ�̹� : ������׽�ü
��¥ : 20161002
��Ÿ : 

*/



#include<iostream>
#define SIZE 1000000
using namespace std;
//(1��M��N��1, 000, 000)

bool check[SIZE];

int main(void)
{
	
	int from,to;
	cin >> from >> to;

	check[0] = 1;
	check[1] = 1;
	check[2] = false; //2�� �Ҽ���

	
	for (int i = 2; i <= to; i++) //to���� �Ҽ����� �Ǻ��ϸ�ȴ�.
	{
		if (check[i]) continue; //�Ҽ��� �ƴϸ� ����

		for (int j = 2; i*j <= to; j++)
			check[i*j] = 1;
	}

	for (int i = from; i <= to; i++)
		if (!check[i]) printf("%d ", i);

	cout << endl;

	return 0;
}