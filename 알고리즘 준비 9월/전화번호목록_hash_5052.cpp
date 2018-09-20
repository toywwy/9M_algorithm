/*
���� : ��ȭ��ȣ ���
���� ��ȣ: 5052
Ǯ�̹� : Hash MAP
��¥ : 18.09.20
��Ÿ :

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<map>

using namespace std;




int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N,n;
	cin >> N;

	while (N--)
	{
		map<string, bool> m;//
		vector<string> v;

		cin >> n;
		bool res = false;
		for (int i = 0; i < n; i++)
		{
			string str;
			cin >> str;
			v.push_back(str);
		}
		sort(v.begin(), v.end());
		
		for (string s : v)
		{
			for (int i = 0; i < s.length(); i++)
			{
				string ret = s.substr(0, i + 1);
				if (m.find(ret) != m.end())//���ԵǾ��ִ�.
				{
					res = true;//�ִ�.
					break;
				}
			}

			if (res) break;
			else m[s] = true;
		}


		if (res) cout << "NO" << endl;
		else cout << "YES" << endl;
	}

	return 0;
}
