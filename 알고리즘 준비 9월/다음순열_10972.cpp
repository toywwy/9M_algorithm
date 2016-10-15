/*
문제 :		다음순열
문제 번호:	10972
풀이법 :		cmath next_permutation
날짜 :		161016
기타 :		
입력받은것의 다음 순열을 출력한다.
마지막이라면 
-1 출력

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

	int inp;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &inp);
		v.push_back(inp);
	}

	if (next_permutation(v.begin(), v.end()))
	{
		for (int a : v)
			cout << a << ' ';
	}
	else
		cout << -1;

	cout << endl;

	return 0;
}
