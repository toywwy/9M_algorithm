#include <cstdio>

int d[10000];
int n, m;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i<10; i++)
		d[i] = 0;

	d[0] = 1;
	for (int i = 1; i <= m; i++) {
		d[0] *= n - i + 1;
		for (int j = 1; j<10000; j++) {
			d[j] *= n - i + 1;
			d[j] += d[j - 1] / 100;
			d[j - 1] %= 100;
		}
		for (int j = 9999; j>0; j--) {
			d[j - 1] += 100 * (d[j] % i);
			d[j] /= i;
		}
		d[0] /= i;
	}

	int x;
	for (x = 9999; x >= 0; x--) {
		if (d[x] != 0)
			break;
	}
	printf("%d", d[x--]);
	for (; x >= 0; x--) {
		printf("%02d", d[x]);
	}

}