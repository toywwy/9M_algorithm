
/*
문제 : 트리순회
문제 번호: 1991
풀이법 : 배열로 자식 두개를 갖고있는 방식
날짜 : 160925
기타 : 좌우가 있는걸 깜밖하고 벡터로 풀었다가 pushback으로했다가 ..
. 도 받아서 처리를 해줘야 했다.

그리고 문자열 %c로받을때는 \n 까지 포함하기때문에 앞에 ' %c' 이런식으로 해서 입력을 받아야 한다는점!!
아니면 getChar로도 해결이 된다는거 같았음
*/

#include<iostream>

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