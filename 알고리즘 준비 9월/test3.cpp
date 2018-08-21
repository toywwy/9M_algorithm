#include<iostream>
#include<cstdio>
#define MAX_SIZE 100

using namespace std;


class Node
{
public:
	int value;
}nodes[100000];

int idx = 0;

Node * newNode()
{
	return &nodes[idx++];
}

Node heap[MAX_SIZE];
int heapSize = 0;

void heapInit(void)
{
	heapSize = 0;
}

int heapPush(Node *value)
{
	if (heapSize + 1 > MAX_SIZE)
	{
		printf("queue is full!");
		return 0;
	}

	heap[heapSize] = *value;//이러면 값으로 넣는건대 ...음 ..문제없나?

	int current = heapSize;
	while (current > 0 && heap[current].value < heap[(current - 1) / 2].value)
	{
		int temp = heap[(current - 1) / 2].value;
		heap[(current - 1) / 2].value = heap[current].value;
		heap[current].value = temp;
		current = (current - 1) / 2;
	}

	heapSize = heapSize + 1;

	return 1;
}


int heapPop()
{
	if (heapSize <= 0)
	{
		return -1;
	}

	//*value = heap[0].value;
	heapSize = heapSize - 1;

	heap[0].value = heap[heapSize].value;

	int current = 0;
	while (current * 2 + 1 < heapSize)
	{
		int child;
		if (current * 2 + 2 == heapSize)
		{
			child = current * 2 + 1;
		}
		else
		{
			child = heap[current * 2 + 1].value < heap[current * 2 + 2].value ? current * 2 + 1 : current * 2 + 2;
		}

		if (heap[current].value < heap[child].value)
		{
			break;
		}

		int temp = heap[current].value;
		heap[current].value = heap[child].value;
		heap[child].value = temp;

		current = child;
	}

	return 1;
}

int main(int argc, char* argv[])
{
	int T, N,M;

	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; test_case++)
	{
		cin >> N >> M;

		heapInit();

		for (int i = 0; i < M; i++)
		{
			int a, b;
			int value;
			cin >> a >> b >> value;

			Node *p = newNode();
			p->value = value;
			heapPush(p);
		}

		//이제 여기서 루트 부터 정렬해보자.

		for (int i = 0; i < N; i++)
		{
			int value;
			int temp = heap[0].value;
			heapPop();
			printf(" %d %d\n", temp,temp);
		}
		printf("\n");
	}
	return 0;
}