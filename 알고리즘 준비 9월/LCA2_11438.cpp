/*
문제 :		LCA2
문제 번호:	11438
풀이법 :		LCA 공통조상
날짜 :		161013
기타 :		LCA로 문제풀기.
*/


#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 18; // roundup log(2, 100000)
//2^k 번쨰의 부모이다 바로 자신의 부모를 가지고 있는게 아니야 ...
//LCA1 같은경우에는 그냥 바로 자신의 부모만 갖은걸로 가능할려나????
//DEPTH처리하는 법은알았고


int N, M;
int parent[100000][MAX]; // parent[i][k]: i의 2^k번째 부모
int depth[100000]; // 정점의 깊이 (루트의 깊이: 0)
vector<int> adj[100000]; // 인접 리스트

						 // dfs로 트리 제작하며 parent[i][0], depth 배열 채움
void makeTreeByDFS(int curr) {
	for (int next : adj[curr]) {
		if (depth[next] == -1) {
			parent[next][0] = curr;
			depth[next] = depth[curr] + 1;
			makeTreeByDFS(next);
		}
	}
}


int main() {
	// 트리 정보 입력
	scanf("%d", &N);
	for (int i = 0; i<N - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	// 배열 초기화
	memset(parent, -1, sizeof(parent));// -로 초기화 이렇게 하면 알아서 초기화가 되는건가??
	fill(depth, depth + N, -1); // -1로 초기화
	depth[0] = 0;

	// 트리 만들기 //u v -- 했으니
	makeTreeByDFS(0);

	// parent 배열 채움
	for (int j = 0; j<MAX - 1; j++)
		for (int i = 1; i<N; i++)
			if (parent[i][j] != -1)
				parent[i][j + 1] = parent[ parent[i][j] ][ j ];

	// 쿼리 입력받기
	scanf("%d", &M);
	for (int i = 0; i<M; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		u--; v--;

		// depth[u] >= depth[v]가 되도록 필요에 따라 u, v를 스왑
		if (depth[u] < depth[v]) swap(u, v);
		int diff = depth[u] - depth[v];

		// 깊이 차(diff)를 없애며 u를 이동시킴
		for (int j = 0; diff; j++) {
			if (diff % 2) u = parent[u][j];
			diff /= 2;
		}

		// u와 v가 다르면 동시에 일정 높이만큼 위로 이동시킴
		if (u != v) {
			// 높이 2^17, 2^16, ..., 2^2, 2, 1 순으로 시도
			for (int j = MAX - 1; j >= 0; j--) {
				if (parent[u][j] != -1 && parent[u][j] != parent[v][j]) {
					u = parent[u][j];
					v = parent[v][j];
				}
			}
			// 마지막엔 두 정점 u, v의 부모가 같으므로 한 번 더 올림
			u = parent[u][0];
		}

		// LCA 출력
		printf("%d\n", u + 1);
	}
}

