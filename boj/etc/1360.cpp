#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
vector<pair<int,string> >state;
int main(){
	int n,time,idx;
	string operation,str;
	cin >> n;
	while(n--){
		cin >> operation >> str >> time;
		if(operation.compare("type") == 0){
			if(state.empty())
				state.push_back(make_pair(time,str));
			else
				state.push_back(make_pair(time,state.back().second+str));
		}
		else{
			int t = time-stoi(str);
			idx = state.size()-1;
			for(int i = 0;i<=idx;i++)
				if(state[i].first>=t){
					idx = i;
					t = -1;
					break;
				}
			if(idx <= 0 && t == -1)
				state.push_back(make_pair(time,""));
			else if(t == -1)
				state.push_back(make_pair(time,state[idx-1].second));
			else if(!state.empty())
				state.push_back(make_pair(time,state.back().second));
			else
				state.push_back(make_pair(time,""));
		}
		
	}
	if(!state.empty())
		cout << state.back().second << endl;
	else
		cout << "" << endl;
}