
/*
���� : ��Ʈ��ũ����
���� ��ȣ: 1922
Ǯ�̹� : ���ͽ�Ʈ��
��¥ : 160916
��Ÿ : ũ�罺Į�� �����ϱ� ���ؼ��� �������� �ؾ��Ѵ�. ���տ� ���ؼ� union find ��°� �̿��ؼ�
������ �ذ��Ͽ���. 

ũ�罺Į�� �����ϴ¹��� �� �����ٰ��Ѵ�.
*/


#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;


int uf[1000];
//disjoint set (���μ� ����)��� �ڷᱸ���� �̿��� ���̴�.


//union-find���� find �����̴�.
int find(int a)
{
	if (uf[a] < 0) return a;//-1�� �ʱ�ȭ �صδ�����
	return uf[a] = find(uf[a]);//�ڽ��� �ڽ��̷��� ���������ٰ� ������ ��Ʈ�� -1 �̵Ǵ� �����̴�.
}

//union-find���� union ������ �����Ѵ�.
bool merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b) return false; //��Ʈ�� ���ٸ� �����Ŵ�.
	uf[b] = a;//���� �ʴٸ� ��ġ��. b�� ��Ʈ�� �Ǵ� �����̴�.
	//uf��� �Ϳ��� ...�׳��ϴ°ǰ�...�����.. õ�簡 �ƴϰ��� �̰ǺҰ���
	

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

	Edge *e = (Edge * ) malloc(sizeof(Edge)*q +1);//q�� 100000�̴�. ������. �׳� �����ϸ� ���� ����.

	for (int i = 0; i < q; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		e[i] = Edge(a, b, c);
	}

	sort(e, e + q); // operator ������ w�� ���� ������ �ϰԵȴ�.

	int result = 0, cnt = 0;
	fill(uf, uf + n, -1); //ó���� -1�� �س��� ��������! ������ ��� ���� di �ӽñ� ������.

	for (int i = 0;; i++)
	{
		if (merge(e[i].u, e[i].v)) {//�̷��� �ؼ� �ϳ��� ��ġ�°ű��� ..�ϴ� w���� �ߺ��Ǿ��ִ°Ű� ..��¥����������.
			result += e[i].w;// union�� �����ߴٸ� result�� ���� �����ش�.
			if (++cnt == n - 1) break;
		}
	}

	printf("%d\n", result);
}