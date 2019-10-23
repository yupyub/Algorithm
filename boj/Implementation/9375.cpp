#include <cstdio>
#include <map>
#include <string>
#include <iostream>
using namespace std;

int main(){
	map<string,int> m;
	int T,n;
	string s1,s2;
	scanf("%d",&T);
	while(T--){
		m.clear();
		scanf("%d",&n);
		for(int i = 0;i<n;i++){
			cin >> s1 >> s2;
			if(m.find("s2") == m.end())
				m[s2]++;
			else m[s2] = 1; //m.insert(make_pair(s2,1));
		}
		int ans = 1;
		map<string,int>::iterator iter;
		for(iter = m.begin();iter != m.end();iter++)
			ans *= (*iter).second + 1;
		printf("%d\n",ans-1);
	}
}