/*
문제 : 상근이의여행
문제 번호: 9372
풀이법 : 스패닝트리
날짜 : 18.07.20
기타 : 어이없는 문제 
정답은 N-1
*/

#include<stdio.h>
void main()
{
	int t, N, M;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d", &N,&M);
		printf("%d ", N-1);
		for (int j = 0; j < M * 2; j++) scanf("%d", &N);
	}
}
