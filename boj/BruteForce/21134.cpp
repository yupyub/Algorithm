#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int dfs(int idx, int first_num, int pos[], int check[], int num_pair[][10]) {
	if (idx == 9) {
		int sum = 0;
		for (int i = 0; i < 9; i++) {
			for (int j = i+1; j < 9; j++) {
				sum += num_pair[pos[i]][pos[j]] * (j - i + 1);
				sum += num_pair[pos[j]][pos[i]] * (j - i + 1);
			}
			sum += num_pair[pos[i]][pos[i]];
			if (pos[i] == first_num)
				sum += i + 1;
		}
		return sum;
	}
	int ret = 987654321;
	for (int i = 1; i <= 9; i++) {
		if (check[i])
			continue;
		check[i] = 1;
		pos[idx] = i;
		ret = min(ret, dfs(idx + 1, first_num, pos, check, num_pair));
		check[i] = 0;
	}
	return ret;
}
int main() {
	char str[100001];
	scanf("%s", str);
	int num_pair[10][10] = { 0, };
	for (int i = 0; i < strlen(str)-1; i++)
		num_pair[str[i]-'0'][str[i + 1]-'0']++;
	int pos[10] = { 0, };
	int check[10] = { 0, };
	printf("%d",dfs(0, str[0] - '0', pos, check, num_pair));
}