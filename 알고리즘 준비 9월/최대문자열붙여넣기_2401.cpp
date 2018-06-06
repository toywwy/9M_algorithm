/*
문제 : 최대문자열붙여넣기
문제 번호: 2401
풀이법 : KMP
날짜 : 18.04.12
기타 :

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main(void)
{
	
	string ori;
	vector<string> str;
	int n;
	cin >> ori>>n;

	string input;
	for (int i = 0; i < n; i++) {
		cin >> input;
		str.push_back(input);
	}

	//kmp를 작성해야하는 문제인가??





	return 0;
}
