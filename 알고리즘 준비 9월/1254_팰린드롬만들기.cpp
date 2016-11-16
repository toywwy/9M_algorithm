/*
문제 : 팰린드롬만들기
문제 번호: 1254
풀이법 : 
날짜 : 161116
기타 : 홀수 짝수 일 경우를 나눠서 풀었다.
상당히 더럽다.

인덱스를 잘다뤄야 한다. 어느부분까지 체크를 할지에 대해서 -1을 해주는바람에 답이 틀리게 나왔었따.
ab를 체크를 못해줘서

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main(void)
{

	string str;
	cin >> str;

	int result = 0;
	int res = 0;

	if (str.size() % 2 == 0)//짝수
	{
		int mid = str.size() / 2;
		//이게 미드고..
		while (mid < str.size())
		{
			int left = mid - 1;
			int right = mid;

			bool c = true;

			while (right < str.size())//마지막까지 체크할수있음
			{
				if (str[left--] != str[right++])
				{
					c = false;
					break;
				}
			}

			if (c) break;
			//홀수체크

			left = mid - 1;
			right = mid + 1;//그냥일단 .. 처음에만 안하면되
			c = true;
			while (right < str.size())
			{
				if (str[left--] != str[right++])
				{
					c = false;
					break;
				}
			}

			if (c)
			{
				res += 1;
				break;
			}

			mid++;
			res += 2;
		}

	}
	else//홀수
	{
		int mid = str.size()/2;
		//미친어렵네

		while (mid < str.size())//이렇게 해야 인덱스오류는 안나고
		{
				//짝수체크
				int right = mid;
				int left = mid - 1;
				bool c = true;
				if (right!=str.size()/2)//처음에 건너뛸려고
				{
				
					while (right < str.size())//마지막까지 체크할수있음
					{
						if (str[left--] != str[right++])
						{
							c = false;
							break;
						}
					}


					if (c)
					{
						res -= 1;
						break;
					}
				}
				//홀수체크

				left = mid - 1;
				right = mid + 1;//그냥일단 .. 처음에만 안하면되
				c = true;
				while (right < str.size())
				{
					if (str[left--] != str[right++])
					{
						c = false;
						break;
					}
				}

				if (c)
					break;
				
			mid++;
			res += 2;
		}


	}
	cout << (str.size() + res) << endl;


	return 0;
}
