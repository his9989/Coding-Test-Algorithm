#include<iostream>
#include<queue>
using namespace std;

int M, N, H, time = 0;
int map[101][101][101];
int dz[6] = { 0, 0, 0, 0, 1, -1 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dx[6] = { 1, -1, 0, 0, 0, 0 };
int visited[101][101][101];
queue<pair<int, pair<int, int>>> q;

void bfs() {
	while (!q.empty()) {
		int z = q.front().first;
		int y = q.front().second.first;
		int x = q.front().second.second;
		q.pop();
		for (int i = 0; i < 6; i++) {
			int nz = z + dz[i];
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (nx >= 0 && nx < M && ny >= 0 && ny < N && nz >= 0 && nz < H) {
				if (!visited[nz][ny][nx] && map[nz][ny][nx] == 0) {
					visited[nz][ny][nx] = visited[z][y][x] + 1;
					map[nz][ny][nx] = 1;
					q.push(make_pair(nz, make_pair(ny, nx)));
				}
			}
		}
	}
}

int main() {
	int temp;
	cin >> M >> N >> H;
	for (int z = 0; z < H; z++)
		for (int y = 0; y < N; y++)
			for (int x = 0; x < M; x++) {
				cin >> temp;
				map[z][y][x] = temp;
				visited[z][y][x] = 0;
				if (temp == 1)
					q.push(make_pair(z, make_pair(y, x)));
			}
	bfs();
	for (int z = 0; z < H; z++)
		for (int y = 0; y < N; y++)
			for (int x = 0; x < M; x++) {
				if (map[z][y][x] == 0) {
					cout << "-1" << endl;
					return 0;
				}
				if (visited[z][y][x] > time)
					time = visited[z][y][x];
			}
	cout << time << endl;
	return 0;
}