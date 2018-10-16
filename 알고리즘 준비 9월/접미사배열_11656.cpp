/*
문제 : 접미사 배열
문제 번호: 11656
풀이법 : Suffix Array 접미사 배열
날짜 : 18.10.03
기타 :
최악의방법으로 푼 접미사배열 SA
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	string s;
	cin >> s;
	vector<string> v;

	for (int i = 0; i < s.length(); i++) {
		string substr = s.substr(i, s.length() - i);
		v.push_back(substr);
	}

	sort(v.begin(), v.end());
	for (string str : v) cout << str << endl;

	return 0;
}
