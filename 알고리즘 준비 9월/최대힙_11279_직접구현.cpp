/*

���� : �ִ���
���� ��ȣ: 11279
Ǯ�̹� : ��
��¥ : 180821
��Ÿ : 
stl �����ʰ� �������� �����Ѵ�.

*/

#include<iostream>
#include<cstdio>

using namespace std;

int N;

int heap[100002];
int heapSize;

void heapPop() {
	if (heapSize < 1) return;
	heap[0] = heap[heapSize-1];
	heap[heapSize - 1] = 0;
	heapSize -= 1;

	int idx = 0; //�ε��� �� �����ؾ��Ѵ�...
	while (2*idx + 2 < heapSize)//�ٽ�����..
	{
		int left = 2 * idx + 1;
		int right = 2 * idx + 2;

		if (heap[left] < heap[right])
		{
			if (heap[right] > heap[idx])
			{
				int temp = heap[idx];
				heap[idx] = heap[right];
				heap[right] = temp;
				idx = right;
			}
			else break;
		}
		else
		{
			if (heap[left] > heap[idx])
			{
				int temp = heap[idx];
				heap[idx] = heap[left];
				heap[left] = temp;
				idx = left;
			}
			else break;
		}
	}
	if (2 * idx + 1 < heapSize)
	{
		int left = 2 * idx + 1;
		if (heap[left] > heap[idx])
		{
			int temp = heap[idx];
			heap[idx] = heap[left];
			heap[left] = temp;
			idx = left;
		}
	}

}


void heapPush(int v)
{
	heap[heapSize] = v;
	int idx = heapSize;
	heapSize += 1;//ó���� �ϳ� �÷��ְ� �ٵ� 1�� �����ؼ� �Ϸ���..

	while (idx > 0) // idx�� 1�̵ȴٸ� ....�θ𰡾��ݾ�. 1�̻��� �Ǿ���Ѵ�. //�ε����� -1
	{
		int parent = (idx-1) >> 1;
		if (heap[idx] > heap[parent])//�ڽ��� ��ũ�ٸ� ���� �ö󰡾��Ѵ�.
		{
			int temp = heap[parent];
			heap[parent]= heap[idx];
			heap[idx] = temp;//swap�Ѵ�.
			
			idx = parent;
		}
		else break;//���ö󰡰� �ٷ� ��
	}

}

int main(void)
{
	scanf("%d", &N);
	heapSize = 0;
	int input;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &input);
		if (input == 0)
		{	
			printf("%d\n", heap[0]);
			heapPop();
		}
		else //heapPush();
		{
			heapPush(input);
		}
	}

	return 0;
}
