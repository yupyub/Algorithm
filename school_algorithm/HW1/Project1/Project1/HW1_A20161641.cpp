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
int arr[MAXSIZE];

int ReadFile(char fname[]) {
	FILE *fp_r;
	int data;
	int n;
	char filename[30];
	sprintf(filename, "./Data_A/%s", fname);
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
	ll data,ten;
	int idata;
	int n;

	//n = ((rand()*1024) % (1024*1024))+1;
	n = idx;
	char filename[30];
	sprintf(filename, "./Data_A/MSS_%02d.input", idx);
	//sprintf(filename, "MSS_%02d.input", idx);

	fp_w = fopen(filename, "wb");
	fwrite(&n, dataSize, 1, fp_w);

	for (int i = 0; i < n; i++) {
		data = 0;
		ten = 1;
		for (int j = 0; j < 10; j++) {
			data += (ll)((rand())%10) * ten * (rand() % 2);
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
	int idx = 10;
	while (n--) {
		MakeRandomFile(idx);
		idx*=10;
	}
}

void MakeOutputFile(char fname[],int n,int t,ll sum, int s,int e, chrono::duration<double, milli> mili) {
	FILE *fp;
	char filename[30];
	//sprintf(filename, "./Data_A/MSS_%02d.output.txt", idx);
	//sprintf(filename, "MSS_%02d.input", idx);
	sprintf(filename, "./Data_A/%s", fname);
	fp = fopen(filename, "w");
	fprintf(fp, "%d\n%d\n%lld\n%d %d\n%.4lf", n, t, sum, s, e, mili);
	fclose(fp);
}

void MaxSubsequenceSum_1(int n, int* s, int* e, ll* sum) {		//O(N^2)
	ll tmp;
	for (int i = 0; i < n; i++) {
		tmp = 0;
		for (int j = i; j < n; j++) {
			tmp += (ll)arr[j];
			if (*sum < tmp) {
				*sum = tmp;
				*s = i;
				*e = j;
			}
		}
	}
}
ll MaxSubSum(int L, int R, int* s, int* e, ll* sum) {
	ll MaxL, MaxR;
	ll MaxLB = 0, MaxRB = 0;
	ll LB = 0, RB = 0;
	ll Maxi;
	int M, tmps, tmpe;
	if (L == R) {
		if (arr[L]>0) {
			if (*sum < (ll)(arr[L])) {
				*sum = (ll)arr[L];
				*s = *e = L;
			}
			return (ll)arr[L];
		}
		else return 0;
	}
	M = (L + R) / 2;
	MaxL = MaxSubSum(L, M, s, e, sum);
	MaxR = MaxSubSum(M + 1, R, s, e, sum);
	tmps = tmpe = M;
	for (int i = M; i >= L; i--) {
		LB += (ll)arr[i];
		if (LB > MaxLB) {
			MaxLB = LB;
			tmps = i;
		}
	}
	for (int i = M + 1; i <= R; i++) {
		RB += (ll)arr[i];
		if (RB > MaxRB) {
			MaxRB = RB;
			tmpe = i;
		}
	}
	Maxi = max(max(MaxL, MaxR), MaxLB + MaxRB);
	if (Maxi > (*sum)) {
		if (Maxi == MaxL || Maxi == MaxR) {
			*sum = Maxi;
		}
		else if (Maxi == MaxLB + MaxRB) {
			*s = tmps;
			*e = tmpe;
			*sum = Maxi;
		}
	}
	return Maxi;

}
void MaxSubsequenceSum_2(int n, int* s, int* e, ll* sum) {		//Divide_Conquer : O(NlogN)
	*sum = MaxSubSum(0, n - 1, s, e, sum);
}
void MaxSubsequenceSum_3(int n, int* s, int* e, ll* sum) {		//Dynamic Programming : O(N)
	ll tmp = 0;
	int tmps = 0;
	for (int i = 0; i < n; i++) {
		tmp += (ll)arr[i];
		if (tmp > (*sum)) {
			*sum = tmp;
			*s = tmps;
			*e = i;
		}
		else if (tmp < 0) {
			tmp = 0;
			tmps = i + 1;
		}
	}
}

void Func1(int t, int n, int* s, int *e, ll* sum) {
	*s = 0, *e = 0;
	*sum = 0;
	if (n <= 0) {
		(*s) = (*e) = -1;
		return;
	}
	switch (t) {
	case 1: MaxSubsequenceSum_1(n, s, e, sum);
		break;
	case 2: MaxSubsequenceSum_2(n, s, e, sum);
		break;
	case 3: MaxSubsequenceSum_3(n, s, e, sum);
		break;
	}
	if ((*sum) == 0)
		(*s) = (*e) = -1;
}

void Func2(char filename1[], char filename2[],int t) {
	int s, e;
	ll sum;
	int n = ReadFile(filename1);
	//time start
	chrono::system_clock::time_point st = chrono::system_clock::now();
	Func1(t, n, &s, &e, &sum);
	chrono::system_clock::time_point en = chrono::system_clock::now();
	//time end
	chrono::duration<double, milli> mili = chrono::duration_cast<chrono::duration<double, milli>>(en - st);

	MakeOutputFile(filename2, n, t, sum, s, e, mili);
}

void Func3(int n) {
	LoopMakeFile(n);
	int s, e;
	ll sum;
	int num = 10;
	FILE *fp = fopen("out.txt", "w");
	for (int i = 1; i <= n; i++, num *= 10) {
		printf("======================\n");
		for (int j = 1; j <= 3; j++) {
			chrono::system_clock::time_point st = chrono::system_clock::now();
			Func1(1, num, &s, &e, &sum);
			chrono::system_clock::time_point en = chrono::system_clock::now();
			chrono::duration<double, milli> mili = chrono::duration_cast<chrono::duration<double, milli>>(en - st);
			fprintf(fp, "%lf\n", mili);
		}
	}
	fclose(fp);
}
void ReadInstruction() {
	FILE *fp;
	int data;
	int n;
	char filename[30] = "./Data_A/HW1_MSS_config.txt";
	fp = fopen(filename, "r");
	char str[30];
	int cnt = 0,tt;
	char filename1[30], filename2[30];
	while (fscanf(fp, "%s", str) != EOF) {
		if (cnt == 0)
			strcpy(filename1, str);
		else if (cnt == 1)
			strcpy(filename2, str);
		else
			tt = str[1]-'0';
		if (cnt == 2)
			Func2(filename1, filename2, tt);
		cnt++;
		if (cnt > 2)
			cnt = 0;
	}
	fclose(fp);
}
int main() {
	srand(time(NULL));
	LoopMakeFile(7);				//Make Random Input File. 
	//ReadInstruction();
	Func3(5);
}