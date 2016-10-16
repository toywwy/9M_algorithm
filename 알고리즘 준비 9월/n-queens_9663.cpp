#include <iostream>
#include <cmath>
using namespace std;

int unsafe[16][16];
int N;
int cnt = 0;
int di[] = { 1, 1, 1 };
int dj[] = { -1, 0, 1 };

void dfs(int row) {
	for (int i = 1; i <= N; ++i) {
		if (unsafe[row][i])continue;

		for (int j = 0; j < 3; ++j) {
			int ni = row;
			int nj = i;
			while (true) {
				ni += di[j];
				nj += dj[j];
				if (ni <= N&&nj >= 1 && nj <= N) {
					unsafe[ni][nj]++;
				}
				else {
					break;
				}
			}
		}

		if (row == N) cnt++;
		else {
			dfs(row + 1);
		}
		//원래대로 백트랙킹
		for (int j = 0; j < 3; ++j) {
			int ni = row;
			int nj = i;
			while (true) {
				ni += di[j];
				nj += dj[j];
				if (ni <= N&&nj >= 1 && nj <= N) {
					unsafe[ni][nj]--;
				}
				else {
					break;
				}
			}
		}

	}
}

int main() {
	cin >> N;
	dfs(1);//row
	cout << cnt << endl;
	return 0;
}