#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <string>
#include <tuple>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int INF = 987654321;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int arr[500001];
int temp[500001];
int _mergeSort(int left, int right); 
int merge(int left, int mid, int right); 
/* This function sorts the input array and returns the  
number of inversions in the array */
int mergeSort(int array_size) 
{ 
    return _mergeSort(0, array_size - 1); 
} 
  
/* An auxiliary recursive function that sorts the input array and  
returns the number of inversions in the array. */
int _mergeSort(int left, int right) 
{ 
    int mid, inv_count = 0; 
    if (right > left) { 
        /* Divide the array into two parts and  
        call _mergeSortAndCountInv()  
        for each of the parts */
        mid = (right + left) / 2; 
  
        /* Inversion count will be sum of  
        inversions in left-part, right-part  
        and number of inversions in merging */
        inv_count += _mergeSort(left, mid); 
        inv_count += _mergeSort(mid + 1, right); 
  
        /*Merge the two parts*/
        inv_count += merge(left, mid + 1, right); 
    } 
    return inv_count; 
} 
  
/* This funt merges two sorted arrays  
and returns inversion count in the arrays.*/
int merge(int left, 
          int mid, int right) 
{ 
    int i, j, k; 
    int inv_count = 0; 
  
    i = left; /* i is index for left subarray*/
    j = mid; /* j is index for right subarray*/
    k = left; /* k is index for resultant merged subarray*/
    while ((i <= mid - 1) && (j <= right)) { 
        if (arr[i] <= arr[j]) { 
            temp[k++] = arr[i++]; 
        } 
        else { 
            temp[k++] = arr[j++]; 
  
            /* this is tricky -- see above  
            explanation/diagram for merge()*/
            inv_count = inv_count + (mid - i); 
        } 
    } 
  
    /* Copy the remaining elements of left subarray  
(if there are any) to temp*/
    while (i <= mid - 1) 
        temp[k++] = arr[i++]; 
  
    /* Copy the remaining elements of right subarray  
(if there are any) to temp*/
    while (j <= right) 
        temp[k++] = arr[j++]; 
  
    /*Copy back the merged elements to original array*/
    for (i = left; i <= right; i++) 
        arr[i] = temp[i]; 
  
    return inv_count; 
} 
  
// Driver code 
int main() 
{ 
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i = 0;i<n;i++)
			scanf("%d",&arr[i]);
    	int ans = mergeSort(n); 
    	//printf("%d ",ans);
		if(ans >= ((n-1)*n)/2-1)
			printf("NO\n");
		else
			printf("YES\n");
	}
    return 0; 
} 
  