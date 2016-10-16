/*
문제 : 집합의표현
문제 번호: 1717
풀이법 : Disjoint-set, union-find(합치고 찾고하는거)
날짜 : 160916
기타 : union-find로 해결
disjoint-set
한마디로 배열을 인덱스 처럼사용을한다. 결국에 재귀를 타서 ... 루트에 다다르도록 만드는 것이다.
그리고 union은 그 두 집합을 이어주는 것이다.

참조 : http://kks227.blog.me/220791837179?Redirect=Log&from=postView

*/

#include<iostream>
#include<vector>

using namespace std;

int dis[1000002];

int find(int x)
{
	if (dis[x] < 0) return x;
	else return dis[x] = find(dis[x]); //새 부모 x를 등록해준다.
}

bool merge(int a, int b)
{
	a = find(a), b = find(b);
	if (a == b) return false;
	dis[b] = a; return true;
}

int main(void)
{
	int n, m, a, b, com;;
	cin >> n >> m;

	fill(dis, dis + n + 1, -1);
	while (m--)
	{
		scanf("%d %d %d", &com, &a, &b);

		if (com)// CHECK
		{
			if (find(a) == find(b)) printf("YES\n");
			else printf("NO\n");
		}
		else merge(a, b);// Union
	}

	return 0;
}