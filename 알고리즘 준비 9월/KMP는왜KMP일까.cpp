/*
���� : KMP�� ��KMP�ϱ�?
���� ��ȣ: 2902
Ǯ�̹� : ���ڿ�..
��¥ : 161008
��Ÿ :
*/


#include<iostream>
#include<string>
using namespace std;

int main(void)
{
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
		if (s[i] < '[' && s[i]!='-')
			printf("%c", s[i]);

	printf("\n");

	return 0;
}