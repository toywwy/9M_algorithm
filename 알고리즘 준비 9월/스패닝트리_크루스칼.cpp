/*
스패닝트리 크루스칼 유니온파인드
disjoint set 서로소 집합
union find
*/


#include<iostream>
#include<algorithm>

#define N 1000
#define LINE 100000
using namespace std;


class Edge
{
public:
	int u,v,w;
	Edge() : Edge(-1,-1,0) {}// default 생성자
	Edge(int u, int v, int w) :u(u), v(v), w(w) {}//defalut 입력
	bool operator<(Edge e) { return w < e.w; }
};


int disjoint[1002];

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


//집합 관련 연산 union find 써야한다.
 
int main(void)
{

	int n,m;//컴퓨터수 1000 , 연결할 선의수 100000
	cin >> n >> m;

	Edge *edges = new Edge[m];

	int u, v, w;
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &u, &v, &w);
		Edge *e = new Edge(u, v, w);
		edges[i] = *e;
	}

	sort(edges, edges + m); //이렇게 하면 w에 대해서 정렬이 된다 일단.
	
	fill(disjoint, (disjoint + N + 2),-1);
	//모든 컴퓨터를 하나의 집합으로 만들면된다. 크루스칼
	
	//이제 부터 집합 연산 할거임


	int value = 0;
	int cnt = 1;

	for (int i = 0;; i++)//여기에서 i<m을 뺴주는게 팁인게 연산을 비교연산을 빼준다.
	{
		//처음에 나온거 집합에 넣는다..
		Edge e = edges[i];
		if (mUnion(e.u, e.v))
		{
			value += e.w;
			cnt++;

			if (cnt >= n)
				break;
		}

	}

	cout << value << endl;

	return 0;
}