#include <cstdio>
#include <string>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main(){
	string S, T;
	cin >> S >> T;
	int ans = 0;
	while(T.length() != 0){
		if(!S.compare(T)){
			ans = 1;
			break;
		}
		if(*(T.end()-1) == 'B'){
			T.pop_back();
			reverse(T.begin(),T.end());
		}
		else
			T.pop_back();
	}
	cout << ans;
	return 0;
}
