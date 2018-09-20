/*
문제 : 전화번호 목록
문제 번호: 5052
풀이법 : Hash MAP
날짜 : 18.09.20
기타 :

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
				if (m.find(ret) != m.end())//포함되어있다.
				{
					res = true;//있다.
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
