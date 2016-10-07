/*
문제 : KMP는 왜KMP일까?
문제 번호: 2902
풀이법 : 문자열..
날짜 : 161008
기타 :
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