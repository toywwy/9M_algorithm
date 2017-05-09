/*
문제 : 수 정렬하기 3
문제 번호: 10989
풀이법 : QuickSort
날짜 : 170502
기타 : 중복이 없다. quick 정렬해야함.
*/

#include<iostream>
using namespace std;
int arr[10001];//중복이 있다. 맵처럼 사용해서 정렬하겠음

int main(void)
{
	int N, k = 0, max = 0;
	scanf("%d", &N);//N 1천만까지 
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &k);
		if (max < k) max = k;
		arr[k] += 1;
	}

	for (int i = 0; i <=max; i++)//여기서 N만큼 배열을 순회해버리면 배열 터짐
		for (int j = 0; j < arr[i]; j++)
			printf("%d\n", i);

	return 0;
}