/*
	2차원 해시리스트
*/

#include<iostream>
#include<cstdio>
#include<cmath>

#define N 100
#define MAX_TABLE 40
using namespace std;

class Node {
public:
	char data[10];
	Node * prev;
}nodes[1000];

int idx, SIZE;

unsigned long myhash(const char *str)
{
	unsigned long hash = 5381;
	int c;

	while (c = *str++)
		hash = (((hash << 5) + hash) + c) % MAX_TABLE;

	return hash % MAX_TABLE;
}


Node *hTable[MAX_TABLE];



Node* newNode()//무한히 확장시켜나간다.
{
	return &nodes[idx++];
}


int main(void)
{
	char str[10];
	int LEN = 5;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < LEN-1; j++)
		{
			str[j] = (char)(rand() % 26) + 'a';
		}
		str[LEN-1] = '\0';//

		
		int key = (int)myhash(str);
		Node *p = newNode();
		strcpy(p->data, str);
		p->prev = hTable[key];
		hTable[key] = p;

	}


	for (int i = 0; i < MAX_TABLE; i++)
	{
		Node * cur = hTable[i];
		cout << i << " : ";
		while (cur != 0)
		{
			cout << cur->data << " ";
			cur = cur->prev;
		}
		cout << endl;

	}

	return 0;
}