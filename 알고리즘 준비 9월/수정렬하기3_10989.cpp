/*
���� : �� �����ϱ� 3
���� ��ȣ: 10989
Ǯ�̹� : QuickSort
��¥ : 170502
��Ÿ : �ߺ��� ����. quick �����ؾ���.
*/

#include<iostream>
using namespace std;
int arr[10001];//�ߺ��� �ִ�. ��ó�� ����ؼ� �����ϰ���

int main(void)
{
	int N, k = 0, max = 0;
	scanf("%d", &N);//N 1õ������ 
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &k);
		if (max < k) max = k;
		arr[k] += 1;
	}

	for (int i = 0; i <=max; i++)//���⼭ N��ŭ �迭�� ��ȸ�ع����� �迭 ����
		for (int j = 0; j < arr[i]; j++)
			printf("%d\n", i);

	return 0;
}