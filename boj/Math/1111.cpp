#include <cstdio>
int main() {
	int N;
	scanf("%d", &N);
	int num[50];
	for (int i = 0; i < N; i++)
		scanf("%d", &num[i]);
	if (N < 2) {
		printf("A\n");
		return 0;
	}
	int flag = 0;
	if (num[0] == num[1]) {
		for (int i = 2; i < N; i++) {
			if (num[i] != num[0])
				flag = 1;
		}
		if (flag == 0) 
			printf("%d\n", num[0]);
		else 
			printf("B\n");
		return 0;
	}
	if (N < 3) {
		printf("A\n");
		return 0;
	}
	if ((num[2] - num[1]) % (num[1] - num[0]) != 0) {
		printf("B\n");
		return 0;
	}
	int a = (num[2] - num[1]) / (num[1] - num[0]);
	int b = num[1] - a * num[0];
	for (int i = 3; i < N; i++) {
		if (num[i] != num[i - 1] * a + b) {
			printf("B\n");
			return 0;
		}
	}
	printf("%d\n", num[N - 1] * a + b);
	return 0;
}