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
typedef long long ll;
using namespace std;

ll Answer;
ll A[200000];
ll B[200000];
int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int T, test_case;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 200000000000001;
		/////////////////////////////////////////////////////////////////////////////////////////////

	    int N;
		cin >> N;
		for(int i = 0;i<N;i++){
		    cin >> A[i];
		}
		for(int i = 0;i<N;i++){
		    cin >> B[i];
		}
		sort(A,A+N);
		sort(B,B+N);
		ll maxi = 0;
		ll ans = 0 ;
		for(int i = 0;i<N;i++){
			maxi = max(maxi,abs(A[i] - B[i]));
			ans += abs(A[i] - B[i]);
		}
		ans -= maxi;
		Answer = min(Answer,ans);
		ans = 0 ;
		for(int i = 1;i<N;i++){
			ans += abs(A[i-1] - B[i]);
		}
		// cout << ">> " << ans << endl;
		Answer = min(Answer,ans);
		ans = 0 ;
		for(int i = 0;i<N-1;i++){
			ans += abs(A[i+1] - B[i]);
		}
		// cout << ">> " << ans << endl;
		Answer = min(Answer,ans);
		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}