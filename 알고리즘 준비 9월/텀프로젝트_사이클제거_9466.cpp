/*
���� : ��������Ʈ
���� ��ȣ: 9466
Ǯ�̹� : DFS
��¥ : 161001
��Ÿ : DFS
*/

#include <cstdio>
#include <algorithm>
using namespace std;

int N, S[100000], cnt; // cnt: ����Ŭ�� ���ϴ� ���� ��//��
bool visited[100000], finished[100000];

/*
���� �츮�� DFS�� �ϴٰ�, ����Ŭ�� �߻��ϴ� ������ ã�ƾ� �մϴ�.
�� ������ �ٷ�... ������ �湮�� ������ k�� ��, visited[k]=true�� finished[k]=false�� ����Դϴ�.
�� ���� �����̳ĸ� ������ ������ �̹� �湮�� ���������� �� ������ DFS�� ���� ������ �ʾҴ�...
*/

void dfs(int curr) {
	visited[curr] = true;

	int next = S[curr];

	if (visited[next]) {//�湮������ �־���
		if (!finished[next]) {//�������� DFS�� ���������� �ʾҴ�.
			for (int temp = next; temp != curr; temp = S[temp]) 
				cnt++;
			cnt++; // �ڱ� �ڽ�
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

		// �� ������Ʈ�� ���� DFS ����
		fill(visited, visited + N, false);
		fill(finished, finished + N, false);
		cnt = 0;
		for (int i = 0; i < N; i++)
			if (!visited[i]) dfs(i);

		printf("%d\n", N - cnt);
	}
}


/*
//�� Ǯ�̴� �� ���� ���� Ǯ���̴�.
#include<stdio.h>
const int MAX_N = 1e5;
int t, n, check[MAX_N + 1], arr[MAX_N + 1], flag[MAX_N + 1];
//�ñ��ϴ� �𸣰���
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

		//������ ���� �л����� ��� ��������!

		//nxt�� �Է¹޴°� ���ִ�.

		for (int i = 1; i <= n; i++) {
			h = i;
			//�Ѵ� 1�� �ƴϿ����Ѵ�. ������ �ϳ����̶� ������ �ȵ�
			//����Ŭ�� �߻��� ������ �����ΰ�???
			
			while (!check[h] && !flag[h]) {// �湮�����̾��� ������ 1�� �ƴ϶�� res++
				flag[h] = 1;
				check[arr[h]]--;
				h = arr[h];//��������
				r++;
			}
		}
		//���� �˰��� �ϱ�...
		printf("%d\n", r);
	}
	return 0;
}



*/