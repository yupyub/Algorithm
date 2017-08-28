#include <stdio.h>
#include <string.h>
int arr[10001];
int s = 0,e = 0;
int size = 0;
void push_front(int n) {
	size++;
	if (s == 0)
		s = 10000;
	else
		s--;
	arr[s] = n;
}
void push_back(int n) {
	size++;
	arr[e] = n;
	if (e == 10000)
		e = 0;
	else
		e++;
}
void pop_front() {
	if (size == 0) {
		printf("-1\n");
		return;
	}
	size--;
	printf("%d\n", arr[s]);
	if (s == 10000)
		s = 0;
	else
		s++;
}
void pop_back() {
	if (size == 0) {
		printf("-1\n");
		return;
	}
	size--;
	if (e == 0)
		e = 10000;
	else
		e--;
	printf("%d\n", arr[e]);
}
void fsize() {
	printf("%d\n", size);
}
void empty() {
	if (!size)
		printf("1\n");
	else
		printf("0\n");
}
void front() {
	if (!size) {
		printf("-1\n");
		return;
	}
	printf("%d\n", arr[s]);
}
void back() {
	if (!size) {
		printf("-1\n");
		return;
	}
	if (e == 0)
		printf("%d\n", arr[10000]);
	else
		printf("%d\n", arr[e-1]);
}
int main() {
	int n,a;
	char str[13];
	scanf("%d", &n);
	while (n--) {
		scanf("%s", str);
		if (!strcmp(str, "push_back")) {
			scanf("%d", &a);
			push_back(a);
		}
		else if (!strcmp(str, "push_front")) {
			scanf("%d", &a);
			push_front(a);
		}
		else if (!strcmp(str, "size")) {
			fsize();
		}
		else if (!strcmp(str, "empty")) {
			empty();
		}
		else if (!strcmp(str, "pop_back"))
			pop_back();
		else if (!strcmp(str, "pop_front"))
			pop_front();
		else if (!strcmp(str, "front"))
			front();
		else
			back();
	}
}