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
int X[3001];
int Y[3001];
int dp[3001][3001];
int idxX[3001];
int idxY[3001];
int sumX[3001][3001];
int sumY[3001][3001];
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
			cin >> X[i];
		for(int i = 1;i<=N;i++)
			cin >> Y[i];
		/// idx 계산
		for(int i = 0;i<=N;i++){
			int tmp = i;
			int tot = 0;
			while(tmp>0){
				if(tot + X[tmp]>K){
					tmp++;
					break;
				}
				tot += X[tmp];
				tmp--;
			}
			idxX[i] = tmp;
			tmp = i;
			tot = 0;
			while(tmp>0){
				if(tot + Y[tmp]>K){
					tmp++;
					break;
				}
				tot += Y[tmp];
				tmp--;
			}
			idxY[i] = tmp;
		}
		/// DP 계산 + 누적합 사용 최적화
		dp[0][0] = sumX[0][0] = sumY[0][0] = 1;
		Answer = 1;
		for(int i = 0;i<=N;i++){
			for(int j = 0;j<=N;j++){
				if(i == 0 && j == 0)
					continue;
				dp[i][j] = 0;
				if(i>0){
					if(idxX[i-1] == 0 && sumX[i-1][j] < i)
						dp[i][j] = 1;
					else if(idxX[i-1]>0 && sumX[i-1][j] - sumX[idxX[i-1]-1][j] < i-idxX[i-1])
						dp[i][j] = 1;
				}
				if(j>0){ 
					if(idxY[j-1] == 0 && sumY[i][j-1] < j)
						dp[i][j] = 1;
					else if(idxY[j-1]>0 && sumY[i][j-1] - sumY[i][idxY[j-1]-1] < j-idxY[j-1])
						dp[i][j] = 1;
				}
				if(i>0) sumX[i][j] = sumX[i-1][j] + dp[i][j];
				else sumX[i][j] = dp[i][j];
				if(j>0) sumY[i][j] = sumY[i][j-1] + dp[i][j];
				else sumY[i][j] = dp[i][j];
				Answer += dp[i][j];
			}
		}
		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << " " << (N+1)*(N+1) - Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}