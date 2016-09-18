
/*
문제 : 여행가자
문제 번호: 1976
날짜 : 160918
기타 : union파인드, 크루스칼을 이용해서 스패닝트리 구하고나서 각각의 루트를 비교함
*/

#include<iostream>
#include<algorithm>

#define N 200
using namespace std;


class Edge
{
public:
	int u, v;
	Edge() : Edge(-1, -1) {}// default 생성자
	Edge(int u, int v) :u(u), v(v){}// defalut 입력
};


int disjoint[N+2];

int mFind(int a)
{
	if (disjoint[a] < 0)
		return a;
	else
		return disjoint[a] = mFind(disjoint[a]);
}

bool mUnion(int a, int b)
{
	int _a = mFind(a);
	int _b = mFind(b);

	if (_a == _b)
		return false;

	disjoint[_b] = _a;
	return true;
}


int main(void)
{
	int n, m;//도시수 200, 여행 계획에 속한 도시들 M개

	cin >> n >> m;

	Edge *edges = new Edge[n*n+2];

	int input=0;
	int edgeCnt = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &input);

			if (input != 0)
			{
				Edge *e = new Edge(i, j);
				edges[edgeCnt] = *e;
				edgeCnt++;
			}
		}
	}

	fill(disjoint, disjoint+ N+2 , -1);

	int value = 0;
	int cnt = 1;

	//스패닝 트리를 못만들수있음. 그래서 <edgeCnt까지만!
	for (int i = 0;i<edgeCnt; i++)
	{
		Edge e = edges[i];

		if (mUnion(e.u, e.v))
		{
			if ((++cnt) >= n)
				break;
		}
	}

	//이미 스패닝 트리는 만들어진 상태. 스패닝 트리라고 하긴 그렇고 집합들이 만들어 졌겠지.
	int q;
	cin >> q;

	int root = mFind(q);
	bool res = true;

	for (int i = 0; i < m-1; i++)
	{
		scanf("%d", &q);
		//부모가 같나 확인한다.
		if (root != mFind(q)) {
			res = false;
			break;
		}
	}

	if (res)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}