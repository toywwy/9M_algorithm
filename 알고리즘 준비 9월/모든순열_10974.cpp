/*
���� :		������
���� ��ȣ:	10974
Ǯ�̹� :		next_permutation
��¥ :		161016
��Ÿ :		

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;


//ù° �ٿ� �Է����� �־��� ������ ������ ���� ������ ����Ѵ�.����, ���������� �������� ���� ������ ��쿡�� - 1�� ����Ѵ�.
int main(void)
{
	int n;
	cin >> n;

	vector<int> v;

	for (int i = 1; i <= n; i++)
		v.push_back(i);

	for (int a : v)
		printf("%d ", a);
	printf("\n");

	while (next_permutation(v.begin(), v.end()))
	{
		for (int a : v)
			printf("%d ", a);
		printf("\n");
	}
	return 0;
}