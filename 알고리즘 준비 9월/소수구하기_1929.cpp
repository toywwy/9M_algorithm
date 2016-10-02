/*
문제 : 소수구하기
문제 번호: 1929
풀이법 : 에라토네스체
날짜 : 20161002
기타 : 

*/



#include<iostream>
#define SIZE 1000000
using namespace std;
//(1≤M≤N≤1, 000, 000)

bool check[SIZE];

int main(void)
{
	
	int from,to;
	cin >> from >> to;

	check[0] = 1;
	check[1] = 1;
	check[2] = false; //2는 소수다

	
	for (int i = 2; i <= to; i++) //to까지 소숭인지 판별하면된다.
	{
		if (check[i]) continue; //소수가 아니면 안해

		for (int j = 2; i*j <= to; j++)
			check[i*j] = 1;
	}

	for (int i = from; i <= to; i++)
		if (!check[i]) printf("%d ", i);

	cout << endl;

	return 0;
}