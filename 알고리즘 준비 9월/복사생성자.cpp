#include<iostream>

using namespace std;


int cnt = 0;
class Node {
public :
	int to;
	Node * prev;

	~Node()
	{
		cout << "¼Ò¸êÀÚ : "<<cnt++<< endl;
	}
};

Node *tail;
int main(void)
{

	for (int i = 0; i < 10; i++)
	{
		Node * newNode = new Node();
		newNode->to = i + 1;
		newNode->prev = tail;
		tail = newNode;
	}


	Node * cur = tail;
	while (cur != 0)
	{
		cout << cur->to << " ";
		cur = cur->prev;
	}
	cout << endl;

	cur = tail;
	while (cur != 0)
	{
		Node *del = cur;
		Node *next = cur->prev;
		delete cur;
		cur = next;
	}


	return 0;
}