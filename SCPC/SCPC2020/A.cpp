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
int arr1[200001];
int arr2[200001];
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

	    int N,K;
		cin >> N >> K;
		for(int i = 0;i<N;i++){
		    cin >> arr1[i];
		}
		for(int i = 0;i<N;i++){
		    cin >> arr2[i];
		}
		sort(arr1,arr1+N);
		sort(arr2,arr2+N);
		for(int i = 0;i<K;i++){
		    Answer = max(Answer,arr1[i]+arr2[K-1-i]);
		}
		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}