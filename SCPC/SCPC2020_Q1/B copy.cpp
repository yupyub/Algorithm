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
int sum1[3001];
int sum2[3001];
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
			sum1[i] = sum2[i] = 0;
			for(int j = 0;j<=N;j++)
				dp[i][j] =  0;
		}
		int idx1[3001];
		int idx2[3001];
		/// idx 계산
		for(int i = 0;i<=N;i++){
			for(int j = 0;j<=N;j++){
				if(sum1[i]-sum1[idx1[i]] < i-idx1[i])
					dp[i][j] = 1;
				else if( 1 )
					dp[i][j] = 1;
				///
				// 
				///
				if(i != 0)
					sum1[i] = sum1[i-1] + dp[i][j];
				else 
					sum1[i] = dp[i][j];
				if(j != 0)
					sum2[j] = sum2[j-1] + dp[i][j];
				else
					sum2[j] = dp[i][j];
			}
		}
		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << " " << (N+1)*(N+1) - Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}