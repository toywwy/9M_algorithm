#include<iostream>

using namespace std;

int m[32]; // a

int recur(int a, int b)
{

	if (a == 1 || b == 1)
		return 2*2;//2^1 * 2^1 인거다

	
	int f = 0, r = 0;
	if (m[a] == 0)
	{
		f = recur(a / 2, a / 2);
		m[a] = f;
	}
	else
		f = m[a];
	//어떤걸 캐싱 해야되는지도 잘 생각해야함.

	if (m[b] == 0)
	{
		int r = recur(b / 2, b / 2);
		m[a] = r;
	}
	else
		r = m[b];

	return f*r;

}

int main(void)
{
	int n = 16;
	cout<<recur(n / 2, n / 2)<<endl;

	return 0;
}