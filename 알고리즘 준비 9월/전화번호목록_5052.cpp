/*
문제 : 전화번호 목록
문제 번호: 5052
풀이법 : 트라이
날짜 : 170518
기타 : 

*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Node
{
public:
	int id;
	bool isEnd;
	int childCount;
	
	Node *next; //이 노드가 가리키는 것들의 집합
	Node *child[10]; //이 노드의 자식들..
	
	Node *rearNode;
	Node() { 
		id = 0;
		next = NULL; 
		isEnd = false;
		childCount = 0;
	};

} nodes[10001];//시작 노드가 만개일수가있따....시작노드 어떻게할것인가...?

bool visit[10001];//사실 의미가없다.. 트라이를 먼저만들어본다.

char arr[10001];//전화번호의 수 n이 주어진다. (1 ≤ n ≤ 10000) 




inline int strLen(char *str)
{
	int k = 0;
	while (str[k] != NULL) k++;

	return k;
}

int main(void)
{

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		int N;
		cin >> N;
	
		for (int i = 0; i < N; i++)
		{
			scanf("%s", &arr);

			int idx = 1;//분명히 시작과 끝은 구분이되야함.
			int n = arr[0] - '0';

			Node *node = &nodes[n];//시작점..
			node->id = n;
			//시작 visit은 의미가 있을지도 모른다.

			while (arr[idx] != NULL)
			{
				n = arr[idx] - '0';
				Node nNode;
				nNode.id = n;
				//여기서 있나 없나 체크해봐야한다.
				
				if (node->childCount == 0)
				{
					node->next = &nNode;
					node->rearNode = &nNode;
					node->childCount += 1;
				}
				else
				{
					int cnt = 0;
					Node *chk = node;
					bool chkNode = false;
					while (cnt<node->childCount)//end는 필요없다.
					{
						if (chk->id == n)
						{
							chkNode = true;
							break;
						}
						chk = chk->next;
						
						cnt++;
					}

					if (chkNode == false)
					{
						node->rearNode = &nNode;
						node->childCount += 1;
					}
				}

				idx++;
				if (arr[idx] == NULL)
				{

				}
			}
			



		}




	}
	return 0;
}
