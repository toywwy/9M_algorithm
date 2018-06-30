/* 
문제 : 축사배정
문제 번호: 2188
풀이법 : 이분 매칭(Bipartite Matching)
날짜 : 18.06.30
기타 :
너무 어려워서 이해가 잘안간다.
다음에 다시 풀어봐야함.
*/



#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 200;

// N: A 그룹 크기, M: B 그룹 크기
// A[i], B[i]: 각 정점이 매칭된 반대편 정점 번호
int N, M, A[MAX], B[MAX];
// adj[i]: A[i]와 인접한 그룹 B의 정점들
vector<int> adj[MAX];
bool visited[MAX];

// A그룹에 속한 정점 a를 이분 매칭시켜서 성공하면 true
bool dfs(int a) {
	
	visited[a] = true;//visit를 체크해야하는이유 이미 얘는 자리 변경이 한번 된 얘다 얘를 또바꾸게 되면
	//재귀를 돌면서 계속 바꾸게 될 것이다.
	
	for (int b : adj[a]) { //계쏙해서 다음것도 탐색을 해본다. 마지막에 true를 return 하게되면 끝나는것.
		// 반대편이 매칭되지 않았거나
		// 매칭되어 있었지만 원래 매칭되어 있던 정점을 다른 정점과 매칭시킬 수 있으면 성공
		if (B[b] == -1 || !visited[B[b]] && dfs(B[b])) {//포인트 원래 매칭되어 있던 정점을 다른 정점과 매칭시킬수 있으면된다.
			A[a] = b; // 무조건 매칭만  하지..뺴거나 하는건 없다.
			B[b] = a; // 
			return true;
		}
	}//b는 일단 축사이다.
	
	// 매칭 실패
	return false;
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i<N; i++) {
		int S;
		scanf("%d", &S);
		for (int j = 0; j<S; j++) {
			int k;
			scanf("%d", &k);
			adj[i].push_back(k - 1);
			//그냥 i를 0으로 받아도문제없나??
			//어차피 소는 0부터가고 축사만 1부터 시작으로 해도 무관하다.
		}
	}

	int match = 0;
	// 초기값: -1
	fill(A, A + N, -1);//주소값 넗어서 from to 까지 -1로 초기화 한다.
	fill(B, B + M, -1);

	for (int i = 0; i<N; i++) {//결국이렇게해서 되는게 i 번쨰꺼 하나를 매칭 시키기 위한 거라는게 이해가안간다.
		// 아직 매칭되지 않은 그룹 A 정점에 대해 매칭 시도
		if (A[i] == -1) {
			// visited 배열 초기화
			fill(visited, visited + N, false);
			if (dfs(i)) match++;
		}//이제 어느정도 플로우는 이해가갔다.
	}
	printf("%d\n", match);
}

