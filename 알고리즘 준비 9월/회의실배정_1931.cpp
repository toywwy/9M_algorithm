/*
문제 : 회의실배정
문제 번호: 1931
풀이법 : 그리디
날짜 : 18.07.18
기타 :

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstdio>

using namespace std;

typedef pair<long long, long long> P;


vector<P> v;

//자기자신인거 잘생각해서 해야한다.
int mMax;
long long mMin = (1 << 31) - 1;

void recur(int idx,int end,int cnt)
{
	mMax = max(cnt, mMax);
	
	long long m = mMin;
	bool chk = false;
	int mIdx = 0;
	for (int i = idx; i < v.size(); i++) {
		if (end <= v[i].first)
		{
			//가장 작은 end를 찾아야 한다.
			if (m > v[i].second)
			{
				m = v[i].second;
				mIdx = i;
				chk = true;
			}
		}
	}
	if (chk)
	{
		recur(mIdx + 1, m, cnt + 1);
	}
}


int main(void)
{
	int N;
	cin >> N;

	long long a, b;

	//시작 시간과 끝나는 시간은 2^31-1보다 작거나 같은 자연수 또는 0이다.
	for (int i = 0; i < N; i++)
	{
		scanf("%lld %lld", &a, &b);
		v.push_back(P(a, b));
	}

	sort(v.begin(),v.end());

	int s, e, m;
	for (int i = 0 ; i < v.size();i++)
		recur(i,v[i].second,1);

	printf("%d\n",mMax);


	return 0;
}
