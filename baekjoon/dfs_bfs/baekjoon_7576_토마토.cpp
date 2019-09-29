#include<iostream>
#include<queue>
using namespace std;
int N, M;
int time = 0;
int map[1001][1001];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
int visited[1001][1001]; // visited에 각 좌표의 price를 저장합니다. 즉, 0으로 초기화가 필요합니다.
queue<pair<int, int>>q; // map[y][x] = 1인 좌표를 저장하는 queue입니다.

void bfs() {
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && ny < N && nx >= 0 && nx < M) {
				if (!visited[ny][nx] && map[ny][nx] == 0) {
					visited[ny][nx] = visited[y][x] + 1;
					map[ny][nx] = 1;
					q.push(make_pair(ny, nx));
				}
			}
		}
	}
}

int main() {
	cin >> M >> N;
	int temp;
	// visited 행렬 0으로 초기화
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			visited[y][x] = 0;
	// map 행렬에 입력값 받고, 1인 경우 q에 넣기
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++) {
			cin >> temp;
			map[y][x] = temp;
			if (temp == 1)
				q.push(make_pair(y, x));
		}
	// bfs 탐색
	bfs();
	// 결과 출력을 위해, 최종 탐색 시간 확인 및 0인 경우 -1 출력하고 종료
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (map[y][x] == 0) {
				cout << "-1" << endl;
				return 0;
			}
			if (visited[y][x] > time)
				time = visited[y][x];
		}
	}
	cout << time << endl;
	return 0;
}