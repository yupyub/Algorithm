#include <cstdio>
#include <stack>
using namespace std;
stack <char> s;
char arr[110];
int main(){
	while(1){
		scanf("%[^\n]",arr);
		getchar(); // scanf 에서 '\n' 전까지 입력 받음으로 버퍼에 남아있는 '\n'을 버린다.
		if(arr[0] == '.') break;
		while(!s.empty()) s.pop();
		int i = 0, ans = 1;
		while(arr[i] != '\0'){
			if(arr[i] == '['||arr[i] == '(')
				s.push(arr[i]);
			else if(arr[i] == ']'){
				if(!s.empty() && s.top() == '[') s.pop();
				else {
					ans = 0;
					break;
				}
			}
			else if(arr[i] == ')'){
				if(!s.empty() && s.top() == '(') s.pop();
				else{
					ans = 0;
					break;
				}
			}
			i++;
		}
		if(ans == 1 && s.empty()) printf("yes\n");
		else printf("no\n");
	}
}
	