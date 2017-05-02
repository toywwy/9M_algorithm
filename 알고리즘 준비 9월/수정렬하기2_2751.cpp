/*
���� : �� �����ϱ� 2
���� ��ȣ: 2751
Ǯ�̹� : QuickSort
��¥ : 170502
��Ÿ : �ߺ��� ����. quick �����ؾ���.
*/

#include<iostream>
using namespace std;
int arr[1000001];
void quickSort(int left, int right)
{
	int pivot = arr[right], up = left, down = right;
	while (up < down)
	{
		while (pivot > arr[up]) up++;
		while (pivot < arr[down]) down--;
		if (up <= down) swap(arr[up++], arr[down--]);
	}
	if (left < down) quickSort(left, down);
	if (up < right) quickSort(up, right);
}

int main(void)
{
	int N = 0;
	cin >> N;
	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
	quickSort(0, N - 1);
	for (int i = 0; i < N; i++) printf("%d\n", arr[i]);


	return 0;
}