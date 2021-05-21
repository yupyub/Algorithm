#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
constexpr int INF = 987654321;
map<pair<vector<vector<int> >, vector<vector<int> > >, int> visit;
int isVisited(vector<vector<int> >& row, vector<vector<int> >& col) {
	auto temp = make_pair(row, col);
	if (visit[temp] == 0) {
		visit[temp] = 1;
		return 0;
	}
	return 1;
}
vector<vector<int> > fold(vector<vector<int> >& arr, int N, int M, int x, int y) {
	vector<vector<int> > temp;
	if (y == -1) {
		int retN = max(x + 1, N - x - 1);
		temp.resize(retN);
		for (int i = 0; i < retN; i++)
			for (int j = 0; j < M; j++)
				temp[i].push_back(0);
		for (int i = x + 1; i < N; i++) {
			for (int j = 0; j < M; j++)
				temp[i - x - 1][j] += arr[i][j];
		}
		for (int i = x; i >= 0; i--) {
			for (int j = 0; j < M; j++)
				temp[x - i][j] += arr[i][j];
		}
		return temp;
	}
	else {
		int retM = max(y + 1, M - y - 1);
		temp.resize(N);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < retM; j++)
				temp[i].push_back(0);
		for (int j = y + 1; j < M; j++) {
			for (int i = 0; i < N; i++)
				temp[i][j - y - 1] += arr[i][j];
		}
		for (int j = y; j >= 0; j--) {
			for (int i = 0; i < N; i++)
				temp[i][y - j] += arr[i][j];
		}
		return temp;
	}
}
vector<vector<int> > fold_row(vector<vector<int> >& row, int N, int M, int x, int y) {
	vector<vector<int> > temp_row;
	int retN = max(x + 1, N - x - 1);
	temp_row.resize(retN);
	for (int i = x + 1; i < N; i++) {
		for (int j : row[i])
			temp_row[i - x - 1].push_back(j);
	}
	for (int i = x; i >= 0; i--) {
		for (int j : row[i])
			temp_row[x - i].push_back(j);
	}
	for (auto i : temp_row)
		sort(i.begin(), i.end());
	return temp_row;
}
vector<vector<int> > fold_col(vector<vector<int> >& col, int N, int M, int x, int y) {
	vector<vector<int> > temp_col;
	int retM = max(y + 1, M - y - 1);
	temp_col.resize(retM);
	for (int j = y + 1; j < M; j++) {
		for (int i : col[j])
			temp_col[j - y - 1].push_back(i);
	}
	for (int j = y; j >= 0; j--) {
		for (int i : col[j])
			temp_col[y - j].push_back(i);
	}
	for (auto i : temp_col)
		sort(i.begin(), i.end());
	return temp_col;
}
int dfs(vector<vector<int> > arr, vector<vector<int> > row, vector<vector<int> > col, int N, int M) {
	//printf(">> %d %d\n", N, M);
	int ret = -INF;
	for (int i = 0; i < N - 1; i++) {
		auto row_temp = fold_row(row, N, M, i, -1);
		auto& col_temp = col;
		if (isVisited(row_temp, col_temp))
			continue;
		auto temp = fold(arr, N, M, i, -1);
		int cnt = 0;
		for (auto i : temp)
			for (int j : i) {
				if (j > 0)
					cnt++;
				ret = max(ret, j);
			}
		if (cnt < 2)
			continue;
		ret = max(ret, dfs(temp, row_temp, col_temp, temp.size(), temp[0].size()));
	}
	for (int i = 0; i < M - 1; i++) {
		auto& row_temp = row;
		auto col_temp = fold_col(col, N, M, -1, i);
		if (isVisited(row_temp, col_temp))
			continue;
		auto temp = fold(arr, N, M, -1, i);
		int cnt = 0;
		for (auto i : temp)
			for (int j : i) {
				if (j > 0)
					cnt++;
				ret = max(ret, j);
			}
		if (cnt < 2)
			continue;
		ret = max(ret, dfs(temp, row_temp, col_temp, temp.size(), temp[0].size()));
	}
	return ret;
}
int main() {
	vector<vector<int> > arr;
	int N, M;
	scanf("%d %d", &N, &M);
	arr.resize(N);
	int a;
	int ans = -INF;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			scanf("%d", &a);
			arr[i].push_back(a);
			ans = max(ans, a);
		}
	vector<vector<int> > row;
	vector<vector<int> > col;
	row.resize(N);
	col.resize(M);
	for (int i = 0; i < N; i++) {
		row[i].push_back(i);
	}
	for (int i = 0; i < M; i++) {
		col[i].push_back(i);
	}
	ans = max(ans, dfs(arr, row, col, N, M));
	printf("%d\n", ans);
	return 0;
}