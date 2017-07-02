/*
문제 : 수들의합
문제 번호: 1789
풀이법 : 간단히..
날짜 : 20170702
기타 :

*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void)
{

	long long S = 0, M=0;
	cin >> S; //합이 S가 되는 최소의 합의 갯수를 구하는 것이다.

	int i = 1;
	for (; M + (i + 1) < S; i++) M += i;

	if (M + i == S) cout << i << endl;
	else
	{ 
		long long m = S - M;
		
		if (m > i) cout << i << endl;
		else
		{//단계를 내려가야한다.
			int h = i - 1;
			
			for (int k = h; k >= 1; k--)
			{
				M -= k;
				
				m = S - M;
				if (m > k)
				{
					cout << k << endl;
					break;
				}
			}
		}

	}



	return 0;
}
