#include <stdio.h>

int main() {
	char a;
	for (int i = 0; ; i++) {
		a = getchar();
		if (a == '\n' || a == EOF)
			break;
		printf("%d\n", i);
	}
}