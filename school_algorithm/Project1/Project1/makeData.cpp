#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>

#define MAX 2000
#define dataSize 4

using namespace std;

int main() {
	FILE *fp_w;
	int idx = 0;
	int data;

	srand(time(NULL));

	while (1) {
		int n;
		printf("��ǲ �������� ũ�� n(<=2^20)�� �Է��Ͻÿ�.(0������ ���� �Է½� ���α׷� ����): ");
		scanf("%d", &n);

		if (n <= 0) break;

		char filename[14];
		sprintf(filename, "MSS_%02d.input", idx++);

		fp_w = fopen(filename, "wb");
		fwrite(&n, dataSize, 1, fp_w);
		
		for (int i = 0; i < n; i++) {
			data = rand() % 2000;
			if (rand() % 2 == 0)
				data *= -1;
			fwrite(&data, dataSize, 1, fp_w);
		}

		fclose(fp_w);
	}

	return 0;
}