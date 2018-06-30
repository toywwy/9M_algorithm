/* 
���� : ������
���� ��ȣ: 2188
Ǯ�̹� : �̺� ��Ī(Bipartite Matching)
��¥ : 18.06.30
��Ÿ :
�ʹ� ������� ���ذ� �߾Ȱ���.
������ �ٽ� Ǯ�������.
*/



#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 200;

// N: A �׷� ũ��, M: B �׷� ũ��
// A[i], B[i]: �� ������ ��Ī�� �ݴ��� ���� ��ȣ
int N, M, A[MAX], B[MAX];
// adj[i]: A[i]�� ������ �׷� B�� ������
vector<int> adj[MAX];
bool visited[MAX];

// A�׷쿡 ���� ���� a�� �̺� ��Ī���Ѽ� �����ϸ� true
bool dfs(int a) {
	
	visited[a] = true;//visit�� üũ�ؾ��ϴ����� �̹� ��� �ڸ� ������ �ѹ� �� ��� �긦 �ǹٲٰ� �Ǹ�
	//��͸� ���鼭 ��� �ٲٰ� �� ���̴�.
	
	for (int b : adj[a]) { //����ؼ� �����͵� Ž���� �غ���. �������� true�� return �ϰԵǸ� �����°�.
		// �ݴ����� ��Ī���� �ʾҰų�
		// ��Ī�Ǿ� �־����� ���� ��Ī�Ǿ� �ִ� ������ �ٸ� ������ ��Ī��ų �� ������ ����
		if (B[b] == -1 || !visited[B[b]] && dfs(B[b])) {//����Ʈ ���� ��Ī�Ǿ� �ִ� ������ �ٸ� ������ ��Ī��ų�� ������ȴ�.
			A[a] = b; // ������ ��Ī��  ����..���ų� �ϴ°� ����.
			B[b] = a; // 
			return true;
		}
	}//b�� �ϴ� ����̴�.
	
	// ��Ī ����
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
			//�׳� i�� 0���� �޾Ƶ���������??
			//������ �Ҵ� 0���Ͱ��� ��縸 1���� �������� �ص� �����ϴ�.
		}
	}

	int match = 0;
	// �ʱⰪ: -1
	fill(A, A + N, -1);//�ּҰ� ��� from to ���� -1�� �ʱ�ȭ �Ѵ�.
	fill(B, B + M, -1);

	for (int i = 0; i<N; i++) {//�ᱹ�̷����ؼ� �Ǵ°� i ������ �ϳ��� ��Ī ��Ű�� ���� �Ŷ�°� ���ذ��Ȱ���.
		// ���� ��Ī���� ���� �׷� A ������ ���� ��Ī �õ�
		if (A[i] == -1) {
			// visited �迭 �ʱ�ȭ
			fill(visited, visited + N, false);
			if (dfs(i)) match++;
		}//���� ������� �÷ο�� ���ذ�����.
	}
	printf("%d\n", match);
}

