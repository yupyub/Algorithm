#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
vector<pair<int,string> >state;
int main(){
	int n,time,idx,t;
	string operation,str,tmp;
	cin >> n;
	while(n--){
		cin >> operation >> str >> time;
		tmp = (state.empty() ? "" : state.back().second);
		if(operation.compare("type") == 0)
			state.push_back(make_pair(time,tmp+str));
		else{
			t = time-stoi(str);
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
			else 
				state.push_back(make_pair(time,tmp));
		}
	}
	if(!state.empty())
		cout << state.back().second << endl;
	else
		cout << "" << endl;
}