/*
문제 : KMP는 왜KMP일까?
문제 번호: 2902
풀이법 : 문자열, KMP
날짜 : 161008
기타 : 약간의 KMP를 이용하는 구조였음
*/


#include<iostream>
#include<string>
using namespace std;

int main(void)
{
	int n;
	cin >> n;

	int len;
	scanf("%d", &len);

	int resCnt = 0;

	string s;
	cin >> s;

	int idx = 1;

	bool res = true;
	int trueCnt = 0;
	while (idx + 2 < s.size())
	{
		if (s[idx - 1] == 'I')
		{
			if (s[idx] == 'O')
			{
				if (s[idx + 1] != 'I')
					res = false;
			}
			else
				res = false;
		}
		else res = false;

		if (res)
		{
			idx += 2;
			trueCnt++;

			if (trueCnt == n)//정답처리
			{
				resCnt += 1;
				trueCnt = n-1;
			}
		}
		else
		{
			idx += 1;
			trueCnt = 0;
			res = true;
		}
	}

	cout << resCnt << endl;
	return 0;
}