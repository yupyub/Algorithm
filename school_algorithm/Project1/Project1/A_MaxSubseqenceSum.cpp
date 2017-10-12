#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <algorithm>
#define MAX 2000
#define dataSize 4
#define MAXSIZE 10000000
#define INF 987654321987654321
using namespace std;

typedef long long ll;
int arr[MAXSIZE];

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
	int i, j;
	for (i = M; i >= L; i--) {
		LB += (ll)arr[i];
		if (LB > MaxLB) {
			MaxLB = LB;
			tmps = i;
		}
	}
	for (i = M + 1; i <= R; i++) {
		RB += (ll)arr[i];
		if (RB > MaxRB) {
			MaxRB = RB;
			tmpe = i;
		}
	}
	Maxi = max(max(MaxL, MaxR), MaxLB + MaxRB);
	if (Maxi == MaxL || Maxi == MaxR) 
		return Maxi;
	else if (Maxi == MaxLB + MaxRB) {
		*s = tmps;
		*e = tmpe;
		return Maxi;
	}
}
void MaxSubsequenceSum_2(int n, int* s, int* e, ll* sum) {		//Divide_Conquer : O(NlogN)
	*sum = MaxSubSum(0, n - 1, s, e, sum);
}
void MaxSubsequenceSum_3(int n, int* s, int* e, int* sum) {		//Dynamic Programming : O(N)
	int tmp = 0;
	int tmps;
	*s = 0;
	for (int i = 0; i < n; i++) {
		tmp += arr[i];
		if (tmp > (*sum)) {
			*sum = tmp;
			*e = i;
		}
		else if (tmp < 0) {
			tmp = 0;
			*s = i + 1;
		}
	}
}
int main() {
	FILE *fp_r;
	int idx = 0;
	int data;

	srand(time(NULL));

	//while (1) {
	int n;
	char *filename = "MSS_02.input";
	//sprintf(filename, "MSS_%02d.input", idx++);

	fp_r = fopen(filename, "rb");

	fread(&n, dataSize, 1, fp_r);
	printf("%d\n", n);

	for (int i = 0; i < n; i++) {
		fread(&data, dataSize, 1, fp_r);
		printf("%d ", data);
	}
	fclose(fp_r);
	//}

	return 0;
}