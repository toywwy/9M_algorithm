
/*
���� : Ʈ����ȸ
���� ��ȣ: 1991
Ǯ�̹� : �迭�� �ڽ� �ΰ��� �����ִ� ���
��¥ : 160925
��Ÿ : �¿찡 �ִ°� �����ϰ� ���ͷ� Ǯ���ٰ� pushback�����ߴٰ� ..
. �� �޾Ƽ� ó���� ����� �ߴ�.

�׸��� ���ڿ� %c�ι������� \n ���� �����ϱ⶧���� �տ� ' %c' �̷������� �ؼ� �Է��� �޾ƾ� �Ѵٴ���!!
�ƴϸ� getChar�ε� �ذ��� �ȴٴ°� ������
*/

#include<iostream>

using namespace std;


int v[26][2]; //���ĺ� 26�� , �¿� 2��

char dot = ('.' - 'A');

void mOrder(int a, int type)
{

	if (type == 0)//����
		printf("%c", ('A' + a));

	// dot �ΰ� Ž�� ���ص��ǰ� , 0�ΰ͵� Ž�����ص� �ȴ�.
	if(v[a][0]!=0 && v[a][0] !=dot)
		mOrder(v[a][0], type);//�� ���

	if (type == 1)//����
		printf("%c", ('A' + a));

	if (v[a][0] != 0 &&v[a][1] != dot)
		mOrder(v[a][1], type);//�� ���


	if (type == 2)//����
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