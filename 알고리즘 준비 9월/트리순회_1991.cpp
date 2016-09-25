#include<iostream>
#include<vector>

using namespace std;


int v[26][2]; //알파벳 26개 , 좌우 2개

char dot = ('.' - 'A');

void mOrder(int a, int type)
{

	if (type == 0)//전위
		printf("%c", ('A' + a));

	// dot 인건 탐색 안해도되고 , 0인것도 탐색안해도 된다.
	if(v[a][0]!=0 && v[a][0] !=dot)
		mOrder(v[a][0], type);//좌 노드

	if (type == 1)//중위
		printf("%c", ('A' + a));

	if (v[a][0] != 0 &&v[a][1] != dot)
		mOrder(v[a][1], type);//우 노드


	if (type == 2)//후위
		printf("%c", ('A' + a));
}

int main(void)
{
	int n;
	cin >> n;
	char a, b, c;

	for (int i = 0; i < n; i++)
	{
		scanf(" %c  %c  %c", &a, &b, &c);
		v[a - 'A'][0] =(b - 'A');
		v[a - 'A'][1] =(c - 'A');
	}

	mOrder(0, 0);
	cout << endl;

	mOrder(0, 1);
	cout << endl;

	mOrder(0, 2);
	cout << endl;

	return 0;
}