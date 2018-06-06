/*
문제 : 생태학
문제 번호: 4358
풀이법 : Trie
날짜 : 18.06.02
기타 :

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
//30글자를 넘지 않으며, 입력에는 최대 10,000개의 

class Node {

public:
	//입력에는 영문 대소문자와 공백문자, 그리고 숫자, 특수문자만 포함될 수 있다.
	Node *childs[128];//아스키코드 128개 까지 다 할수있도록 ..
	bool leaf;
	int cnt;
	string str;

	Node()
	{
		for (int i = 0; i < 128; i++) this->childs[i] = nullptr;
		this->leaf = false;
		this->cnt = 0;
		this->str = "\0";
	}

};


double cnt = 0;

void recur(Node *cur)
{
	for (int i = 0; i < 128; i++)
	{
		if (cur->childs[i] != nullptr)
		{
			if (cur->childs[i]->leaf == true)
			{
			//	printf("%s %.4f\n", cur->childs[i]->str, ((double)cur->childs[i]->cnt / (double)cnt) * 100);
				cout << cur->childs[i]->str << " " << ((double)cur->childs[i]->cnt / (double)cnt)*100 << endl;
			}

			recur(cur->childs[i]);
		}
	}



}


int main(void)
{

	cout.setf(ios::fixed);
	cout.precision(4);

	Node *root;
	root = new Node();
	while (true)
	{
		string str;

		getline(cin, str);

		//Leaf가 겹쳤을때 count 한다.
		Node * cur = root;
		for (int i = 0; str[i] != '\0'; i++)
		{

			if (cur->childs[str[i]] == nullptr)
				cur->childs[str[i]] = new Node();

			cur = cur->childs[str[i]];
		}
		
		if (cur->leaf == true)
			cur->cnt += 1;
		else
		{
			cur->leaf = true;
			cur->cnt += 1; 
			cur->str = str;

		}

		if (str[0] == '\0') break;
		else cnt+=1;
	}

	//나중에 완전탐색 하면서 leaf 에서 카운트를 호출하면된다.
	//cnt /= (double)100;
	recur(root);

	return 0;
}
