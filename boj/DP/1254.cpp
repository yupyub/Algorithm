#include <stdio.h>
#include <algorithm>
using namespace std;
char str[2001];
char str1[1001];
int arr[2001];
int main() {
	scanf("%s", str1);
	int i = 0;
	while (1) {
		if (str1[i] == 0) {
			str[2 * i - 1] == 0;
			break;
		}
		str[2 * i] = str1[i];
		str[2 * i + 1] = '\n';
		i++;
	}
	int p = 0, r = 0;
	for (int j = 0; j < 2*i-1; j++) {
		if (j <= r)
			arr[j] = min(arr[2 * p - j], r - j);
		else
			arr[j] = 0;
		while (j - arr[j] - 1 >= 0 && j + arr[j] + 1 < 2*i-1 && str[j - arr[j] - 1] == str[j + arr[j] + 1])
			arr[j]++;
		if (r < j + arr[j])
			r = j + arr[j], p = j;
	}
	/*
	for (int j = 0; j < 2 * i - 1; j++)
		printf("%c ", str[j]);
	printf("\n");
	for (int j = 0; j < 2 * i - 1; j++)
		printf("%d ", arr[j]);
	printf("\n");
	*/
	for (int j = 0; j < 2*i-1; j++) {
		//printf(">> %d %d\n", arr[j], 2*i - j-2);
		if (arr[j] == 2*i - j-2) {
			if (str[j] == '\n')
				printf("%d\n", i + (j+1) / 2 - arr[j] + arr[j]/2);
			else
				printf("%d\n", i + (j+1) / 2 - arr[j]/2);
			break;
		}
	}
}