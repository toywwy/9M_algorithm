/*
문제 : 단어공부
문제 번호: 1157
풀이법 : Counting Sort
날짜 : 18.09.13
기타 :

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;

int asci[130];

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++) asci[str[i]] += 1;

	int max = 0,maxIdx = 0;
	
	bool isSame = false;

	for (int i = 'a', j = 'A'; i <= 'z'; i++, j++) asci[j] += asci[i];

	for (int i = 'A'; i <= 'Z'; i++)
	{
		if (asci[i] == max)
		{
			isSame = true;
		}
		else if (asci[i]>max)
		{
			max = asci[i];
			maxIdx = i;
			isSame = false;
		}
	}

	if (isSame)
		cout << "?" << endl;
	else
		cout << (char)maxIdx << endl;

	return 0;
}
