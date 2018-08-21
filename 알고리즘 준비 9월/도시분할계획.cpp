/*
문제 :
문제 번호:
풀이법 :
날짜 :
기타 :

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define SIZE 10002
#define LEN 200004
using namespace std;

int N, M;

class Node
{
public:
	int to;
	int value;
	Node *prev;
};//M은 백만이었다.


int idx = 0;
Node * newNode()
{
	return 0;// &nodes[idx++];
}

Node * ids[SIZE];//10만개
Node heap[SIZE];
bool visit[SIZE];

int heapSize = 0;
void heapInit(void)
{
	heapSize = 0;
}

int heapPush(Node *value)
{
	if (heapSize + 1 > SIZE)
	{
		return 0;
	}

	heap[heapSize] = *value;

	int current = heapSize;
	while (current > 0 && heap[current].value < heap[(current - 1) / 2].value)
	{
		int tempValue = heap[(current - 1) / 2].value;
		int tempTo = heap[(current - 1) / 2].to;
		
		heap[(current - 1) / 2].value = heap[current].value;
		heap[(current - 1) / 2].to = heap[current].to;

		heap[current].value = tempValue;
		heap[current].to = tempTo;

		current = (current - 1) / 2;
	}

	heapSize = heapSize + 1;

	return 1;
}

int heapPop()//heap은 별도의 자료구조라 포인터로 연결될필요가없다. to value만 필요!
{
	if (heapSize <= 0)
	{
		return -1;
	}

	//*value = heap[0].value;
	heapSize = heapSize - 1;

	heap[0].value = heap[heapSize].value;
	heap[0].to = heap[heapSize].to;

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

		int tempValue = heap[current].value;
		int tempTo = heap[current].to;
		heap[current].value = heap[child].value;
		heap[current].to = heap[child].to;
		heap[child].value = tempValue;
		heap[child].to = tempTo;

		current = child;
	}

	return 1;
}


void addNode(int from, int to, int value)
{
	Node * p = new Node();
	p->to = to;
	p->value = value;
	p->prev = ids[from];
	ids[from] = p;
}

void prim()
{
	//초기화
	visit[1] = true;
	int res = 0;
	
	for(Node * cur = ids[1] ; cur!=0 ; cur=cur->prev) heapPush(cur);

	while (heapSize > 0)
	{
		Node top = heap[0];
		heapPop();

		if (visit[top.to] == false)
		{
			visit[top.to] = true;
			res += top.value; //비용
			for (Node * cur = ids[top.to]; cur != 0; cur = cur->prev)
				if (visit[cur->to] == false) heapPush(cur);
		}
	}
	cout << res << endl;
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0);
	
	cin >> N >> M;

	int a, b, c;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		//양방향이다.
		addNode(a, b , c);
		addNode(b , a , c);
		//index 0부터
	}

	//스패닝 트리 !!노드 하나씩 추가해가면서 만들면된다.

	heapInit();

	prim();

	return 0;
}
