/*
문제 :
문제 번호:
풀이법 :
날짜 :
기타 :

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;


//첫째 줄에 입력으로 주어진 순열의 다음에 오는 순열을 출력한다.만약, 사전순으로 마지막에 오는 순열인 경우에는 - 1을 출력한다.
int main(void)
{
	int n;
	cin >> n;

	vector<int> v;

	for (int i = 1; i <= n; i++)
		v.push_back(i);

	for (int a : v)
		cout << a << " ";

	while (next_permutation(v.begin(), v.end()))
	{
		for (int a : v)
			cout << a << " ";
		cout << endl;
	}




	return 0;
}