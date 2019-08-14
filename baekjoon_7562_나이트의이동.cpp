#include<iostream>
#include<queue>
using namespace std;

int T, I;
int sy, sx, ey, ex;
int visited[301][301];
int dy[8] = { 1, 1, 2, 2, -1, -1, -2, -2 };
int dx[8] = { 2, -2, 1, -1, 2, -2, 1, -1 };
bool check = false;
queue<pair<int, int>> q;

void refresh() {
	for (int y = 0; y < I; y++)
		for (int x = 0; x < I; x++)
			visited[y][x] = 0;
	while (!q.empty())
		q.pop();
	check = false;
}

void bfs(int _sy, int _sx) {
	if (_sy == ey && _sx == ex) {
		check = true;
		return;
	}
	if (check)
		return;
	for (int i = 0; i < 8; i++) {
		int ny = _sy + dy[i];
		int nx = _sx + dx[i];
		if (ny >= 0 && ny < I && nx >= 0 && nx < I) {
			if (!visited[ny][nx] && !check) {
				visited[ny][nx] = visited[_sy][_sx] + 1;
				q.push(make_pair(ny, nx));
			}
		}
	}
	while (!q.empty()) {
		int _y = q.front().first;
		int _x = q.front().second;
		q.pop();
		bfs(_y, _x);
	}
	return;
}

void printQ() {
	for (int y = 0; y < I; y++) {
		for (int x = 0; x < I; x++)
			cout << visited[y][x] << " ";
		cout << endl;
	}
}

int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> I;
		cin >> sy >> sx;
		cin >> ey >> ex;
		refresh();
		bfs(sy, sx);
		printQ();
		cout << visited[ey][ex] << endl;
	}
}