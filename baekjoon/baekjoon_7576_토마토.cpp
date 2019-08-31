#include<iostream>
#include<queue>
using namespace std;
int N, M;
int time = 0;
int map[1001][1001];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
int visited[1001][1001]; // visited�� �� ��ǥ�� price�� �����մϴ�. ��, 0���� �ʱ�ȭ�� �ʿ��մϴ�.
queue<pair<int, int>>q; // map[y][x] = 1�� ��ǥ�� �����ϴ� queue�Դϴ�.

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
	// visited ��� 0���� �ʱ�ȭ
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			visited[y][x] = 0;
	// map ��Ŀ� �Է°� �ް�, 1�� ��� q�� �ֱ�
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++) {
			cin >> temp;
			map[y][x] = temp;
			if (temp == 1)
				q.push(make_pair(y, x));
		}
	// bfs Ž��
	bfs();
	// ��� ����� ����, ���� Ž�� �ð� Ȯ�� �� 0�� ��� -1 ����ϰ� ����
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