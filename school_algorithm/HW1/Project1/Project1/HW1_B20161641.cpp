#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <algorithm>
#include <chrono>
#include <iostream>
#include <string.h>
#define MAX 2000
#define dataSize 4
#define MAXSIZE 10000000
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

typedef long long ll;
int arr[MAXSIZE];// = { 1,5,4,8,10,2,6,9,3,7, };
int buf[MAXSIZE];
int ReadFile(char fname[]) {
	FILE *fp_r;
	int data;
	int n;
	char filename[30];
	sprintf(filename, "./Data_B/%s", fname);
	fp_r = fopen(filename, "rb");

	fread(&n, dataSize, 1, fp_r);

	for (int i = 0; i < n; i++) {
		fread(&data, dataSize, 1, fp_r);
		arr[i] = data;
	}
	fclose(fp_r);
	return n;
}

void MakeRandomFile(int idx) {
	FILE *fp_w;
	ll data, ten;
	int idata;
	int n;

	//n = ((rand()*1024) % (1024*1024))+1;
	n = rand() + 1;
	printf("<<%d>>\n", n);
	char filename[30];
	sprintf(filename, "./Data_B/IC_%02d.input", idx);

	fp_w = fopen(filename, "wb");
	fwrite(&n, dataSize, 1, fp_w);

	for (int i = 0; i < n; i++) {
		data = 0;
		ten = 1;
		for (int j = 0; j < 10; j++) {
			data += (ll)((rand()) % 10) * ten * (rand() % 2);
			ten *= 10;
		}
		data %= 2147483647;
		if (rand() % 2)
			data *= -1;
		idata = (int)data;
		fwrite(&data, dataSize, 1, fp_w);
	}
	fclose(fp_w);
}

void LoopMakeFile(int n) {
	int idx = 1;
	while (n--) {
		MakeRandomFile(idx);
		idx++;
	}
}

void MakeOutputFile(char fname[], int n,int total) {
	FILE *fp;
	char filename[30];
	sprintf(filename, "./Data_B/%s", fname);
	fp = fopen(filename, "w");
	fprintf(fp, "%d\n%d\n", n,total);
	fclose(fp);
}

int merge(int L, int mid, int R) {
	int iL, iR,i;
	int ans = 0;
	memcpy(buf + L, arr + L, sizeof(int)*(R - L + 1));
	iL = L;
	iR = mid+1;
	i = L;
	while ((iL <= mid) && (iR <= R)) {
		if (buf[iL] > buf[iR]) {
			arr[i++] = buf[iR++];
			ans += mid - iL + 1;
		}
		else
			arr[i++] = buf[iL++];
	}
	while (iL <= mid)
		arr[i++] = buf[iL++];
	while (iR <= R) {
		arr[i++] = buf[iR++];
	}
	return ans;
}

int merge_inversion(int L,int R) {
	int mid,ans = 0;
	if (L < R) {
		mid = (L + R) / 2;
		ans += merge_inversion(L, mid);
		ans += merge_inversion(mid + 1, R);
		ans += merge(L, mid, R);
		return ans;
	}
	return ans;
}

int test(int n) {
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] > arr[j])
				ans++;
		}
	}
	return ans;
}

void Func(char filename1[], char filename2[]) {
	int tot;
	int n = ReadFile(filename1);
	tot = merge_inversion(0,n-1);
	MakeOutputFile(filename2, n, tot);
}



void ReadInstruction() {
	FILE *fp;
	int data;
	int n;
	char filename[30] = "./Data_B/HW1_IC_config.txt";
	fp = fopen(filename, "r");
	char str[30];
	int cnt = 0;
	char filename1[30], filename2[30];
	while (fscanf(fp, "%s", str) != EOF) {
		if (cnt == 0)
			strcpy(filename1, str);
		else if (cnt == 1)
			strcpy(filename2, str);
		if (cnt == 1)
			Func(filename1, filename2);
		cnt++;
		if (cnt > 1)
			cnt = 0;
	}
	fclose(fp);
}

int main() {
	srand(time(NULL));
	LoopMakeFile(10);				//Make Random Input File.
	ReadInstruction();

}