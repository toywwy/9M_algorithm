
#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;


int uf[1000];
//disjoint set (서로소 집합)라는 자료구조를 이용할 것이다.


//union-find에서 find 연산이다.
int find(int a)
{
	if (uf[a] < 0) return a;//-1로 초기화 해두는이유
	return uf[a] = find(uf[a]);//자식의 자식이렇게 꼬리를물다가 마지막 루트는 -1 이되는 구조이다.
}

//union-find에서 union 연산을 수행한다.
bool merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b) return false; //루트가 같다면 같은거다.
	uf[b] = a;//같지 않다면 합치자. b가 루트가 되는 구조이다.
	//uf라는 것에서 ...그냥하는건가...대단함.. 천재가 아니고서야 이건불가능
	

	return true;
}

struct Edge {
	int u, v, w;
	Edge() :Edge(-1, -1, 0) {}
	Edge(int u1, int v1, int w1) : u(u1), v(v1), w(w1) {}
	bool operator<(const Edge & O)const { return w < O.w; }
};

int main(void)
{
	int n, q;
	scanf("%d %d", &n, &q);

	Edge *e = (Edge * ) malloc(sizeof(Edge)*q);//q가 100000이다. 사이즈. 그냥 선언하면 스택 터짐.

	for (int i = 0; i < q; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		e[i] = Edge(a - 1, b - 1, c);
	}

	sort(e, e + q); // operator 때문에 w에 따라서 정렬을 하게된다.

	int result = 0, cnt = 0;
	fill(uf, uf + n, -1); //처음에 -1로 해놓고 시작을함! 지금은 모두 각각 di 머시기 집합임.

	for (int i = 0;; i++)
	{
		if (merge(e[i].u, e[i].v)) {//이렇게 해서 하나로 합치는거구나 ..일단 w별로 중복되어있는거고 ..진짜좋은문제다.
			result += e[i].w;// union이 성공했다면 result를 증가 시켜준다.
			if (++cnt == n - 1) break;
		}
	}

	printf("%d\n", result);
}