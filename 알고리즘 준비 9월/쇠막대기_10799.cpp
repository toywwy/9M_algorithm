/*
���� : �踷���
���� ��ȣ: 10799
Ǯ�̹� : stack, ����
��¥ : 18.10.04
��Ÿ :
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
				
				chk = true; //������ ���� �������� �ִ��ſ����� �����ϱ����ؼ�
				
				if (save == '(') //������ �ٷ������ϱ�. �߷����� ��������ŭ +=1
					res += (cnt - 1);
				else  //������ �ƴ� ������ ������.
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
