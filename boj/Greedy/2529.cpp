#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
char arr[10];
int ch[10];
int n;
string maxi,mini="9999999999";
void f(int pos,string s){
	if(pos == n+1){
		if(maxi.compare(s) < 0) maxi = s;
		if(mini.compare(s) > 0) mini = s;
		return;
	}
	for(int i = 0;i<10;i++){
		if(ch[i]) continue;
		if(pos==0||(arr[pos-1]=='<'&&s[pos-1]<i+'0')||(arr[pos-1]=='>'&&s[pos-1]>i+'0')){
			ch[i] = 1;
			f(pos+1,s+to_string(i));
			ch[i] = 0;
		}
	}
}
int main(){
	cin>>n;
	for(int i = 0;i<n;i++)
		cin >> arr[i];
	f(0,"");
	cout<<maxi<<endl<<mini<<endl;
}