/*
문제 : 문자열 폭발
문제 번호: 9935
풀이법 : 
날짜 : 18.09.13
기타 :

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<stack>

using namespace std;



vector<char> s;

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	string str1,str2;
	cin >> str1>>str2;
	//str2 폭발문자
	int len = str2.length();//2번쨰 폭발문자 길이가 중요.. 그 전부터 체크를하면되니깐..

	
	int cur = 0;
	for (int i = 0; i < str1.length(); i++,cur++)
	{
		s.push_back(str1[i]);

		if (cur - (len-1) < 0) continue; //조사를 못한다.
		else
		{
			if (s[cur] != str2[len - 1]) continue;

			bool chk = true;
			for (int j = cur - (len - 1), idx = 0; idx < len - 1; j++, idx++)
			{
				if (s[j] != str2[idx]) {
					chk = false;
					break;
				}
			}

			if (chk)
			{
				for (int j = 0; j < len; j++)
				{
					s.pop_back();
				}
				cur = cur - (len - 1);// cur 이증가하는거 막아줘야함.
				cur -= 1;
			}
		}
	}


	if (s.size() < 1) cout << "FRULA";
	else for (int i = 0; i < s.size(); i++) cout << s[i];

	cout << endl;

	return 0;
}
