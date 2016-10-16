/*
문제 : 텀프로젝트
문제 번호: 9466
풀이법 : DFS
날짜 : 161001
기타 : DFS
*/

#include <cstdio>
#include <algorithm>
using namespace std;

int N, S[100000], cnt; // cnt: 싸이클에 속하는 정점 개//수
bool visited[100000], finished[100000];

/*
이제 우리는 DFS를 하다가, 싸이클이 발생하는 조건을 찾아야 합니다.
그 조건은 바로... 다음에 방문할 정점이 k일 때, visited[k]=true고 finished[k]=false인 경우입니다.
이 말은 무엇이냐면 인접한 정점은 이미 방문은 시작했지만 그 정점의 DFS는 아직 끝나지 않았다...
*/

void dfs(int curr) {
	visited[curr] = true;

	int next = S[curr];

	if (visited[next]) {//방문한적이 있었고
		if (!finished[next]) {//그정점의 DFS는 아직끝나지 않았다.
			for (int temp = next; temp != curr; temp = S[temp]) 
				cnt++;
			cnt++; // 자기 자신
		}
	}
	else dfs(next);
	finished[curr] = true;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d", S + i);
			S[i]--;
		}

		// 각 컴포넌트에 대해 DFS 시작
		fill(visited, visited + N, false);
		fill(finished, finished + N, false);
		cnt = 0;
		for (int i = 0; i < N; i++)
			if (!visited[i]) dfs(i);

		printf("%d\n", N - cnt);
	}
}


/*
//이 풀이는 내 역량 밖의 풀이이다.
#include<stdio.h>
const int MAX_N = 1e5;
int t, n, check[MAX_N + 1], arr[MAX_N + 1], flag[MAX_N + 1];
//궁금하다 모르겠음
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int h, r = 0;
		
		for (int i = 1; i <= n; i++) check[i] = flag[i] = 0;
		
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", arr + i);
			check[arr[i]]++;
		}

		//간선이 없는 학생들을 계속 제거하자!

		//nxt에 입력받는게 들어가있다.

		for (int i = 1; i <= n; i++) {
			h = i;
			//둘다 1이 아니여야한다. 간선이 하나씩이라도 있으면 안됨
			//사이클이 발생할 조건은 무엇인가???
			
			while (!check[h] && !flag[h]) {// 방문한적이없고 간선이 1이 아니라면 res++
				flag[h] = 1;
				check[arr[h]]--;
				h = arr[h];//다음갈곳
				r++;
			}
		}
		//무슨 알고리즘 일까...
		printf("%d\n", r);
	}
	return 0;
}



*/