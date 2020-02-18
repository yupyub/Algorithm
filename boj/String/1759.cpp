#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
vector<char> alp;
int ch[20];
vector<string> ans;
void f(int mo,int za,int len, string str,int idx){
	//cout << str << " " << idx << endl;
	if(str.length() == len && mo>=1 && za>=2){
		ans.push_back(str);
		return;
	}
	for(int i = idx;i<alp.size();i++){
		if(ch[i])
			f(mo+1,za,len,str+alp[i],i+1);
		else
			f(mo,za+1,len,str+alp[i],i+1);
	}
}
int main(){
	int n,m;
	char c;
	cin >> n >> m;
	for(int i = 0;i<m;i++){
		cin >> c;
		alp.push_back(c);
	}
	sort(alp.begin(),alp.end());
	for(int i = 0;i<m;i++){
		char c = alp[i];
		if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
			ch[i] = 1;
	}
	f(0,0,n,"",0);
	sort(ans.begin(),ans.end());
	for(string str : ans)
		cout << str << endl;
}
	
