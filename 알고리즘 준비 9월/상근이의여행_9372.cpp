/*
���� : ������ǿ���
���� ��ȣ: 9372
Ǯ�̹� : ���д�Ʈ��
��¥ : 18.07.20
��Ÿ : ���̾��� ���� 
������ N-1
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
