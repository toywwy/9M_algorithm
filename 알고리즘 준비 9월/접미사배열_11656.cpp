/*
���� : ���̻� �迭
���� ��ȣ: 11656
Ǯ�̹� : Suffix Array ���̻� �迭
��¥ : 18.10.03
��Ÿ :
�־��ǹ������ Ǭ ���̻�迭 SA
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
