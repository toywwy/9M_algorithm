/*
���� :		��������
���� ��ȣ:	10972
Ǯ�̹� :		cmath next_permutation
��¥ :		161016
��Ÿ :		
�Է¹������� ���� ������ ����Ѵ�.
�������̶�� 
-1 ���

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

	int inp;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &inp);
		v.push_back(inp);
	}

	if (next_permutation(v.begin(), v.end()))
	{
		for (int a : v)
			cout << a << ' ';
	}
	else
		cout << -1;

	cout << endl;

	return 0;
}
