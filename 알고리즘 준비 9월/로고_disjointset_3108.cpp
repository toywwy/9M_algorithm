#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
struct rec {
	int x1, y1, x2, y2;
	rec() {}
	rec(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}
};

int n, par[1001], lv[1001], c[1001];

rec r[1001];

bool connected(rec a, rec b) {
	if (a.x1<b.x1 && b.x2<a.x2 && a.y1<b.y1 && b.y2<a.y2) {
		return false;
	}
	if (a.x1>b.x1 && b.x2>a.x2 && a.y1>b.y1 && b.y2>a.y2) {
		return false;
	}
	if (b.x1>a.x2 || b.x2<a.x1 || b.y1>a.y2 || b.y2<a.y1) {
		return false;
	}
	return true;
}

int find(int u) {
	return u == par[u] ? u : find(par[u]);
}

void merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return;
	if (lv[u]>lv[v]) par[v] = u;
	else {
		par[u] = v;
		if (lv[u] == lv[v]) lv[v]++;
	}
}


int main() {
	scanf("%d", &n);
	r[0] = rec(0, 0, 0, 0);
	for (int i = 1, x1, y1, x2, y2; i <= n; ++i) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		r[i] = rec(x1, y1, x2, y2);
	}
	for (int i = 0; i <= n; ++i) par[i] = i;

	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			if (i != j&&connected(r[i], r[j]))
				merge(i, j);
		}
	}
	int ret = 0;
	for (int i = 0; i <= n; ++i) if (!c[find(i)]) c[find(i)]++, ret++;
	printf("%d\n", ret - 1);
}