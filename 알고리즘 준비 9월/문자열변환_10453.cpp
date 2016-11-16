/*
문제 : 문자열변환
문제 번호: 10453
풀이법 : 그냥 탐색
날짜 : 161116
기타 : 다른 부분을 채키

*/


#include<iostream>
#include<string>
using namespace std;

int main(void)
{
	int itr;
	cin >> itr;

	string src, dst;


	for (int i = 0; i < itr; i++)
	{
		int res = 0;

		cin >> src >> dst;

		if (src.size() != dst.size())
		{
			cout << -1 << endl;
			continue;
		}

		for (int j = 0; j < src.size(); j++)
		{
			if (src[j] != dst[j])
			{
				for (int k = j + 1; k < src.size(); k++)
				{
					res += 1;
					if (src[j] != src[k])
					{
						swap(src[j], src[k]);
						break;
					}

				}
			}
		}
		cout << res << endl;
	}


	return 0;
}