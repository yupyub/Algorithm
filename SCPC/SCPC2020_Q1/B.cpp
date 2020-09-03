#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

int Answer;		

int N,K;
int arr1[3001];
int arr2[3001];
int dp[3001][3001];
int f(int n,int m){
	int &ret = dp[n][m];
	if(ret != -1)
		return ret;
	if(n == 0 && m == 0)
		return ret = 1;
	int sum = 0;
	for(int i = n;i>0;i--){
		sum += arr1[i];
		if(sum>K)
			break;
		if(!f(i-1,m))
			return ret = 1;
	}
	sum = 0;
	for(int i = m;i>0;i--){
		sum += arr2[i];
		if(sum>K)
			break;
		if(!f(n,i-1))
			return ret = 1;
	}
	return ret = 0;
}
int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int T, test_case;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////

		cin >> N >> K;
	    for(int i = 1;i<=N;i++)
			cin >> arr1[i];
		for(int i = 1;i<=N;i++)
			cin >> arr2[i];
		for(int i = 0;i<=N;i++){
			for(int j = 0;j<=N;j++)
				dp[i][j] = -1;
		}
		for(int i = 0;i<=N;i++){
			for(int j = 0;j<=N;j++){
				Answer += f(i,j);
			}
		}
		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << " " << (N+1)*(N+1) - Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}