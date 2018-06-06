#include<iostream>
#include<string>
using namespace std;

int fail[10];//pi라는 용어가 좀더 맞는 듯하다.

int main(void)
{

	string str;
	getline(cin, str);

	int strLen = str.length();

	int i = 1,j = 0;//0 할필요 없음
	int match = 1;
	while(j < strLen && i<strLen)
	{
		if (str[i] == str[j++]) fail[i++] = match++;
		else {
			//i를 어디로 잡을지 분석해봐야한다.
			if (match > 1)
			{
				int temp = fail[match - 2];
				match = 1;
				match += temp;//해당하는 부분맞은 맞고 시작하는게 KMP의 정신이다.
				j = temp;
			}
			else
			{
				i++;
				match = 1;//다시 초기화.
				j = 0;//는 다시 처음부터  j도아닐수있음.
			}
			
		}
	}
	



	//결과값 확인
	for (int i = 0; i < strLen; i++)
		cout << fail[i] << endl;




	return 0;
}