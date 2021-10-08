#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<long long> numbers;
void maker(long long num, int mini, int digit) {
	if (digit == 0) {
		numbers.push_back(num);
		return;
	}
	num *= 10;
	for (int i = mini-1; i >= 0; i--) 
		maker(num + i, i, digit - 1);
}
int main() {
	int N;
	scanf("%d", &N);
	for(int i = 1;i<=10;i++)
		maker(0, 10, i);
	sort(numbers.begin(), numbers.end());
	if (N > numbers.size())
		printf("-1");
	else
		printf("%lld", numbers[N-1]);
	return 0;
}