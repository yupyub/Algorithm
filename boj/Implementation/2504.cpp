#include <stdio.h>
#include <stack>
using namespace std;
stack<int>s;
int tt;
int ttt;
char str[31];
int main() {
	scanf("%s", str);
	int i = 0;
	int ans = 0;
	int tmp = 0;
	while (str[i] != 0) {
		if (str[i] == '(') {
			s.push('(');
			tt++;
		}
		else if (str[i] == '[') {
			s.push('[');
			ttt++;
		}
		else if (str[i] == ')') {
			if (!s.empty() && s.top() == '(') {
				if (str[i - 1] == '(') {
					tmp = 1;
					for (int j = 0; j < tt; j++)
						tmp *= 2;
					for (int j = 0; j < ttt; j++)
						tmp *= 3;
					ans += tmp;
				}
				s.pop();
				tt--;
			}
			else {
				printf("0\n");
				return 0;
			}
		}
		else if (str[i] == ']') {
			if (!s.empty() && s.top() == '[') {
				if (str[i - 1] == '[') {
					tmp = 1;
					for (int j = 0; j < tt; j++)
						tmp *= 2;
					for (int j = 0; j < ttt; j++)
						tmp *= 3;
					ans += tmp;
				}
				s.pop();
				ttt--;
			}
			else {
				printf("0\n");
				return 0 ;
			}
		}
		i++;
	}
	if (s.empty())
		printf("%d\n", ans);
	else
		printf("0\n");
}