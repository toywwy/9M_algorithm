/*
���� : ȸ�ǽǹ���
���� ��ȣ: 1931
Ǯ�̹� : �׸���
��¥ : 18.07.18
��Ÿ :

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstdio>

using namespace std;

typedef pair<long long, long long> P;


vector<P> v;

//�ڱ��ڽ��ΰ� �߻����ؼ� �ؾ��Ѵ�.
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
			//���� ���� end�� ã�ƾ� �Ѵ�.
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

	//���� �ð��� ������ �ð��� 2^31-1���� �۰ų� ���� �ڿ��� �Ǵ� 0�̴�.
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
