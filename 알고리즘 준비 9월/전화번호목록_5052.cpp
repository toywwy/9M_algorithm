/*
���� : ��ȭ��ȣ ���
���� ��ȣ: 5052
Ǯ�̹� : Ʈ����
��¥ : 170518
��Ÿ : 

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
	
	Node *next; //�� ��尡 ����Ű�� �͵��� ����
	Node *child[10]; //�� ����� �ڽĵ�..
	
	Node *rearNode;
	Node() { 
		id = 0;
		next = NULL; 
		isEnd = false;
		childCount = 0;
	};

} nodes[10001];//���� ��尡 �����ϼ����ֵ�....���۳�� ����Ұ��ΰ�...?

bool visit[10001];//��� �ǹ̰�����.. Ʈ���̸� ����������.

char arr[10001];//��ȭ��ȣ�� �� n�� �־�����. (1 �� n �� 10000) 




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

			int idx = 1;//�и��� ���۰� ���� �����̵Ǿ���.
			int n = arr[0] - '0';

			Node *node = &nodes[n];//������..
			node->id = n;
			//���� visit�� �ǹ̰� �������� �𸥴�.

			while (arr[idx] != NULL)
			{
				n = arr[idx] - '0';
				Node nNode;
				nNode.id = n;
				//���⼭ �ֳ� ���� üũ�غ����Ѵ�.
				
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
					while (cnt<node->childCount)//end�� �ʿ����.
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
