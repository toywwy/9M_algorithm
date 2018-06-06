/*
문제 : 찾기
문제 번호: 1786
풀이법 : KMP
날짜 : 18.4.10 
기타 : 정말 푸는데 어렵다. 간단하지만 어려움.

*/


#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

vector<int> get_fail(string p)
{
	vector<int> fail(p.size());

	for (int i = 1, j = 0; i<p.size(); ++i) {

		if (p[i] != p[j]) j = fail[j - 1];
		//틀린지 비교하는것과 그래서 틀리면 fail 함수 호출해서 j에 넣어준다.
		//그리고 그 자리에서 다시 i와 비교를 할수 있게된다.
		//j는 거기까지 맞은 갯수이니깐. 지금 현재의 i랑 비교를 하면된다.
		if (p[i] == p[j]) fail[i] = ++j;
		//맞는지를 비교하는 것을 따로둔다.
	}

	return fail;
}

int main(void)
{
	string str, p;
	getline(cin, str);
	getline(cin, p);

	vector<int> ans;
	vector<int> fail;

	fail = get_fail(p);

	int strlen = str.size();
	int plen = p.size();

	for (int i = 0, j = 0; i<strlen; ++i) {
		if (str[i] != p[j]) j = fail[j - 1];

		if (str[i] == p[j])
		{
			if (j == plen - 1)
			{
				j = fail[j];
				ans.push_back(i - plen + 2);
			}
			else
				j++;
		}
	}

	int length = ans.size();

	cout << length << endl;
	for (int i = 0; i<length; ++i) {
		cout << ans[i] << "\n";
	}
	return 0;
}