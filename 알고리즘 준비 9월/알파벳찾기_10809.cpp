/*
���� : ���ĺ�ã��
���� ��ȣ: 10809
Ǯ�̹� : 
��¥ : 18.09.13
��Ÿ :

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
	for (int i = 'a'; i <= 'z'; i++)
		asci[i] = -1;

	for (int i = 0; i < str.length(); i++)
		if(asci[str[i]] ==-1) asci[str[i]] = i;

	for (int i = 'a'; i <= 'z'; i++)
		cout << asci[i] << " ";
	cout << endl;

	return 0;
}
