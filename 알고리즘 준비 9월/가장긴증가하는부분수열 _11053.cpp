/*
문제 :		가장긴증가하는부분수열
문제 번호:	11053
풀이법 :		DP
날짜 :		161016
기타 :		
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int dp[1002],n,a;
vector<int> v;

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a);
		v.push_back(a);
		dp[i]=1;
	}

	for (int i = 0; i < n-1; i++)
		for (int j = i; j < n - 1; j++)
			if (v[i] < v[j + 1])
				dp[j + 1] = max(dp[i] + 1, dp[j + 1]);

	cout<<*max_element(dp, dp + n)<<endl;

	return 0;
}

