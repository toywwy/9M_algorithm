#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int target = 0;
vector<int> v;

bool bSearch(int a, int b)
{

	if (a >= b) return 0;

	//처음에 0 부터 20 들어온다.
	int c = (a+b)/2;

	if (v[c] == target)
		return 1;

	if (target < v[c])
	{
		return bSearch(a, c);
	}
	else//target > c
	{
		return bSearch(c + 1, b);
	}

}


int main(void)
{
	for (int i = 0; i < 19; i++)
	{
		v.push_back(rand() % 20);
	}
	v.push_back(20);
	
	target = 11;
	
	sort(v.begin(), v.end());

	if (bSearch(0, 20))
		cout << "FIND!" << endl;
	else
		cout << "ELSE!" << endl;

	return 0;
}
