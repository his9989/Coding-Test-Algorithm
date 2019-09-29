#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, M, V;
int map[1001][1001];
int visited[1001][1001];
int visited2[1001];
vector<int> ans;
queue<int> ans2;

void setZero() {
	for (int y = 1; y <= N; y++)
		for (int x = 1; x <= N; x++) {
			map[y][x] = 0;
		}
}

void refresh() {
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			visited[y][x] = 0;
		}
		visited2[y] = 0;
	}
	visited[V][V] = 1;
	ans.clear();
}

void dfs(int start) {
	ans.push_back(start);
	for (int x = 1; x <= N; x++) {
		if (map[start][x] == 1 && visited[start][x] == 0 && visited[x][x] == 0) {
			visited[start][x] = 1;
			visited[x][start] = 1;
			visited[x][x] = 1;
			dfs(x);
		}
	}
}

void bfs(int start) {
	ans2.push(start);
	visited2[start] = 1;
	while (!ans2.empty()) {
		int idx = ans2.front();
		ans2.pop();
		cout << idx << " ";
		for (int i = 1; i <= N; i++) {
			if (map[idx][i] && !visited2[i]) {
				visited2[i] = 1;
				ans2.push(i);
			}
		}
	}
}

int main() {
	cin >> N >> M >> V;
	setZero();
	for (int i = 0; i < M; i++) {
		int temp1, temp2;
		cin >> temp1 >> temp2;
		map[temp1][temp2] = 1;
		map[temp2][temp1] = 1;
	}
	refresh();
	dfs(V);
	int len = ans.size();
	for (int i = 0; i < len; i++)
		cout << ans[i] << " ";
	cout << endl;
	refresh();
	bfs(V);
}