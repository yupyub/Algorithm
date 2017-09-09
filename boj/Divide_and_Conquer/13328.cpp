#include <stdio.h>
int MOD = 31991;
short int mat[5][50][50];
void mult_1(int d) {
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < d; j++) {
			mat[2][i][j] = 0;
			for (int k = 0; k < d; k++) {
				mat[2][i][j] += (mat[0][i][k] * mat[0][k][j])%MOD;
			}
		}
	}
	for (int i = 0; i < d; i++)
		for (int j = 0; j < d; j++)
			mat[0][i][j] = mat[2][i][j]%MOD;
}
void mult_2(int d) {
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < d; j++) {
			mat[2][i][j] = 0;
			for (int k = 0; k < d; k++) {
				mat[2][i][j] += (mat[0][i][k] * mat[1][k][j])%MOD;
			}
		}
	}
	for (int i = 0; i < d; i++)
		for (int j = 0; j < d; j++)
			mat[0][i][j] = mat[2][i][j]%MOD;
}
void mult_matrix(int d, int t) {
	if (t == 1)
		return;
	mult_matrix(d, t / 2);
	if (t % 2) {
		mult_1(d);
		mult_2(d);
	}
	else {
		mult_1(d);
	}
}
int main() {
	int d;
	int t;
	scanf("%d %d", &d, &t);
	for (int i = 0; i < d; i++) {
		mat[0][0][i] = 1;
		mat[1][0][i] = 1;
	}
	for (int i = 1; i < d; i++) {
		mat[0][i][i - 1] = 1;
		mat[1][i][i - 1] = 1;
	}
	mult_matrix(d, t);
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < d; j++) {
			mat[1][i][j] = 0;
		}
	}
	mat[1][0][0] = 1;
	mult_2(d);
	printf("%d\n", mat[0][0][0] % MOD);
}