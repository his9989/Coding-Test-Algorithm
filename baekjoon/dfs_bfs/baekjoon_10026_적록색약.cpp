#include<iostream>
using namespace std;

int N = 0;
int cnt = 0;
char map[101][101];
int visited[101][101];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void refresh() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			visited[y][x] = -1;
		}
	}
	cnt = 0;
}

void GtoR() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (map[y][x] == 'G')
				map[y][x] = 'R';
		}
	}
}

void dfs(int y, int x) {
	visited[y][x] = cnt;
	for (int i = 0; i < 4; i++) {
		if (y + dy[i] >= 0 && x + dx[i] >= 0) {
			if (map[y + dy[i]][x + dx[i]] == map[y][x] && visited[y+dy[i]][x+dx[i]] == -1) {
				visited[y + dy[i]][x + dx[i]] = cnt;
				dfs(y + dy[i], x + dx[i]);
			}
		}
	}
}

int main() {
	int RGB = 0, RB = 0;
	cin >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
		}
	}
	refresh();
	//R, G, B 영역 계산
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (visited[y][x] == -1) {
				dfs(y, x);
				cnt++;
			}
		}
	}
	RGB = cnt;
	GtoR();
	refresh();
	//R, B 영역 계산
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (visited[y][x] == -1) {
				dfs(y, x);
				cnt++;
			}
		}
	}
	RB = cnt;
	cout << RGB << " " << RB << endl;
}