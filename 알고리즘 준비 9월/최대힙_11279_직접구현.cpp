/*

문제 : 최대힙
문제 번호: 11279
풀이법 : 힙
날짜 : 180821
기타 : 
stl 쓰지않고 직접구현 구현한다.

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

	int idx = 0; //인덱스 잘 생각해야한다...
	while (2*idx + 2 < heapSize)//다시조정..
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
	heapSize += 1;//처음에 하나 늘려주고 근데 1로 세팅해서 하려면..

	while (idx > 0) // idx가 1이된다면 ....부모가없잖아. 1이상이 되어야한다. //인덱스라 -1
	{
		int parent = (idx-1) >> 1;
		if (heap[idx] > heap[parent])//자식이 더크다면 위로 올라가야한다.
		{
			int temp = heap[parent];
			heap[parent]= heap[idx];
			heap[idx] = temp;//swap한다.
			
			idx = parent;
		}
		else break;//못올라가고 바로 끝
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
