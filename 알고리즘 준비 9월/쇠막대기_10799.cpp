/*
문제 : 쇠막대기
문제 번호: 10799
풀이법 : stack, 스택
날짜 : 18.10.04
기타 :
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;


vector<char> v;
int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	char c,save;
	int cnt = 0,res = 0;
	bool chk = false;

	while (cin >> c)
	{
		v.push_back(c);
		
		if (c == '(') cnt++;
		else if (c == ')')
		{
			if (cnt > 1) { 
				
				chk = true; //나무가 없이 레이저만 있던거였는지 구분하기위해서
				
				if (save == '(') //레이저 바로전꺼니깐. 잘려나간 나무수만큼 +=1
					res += (cnt - 1);
				else  //레이저 아님 나무의 마지막.
					res += 1;
			}
			else
				if (chk == true) res++;

			v.pop_back();
			v.pop_back();
			cnt -= 1;
		}

		if (v.size() == 0) chk = false;
		save = c;

	}
	cout << res << endl;

	return 0;
}
