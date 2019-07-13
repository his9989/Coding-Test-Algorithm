#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;

int map[100][100];
int N = 0, M = 0;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int visited[100][100];

void inputData() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int b;
			scanf_s("%1d", &b);
			map[i][j] = b;
		}
	}
}

int bfs() {
	int cy = 0, cx = 0;
	queue<pair<int, int>> q;
	q.push(pair<int, int>(cy, cx));
	visited[cy][cx] = 1;
	while (!q.empty()) {
		cy = q.front().first;
		cx = q.front().second;
		q.pop();
		if ((cy == N - 1) && (cx == M - 1)) break;
		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny >= 0 && ny < N && nx >= 0 && nx < M && visited[ny][nx] == 0 && map[ny][nx] == 1) {
				visited[ny][nx] = visited[cy][cx] + 1;
				q.push(pair<int, int>(ny, nx));
			}
		}
	}
	return visited[N - 1][M - 1];
}

int main() {
	cin >> N >> M;
	inputData();
	int answer = bfs();
	cout << answer << endl;
}